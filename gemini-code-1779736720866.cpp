#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

// Define the Student structure
struct Student {
    int id;
    std::string name;
    int age;
    std::string course;
};

// Global vector to store students (extern allows sharing across files)
extern std::vector<Student> studentList;

// Function declarations
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

#endif // STUDENT_H