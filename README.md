# Advanced School Management System

## Overview

The **Advanced School Management System** is a C++ console application designed to manage students, courses, and user authentication for a school or educational institution. It supports two user roles: **Admin** and **Student**. Admins can manage students and courses, while students can enroll in courses and view their details.

---

## Features

### Admin Dashboard
- Add new students
- Add new courses
- Enroll students in courses
- View all students and their enrolled courses
- View all courses
- Remove a course from a student
- Delete students or courses
- Save student and course data to files

### Student Dashboard
- View available courses
- Enroll in a course
- Remove an enrolled course
- View personal details and enrolled courses
- Save personal data to a file

---

## Getting Started

### Prerequisites
- C++ compiler (e.g., g++)
- Linux environment (recommended)


## Usage

- **Default Admin Credentials:**
  - ID: `0`
  - Username: `admin`
  - Password: `admin`

- **Data Files:**
  - Student and course data are saved in the `Data/` directory as `.txt` files.

- **Menus:**
  - Follow on-screen instructions to navigate through Admin or Student dashboards.

---

## Project Structure

```
AdvancedSchoolManagementSystem/
├── src/
│   └── main.cpp
├── include/
│   ├── User.h
│   ├── Student.h
│   ├── Admin.h
│   ├── Repository.h
│   ├── Authentication.h
│   ├── studentControl.h
│   ├── courseControl.h
│   ├── Course.h
│   └── SaveDataControl.h
├── Data/
│   ├── All_Student_Details.txt
│   ├── Course_Details.txt
│   └── Student_Details.txt
└── README.md
```

---

## Notes

- Make sure the `Data/` directory exists for saving files.
- All user input is handled via the console.
- The system uses simple text files for