
# 🚨 **Emergency Management System (C Project)**

## 📄 **Abstract**
The **Emergency Management System** is a terminal-based application written in **C**, designed to manage and coordinate emergency response records efficiently.  
It allows users to add new emergency cases, search by case ID, update details, and delete records.  
All data is saved persistently in a **binary file (emergency.dat)**, ensuring information remains available across multiple program sessions.

This project demonstrates core C programming concepts such as **file handling, structures, arrays, and menu-driven programming**, making it ideal for beginners and small-scale emergency response setups.

---

## 🚑 **Features of the Program**

### ✔ Add New Emergency Records:
- Emergency Case ID  
- Victim / Caller Name  
- Emergency Type (Medical / Fire / Accident / Crime / Disaster)  
- Location of Incident  
- Response Unit Assigned  
- Status (Pending / In Progress / Resolved)  
- Contact Number  

### ✔ Other Features:
- View all emergency records (table format)
- Search emergency case by ID
- Update emergency details (location, status, response unit)
- Delete emergency records
- Persistent binary storage (`emergency.dat`)
- Automatically creates file if missing
- Terminal-based (CLI)
- Clean and beginner-friendly code structure
- Basic validation for invalid inputs

---

## 🖥 **Technical Requirements**

### **1. System Requirements**
- OS: Windows / Linux / macOS  
- Terminal / Command-line  
- Minimum RAM: 4 MB  
- Minimal disk space (for `emergency.dat`)  

### **2. Software Requirements**
- C Compiler: GCC / Clang / MinGW / MSVC  
- Any IDE or editor:
  - VS Code  
  - Code::Blocks  
  - Dev-C++  
  - Vim / Nano  
- Optional: Make tool  

### **3. Programming Requirements**
- Language: C  
- C Standards: **C89 / C99 / C11**  
- Required Libraries:
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
```

---

## 🗂 **File Handling Requirements**

- Read/write access to project folder  
- Records stored in binary file: `emergency.dat`  
- Auto-creates file if not found  

---

## ⚙️ **Compilation Requirements**

Recommended compilation:

```bash
gcc emergency.c -o emergency -Wall
```

---

## ✅ **Functional Requirements**

### **1. User Interface**
- Fully terminal-based
- Clear and simple menu layout
- User input validation

### **2. Emergency Record Operations**

#### 🚨 Add Emergency
Stores new emergency details.

#### 🔍 Search Emergency
Search by **Emergency Case ID**.

#### 📋 View All Emergencies
Displays all stored emergency records.

#### ✏ Update Emergency
Modify:
- Location
- Status
- Response Unit

#### ❌ Delete Emergency
Removes an emergency record after confirmation.

---

## 🔁 **Program Flow**

- Menu-driven loop system  
- Continues until user selects **Exit**  
- Smooth navigation with status messages  

---

## ▶ **How to Run the Program**

### 1. Compile

#### Linux / macOS:
```bash
gcc emergency.c -o emergency
```

#### Windows (MinGW):
```bash
gcc emergency.c -o emergency.exe
```

### 2. Run

#### Linux / macOS:
```bash
./emergency
```

#### Windows:
```bash
emergency.exe
```

### 3. Data File
- `emergency.dat` is auto-created  
- Stores all emergency records permanently  

---

## 🖼 **Screenshots**

*(Replace with your own program screenshots)*

1️⃣ Main Menu 
<img width="358" height="234" alt="Screenshot 2025-11-27 204034" src="https://github.com/user-attachments/assets/34ae1c00-861e-4bcb-9d51-56f1c5188008" />




2️⃣ Add Emergency 
<img width="876" height="477" alt="Screenshot 2025-11-25 210632" src="https://github.com/user-attachments/assets/fd3020b2-2b7a-43f5-9b71-c80e75a9bb5a" />



3️⃣ View Emergencies
<img width="1430" height="381" alt="Screenshot 2025-11-25 210656" src="https://github.com/user-attachments/assets/8f34c1b6-88c6-47fd-aeae-c3210d85b154" />


4️⃣ Search Emergency 
<img width="1121" height="513" alt="Screenshot 2025-11-25 210713" src="https://github.com/user-attachments/assets/1d80b810-d0e2-464b-abc2-eb13bb271b1b" />


5️⃣ Update Emergency 
<img width="501" height="327" alt="Screenshot 2025-11-25 210911" src="https://github.com/user-attachments/assets/260a2b34-0df6-47c7-8361-51b7b07020ba" />




6️⃣ Delete Emergency 
<img width="579" height="309" alt="Screenshot 2025-11-25 210921" src="https://github.com/user-attachments/assets/431eb231-2422-48d5-912e-fef4c297f55c" />







7️⃣ Exit 
<img width="431" height="282" alt="Screenshot 2025-11-25 210941" src="https://github.com/user-attachments/assets/688d00d4-9099-4de5-959e-04bb3bee8b3e" />


---

## 📌 Project Summary

The **Emergency Management System** simplifies the tracking and handling of emergency cases by providing a secure, structured, and persistent record management solution.  
It is well-suited for academic projects, demonstrations, and small-scale control systems.

---

### 👨‍💻 Developed Using:
- Language: C  
- Compiler: GCC  
- File System: Binary Storage  

---

✅ Ready for:
- GitHub upload  
- College project submission  
- Documentation use 

---

🎯 **End of README**
