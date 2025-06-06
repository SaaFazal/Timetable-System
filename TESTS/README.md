# ntu-timetabling-system
Overview:

This is a C++ console-based application developed to manage university timetables. 
It allows administrators to manage modules, students, lecturers, rooms, and timetables, while students can view and export their timetables.

Folder Structure:

SRC/      -> Contains all source (.cpp) and header (.h) files
BUILD/    -> Contains the compiled executable (timetable.exe)
DATA/     -> CSV files for saved modules, students, lecturers, rooms, timetable
TESTS/    -> Notes or test case documentation

Features:

Admin Features:
- Add, view, edit, delete modules
- Add, view, edit, delete students (with group assignment)
- Add, view, edit, delete lecturers
- Add, view, edit, delete rooms (with type)
- Create and view weekly timetable
- Detect timetable conflicts (lecturer, room, or group conflicts)
- Export full timetable to CSV

Student Features:
- Login with 'student'
- Enter their group name
- View timetable by week number
- Search timetable by module, lecturer, or room (within group)
- Export their timetable to CSV

Usage Instructions:

1. **Build the Project** (From the root directory):

   For PowerShell:
   g++ SRC/*.cpp -o BUILD/timetable.exe

   Or manually list files if wildcard doesn't work:
   g++ SRC/main.cpp SRC/Module.cpp SRC/ModuleManager.cpp SRC/Student.cpp SRC/StudentManager.cpp SRC/Lecturer.cpp SRC/LecturerManager.cpp SRC/Room.cpp SRC/RoomManager.cpp SRC/TimetableEntry.cpp SRC/TimetableManager.cpp -o BUILD/timetable.exe

2. **Run the Program**:

   .\BUILD\timetable.exe

3. **Login Credentials**:

   - admin     → Full access to all system features (password = "admin123")
   - student   → Limited access (enter group name to access own timetable)

4. **Saving and Loading**:

   All data is saved to and loaded from:
   - data_modules.csv
   - data_students.csv
   - data_lecturers.csv
   - data_rooms.csv
   - data_timetable.csv

   Files will be automatically created if they do not exist.

Test Notes:

- Add a few modules, rooms, and lecturers from the admin menu
- Schedule sessions for a group using the timetable option
- Log in as student, use your group, and test viewing + exporting timetable
- Try creating a conflict and verify the system blocks it
