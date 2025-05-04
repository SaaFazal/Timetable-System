Overview:
The NTU Timetabling System is a C++ console-based application designed to automate the scheduling and management of university timetables. It provides role-based access for administrators and students to manage or view timetables efficiently.

Key Features:
Admin Functionalities:

Manage modules, students (with group assignment), lecturers, and rooms.

Generate and view weekly timetables.

Detect scheduling conflicts (lecturer, room, group).

Export complete timetable to CSV.

Student Functionalities:

Login as a student and enter their group name.

View group-specific timetable by week.

Search timetable by module, lecturer, or room.

Export personal timetable to CSV.

Project Structure:
SRC/ – All source and header files (.cpp, .h)

BUILD/ – Compiled application executable (timetable.exe)

DATA/ – CSV files storing modules, students, lecturers, rooms, and timetables

TESTS/ – Test documentation and usage notes

Technologies Used:
C++

CSV-based data storage

Object-oriented programming

Console I/O operations

How to Build & Run:
g++ SRC/*.cpp -o BUILD/timetable.exe
# or manually specify files if wildcard doesn't work
g++ SRC/main.cpp SRC/Module.cpp SRC/Student.cpp ... -o BUILD/timetable.exe
