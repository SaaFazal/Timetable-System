# 🗓️ NTU Timetabling System

A C++ console-based application designed to help universities manage timetables for modules, students, lecturers, and rooms. This system supports both admin and student roles with different capabilities, including timetable creation, conflict detection, and CSV export.

---

## 📌 Features

### 🔐 Admin
- Add, edit, delete:
  - Modules
  - Students (with group assignment)
  - Lecturers
  - Rooms (with type specification)
- Generate and view weekly timetables
- Detect timetable conflicts (lecturer, room, or group)
- Export the full timetable to CSV

### 👩‍🎓 Student
- Login using group name
- View weekly group-specific timetable
- Search timetable by module, lecturer, or room
- Export personal timetable to CSV

---

## 📂 Folder Structure

```
Timetable-System/
├── SRC/        # All C++ source and header files
├── BUILD/      # Compiled executable: timetable.exe
├── DATA/       # CSV data files for modules, students, lecturers, rooms, timetable
├── TESTS/      # Test cases and documentation
```

---

## 🛠️ Build Instructions

### Compile the program (Windows PowerShell or Terminal):
```bash
g++ SRC/*.cpp -o BUILD/timetable.exe
```

> If wildcard expansion fails:
```bash
g++ SRC/main.cpp SRC/Module.cpp SRC/ModuleManager.cpp SRC/Student.cpp SRC/StudentManager.cpp SRC/Lecturer.cpp SRC/LecturerManager.cpp SRC/Room.cpp SRC/RoomManager.cpp SRC/TimetableEntry.cpp SRC/TimetableManager.cpp -o BUILD/timetable.exe
```

### Run:
```bash
./BUILD/timetable.exe
```

---

## 💾 Data Format (CSV)

- **Students**: ID, Name, Group
- **Lecturers**: ID, Name, Subject
- **Modules**: Code, Name, Lecturer
- **Rooms**: Number, Type
- **Timetable**: Group, Module, Lecturer, Room, Week, Day, Slot

---

## 🧪 Testing

Located in the `/TESTS` directory:
- Manual test case notes
- Timetable exports for validation
- Conflict scenarios

---

## 🔒 Authentication

- Admin credentials: `"admin"`; password: `"admin123"`
- Student login: `"student"` → Enter group name to access timetable

---

## 📌 Future Improvements

- GUI interface using Qt or JavaFX
- MySQL/PostgreSQL database integration
- Web-based portal for student access

---

## 📄 License

This project is for academic demonstration and coursework purposes. For any reuse or contribution, please contact the author.
