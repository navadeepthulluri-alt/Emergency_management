#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILE_NAME "emergency.dat"
#define MAX_NAME     100
#define MAX_TYPE     50
#define MAX_LOC      100
#define MAX_SEV      20
#define MAX_STATUS   20
#define MAX_CONTACT  30
#define MAX_GENDER   10

typedef struct {
    int case_id;
    char patient[MAX_NAME];
    int age;
    char gender[MAX_GENDER];
    char type[MAX_TYPE];
    char location[MAX_LOC];
    char severity[MAX_SEV];   // e.g., Low / Medium / Critical
    char status[MAX_STATUS];   // e.g., Pending / In Progress / Resolved
    char contact[MAX_CONTACT];
    char created_at[30];      // human-readable timestamp
} Emergency;

/* function declarations */
void menu();
void addCase();
void viewCases();
void searchCase();
void updateCase();
void deleteCase();
int idExists(int id);
void get_timestamp(char *buf, size_t n);

/* helpers */
static void trim_newline(char *s) {
    s[strcspn(s, "\n")] = '\0';
}

int main(void) {
    menu();
    return 0;
}

void menu() {
    int choice;
    do {
        printf("\n========================================\n");
        printf("      EMERGENCY MANAGEMENT SYSTEM\n");
        printf("========================================\n");
        printf("1. Add Emergency Case\n");
        printf("2. View All Emergency Cases\n");
        printf("3. Search Emergency Case\n");
        printf("4. Update Emergency Case\n");
        printf("5. Delete Emergency Case\n");
        printf("6. Exit\n");
        printf("----------------------------------------\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // clear bad input
            choice = 0;
        }
        getchar(); // consume newline

        switch (choice) {
            case 1: addCase(); break;
            case 2: viewCases(); break;
            case 3: searchCase(); break;
            case 4: updateCase(); break;
            case 5: deleteCase(); break;
            case 6: printf("Exiting... Stay safe!\n"); break;
            default: printf("Invalid choice — try again.\n");
        }
    } while (choice != 6);
}

/* Add a new emergency case (append to file) */
void addCase() {
    Emergency e;
    FILE *fp;

    printf("\n--- Add Emergency Case ---\n");
    printf("Case ID (integer): ");
    if (scanf("%d", &e.case_id) != 1) {
        printf("Invalid ID input.\n");
        while (getchar() != '\n');
        return;
    }
    getchar(); // consume newline

    if (idExists(e.case_id)) {
        printf("Error: Case ID %d already exists.\n", e.case_id);
        return;
    }

    printf("Patient Name: ");
    fgets(e.patient, sizeof(e.patient), stdin); trim_newline(e.patient);

    printf("Age: ");
    if (scanf("%d", &e.age) != 1) {
        printf("Invalid age input.\n");
        while (getchar() != '\n');
        return;
    }
    getchar();

    printf("Gender: ");
    fgets(e.gender, sizeof(e.gender), stdin); trim_newline(e.gender);

    printf("Emergency Type (e.g., Accident, Cardiac): ");
    fgets(e.type, sizeof(e.type), stdin); trim_newline(e.type);

    printf("Location: ");
    fgets(e.location, sizeof(e.location), stdin); trim_newline(e.location);

    printf("Severity (Low / Medium / Critical): ");
    fgets(e.severity, sizeof(e.severity), stdin); trim_newline(e.severity);

    printf("Status (Pending / In Progress / Resolved): ");
    fgets(e.status, sizeof(e.status), stdin); trim_newline(e.status);

    printf("Contact Number: ");
    fgets(e.contact, sizeof(e.contact), stdin); trim_newline(e.contact);

    get_timestamp(e.created_at, sizeof(e.created_at));

    fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        perror("Unable to open data file for writing");
        return;
    }
    fwrite(&e, sizeof(Emergency), 1, fp);
    fclose(fp);

    printf("Emergency case %d added successfully.\n", e.case_id);
}

/* View all emergency records */
void viewCases() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No records found (file not present or empty).\n");
        return;
    }
    Emergency e;
    printf("\n--- All Emergency Cases ---\n");
    printf("%-6s %-20s %-3s %-8s %-12s %-18s %-9s %-12s %-16s\n",
           "ID", "Patient", "Age", "Gender", "Type", "Location", "Severity", "Status", "Contact");
    printf("---------------------------------------------------------------------------------------------\n");
    while (fread(&e, sizeof(Emergency), 1, fp) == 1) {
        printf("%-6d %-20s %-3d %-8s %-12s %-18s %-9s %-12s %-16s\n",
               e.case_id, e.patient, e.age, e.gender, e.type, e.location, e.severity, e.status, e.contact);
    }
    fclose(fp);
}

/* Search for a case by ID */
void searchCase() {
    int id;
    printf("\nEnter Case ID to search: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return;
    }
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }
    Emergency e;
    int found = 0;
    while (fread(&e, sizeof(Emergency), 1, fp) == 1) {
        if (e.case_id == id) {
            found = 1;
            printf("\n--- Case Found ---\n");
            printf("Case ID    : %d\n", e.case_id);
            printf("Patient     : %s\n", e.patient);
            printf("Age         : %d\n", e.age);
            printf("Gender      : %s\n", e.gender);
            printf("Type        : %s\n", e.type);
            printf("Location    : %s\n", e.location);
            printf("Severity    : %s\n", e.severity);
            printf("Status      : %s\n", e.status);
            printf("Contact     : %s\n", e.contact);
            printf("Created At  : %s\n", e.created_at);
            break;
        }
    }
    if (!found) printf("No case with ID %d found.\n", id);
    fclose(fp);
}

/* Update location, severity, status, contact for a case */
void updateCase() {
    int id;
    printf("\nEnter Case ID to update: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return;
    }
    getchar();

    FILE *fp = fopen(FILE_NAME, "rb+");
    if (!fp) {
        printf("No records found.\n");
        return;
    }
    Emergency e;
    int found = 0;
    while (fread(&e, sizeof(Emergency), 1, fp) == 1) {
        if (e.case_id == id) {
            found = 1;
            printf("Current Location: %s\n", e.location);
            printf("Enter new Location (leave blank to keep): ");
            char buf[MAX_LOC];
            fgets(buf, sizeof(buf), stdin); trim_newline(buf);
            if (strlen(buf) > 0) strncpy(e.location, buf, sizeof(e.location));

            printf("Current Severity: %s\n", e.severity);
            printf("Enter new Severity (leave blank to keep): ");
            fgets(buf, sizeof(buf), stdin); trim_newline(buf);
            if (strlen(buf) > 0) strncpy(e.severity, buf, sizeof(e.severity));

            printf("Current Status: %s\n", e.status);
            printf("Enter new Status (leave blank to keep): ");
            fgets(buf, sizeof(buf), stdin); trim_newline(buf);
            if (strlen(buf) > 0) strncpy(e.status, buf, sizeof(e.status));

            printf("Current Contact: %s\n", e.contact);
            printf("Enter new Contact (leave blank to keep): ");
            fgets(buf, sizeof(buf), stdin); trim_newline(buf);
            if (strlen(buf) > 0) strncpy(e.contact, buf, sizeof(e.contact));

            /* move file position back and overwrite */
            fseek(fp, - (long)sizeof(Emergency), SEEK_CUR);
            fwrite(&e, sizeof(Emergency), 1, fp);
            fflush(fp);

            printf("Case %d updated successfully.\n", id);
            break;
        }
    }
    if (!found) printf("No case with ID %d found.\n", id);
    fclose(fp);
}

/* Delete a case by rewriting file excluding that record */
void deleteCase() {
    int id;
    printf("\nEnter Case ID to delete: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return;
    }
    getchar();

    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }
    FILE *tmp = fopen("temp_emergency.dat", "wb");
    if (!tmp) {
        perror("Unable to create temporary file");
        fclose(fp);
        return;
    }

    Emergency e;
    int found = 0;
    while (fread(&e, sizeof(Emergency), 1, fp) == 1) {
        if (e.case_id == id) {
            found = 1;
            printf("Found case %d: %s\n", e.case_id, e.patient);
            printf("Are you sure you want to delete this record? (y/n): ");
            int c = getchar();
            while (getchar() != '\n'); // clear rest
            if (c == 'y' || c == 'Y') {
                printf("Deleting case %d.\n", id);
                /* skip writing to temp file -> effectively deletes */
            } else {
                /* keep it */
                fwrite(&e, sizeof(Emergency), 1, tmp);
                printf("Deletion cancelled.\n");
            }
        } else {
            fwrite(&e, sizeof(Emergency), 1, tmp);
        }
    }

    fclose(fp);
    fclose(tmp);

    /* replace original file */
    remove(FILE_NAME);
    rename("temp_emergency.dat", FILE_NAME);

    if (!found) printf("No case with ID %d found.\n", id);
}

/* Check if a case id already exists */
int idExists(int id) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return 0;
    Emergency e;
    while (fread(&e, sizeof(Emergency), 1, fp) == 1) {
        if (e.case_id == id) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

/* Fill timestamp in human-readable format */
void get_timestamp(char *buf, size_t n) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    if (tm) {
        strftime(buf, n, "%Y-%m-%d %H:%M:%S", tm);
    } else {
        strncpy(buf, "unknown", n);
    }
}
