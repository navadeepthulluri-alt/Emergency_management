
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
2️⃣ Add Emergency  
3️⃣ View Emergencies  
4️⃣ Search Emergency  
5️⃣ Update Emergency  
6️⃣ Delete Emergency  
7️⃣ Exit  

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
