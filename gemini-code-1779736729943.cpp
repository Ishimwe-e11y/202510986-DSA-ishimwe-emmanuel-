#include "student.h"
#include <iostream>

// Define the student storage vector
std::vector<Student> studentList;

// Function to add a student to the system
void addStudent() {
    Student newStudent;
    std::cout << "\n--- Add New Student ---\n";
    std::cout << "Enter Student ID: ";
    std::cin >> newStudent.id;
    std::cin.ignore(); // Clear the input buffer newline

    // Simple check to prevent duplicate IDs
    for (const auto& s : studentList) {
        if (s.id == newStudent.id) {
            std::cout << "Error: A student with this ID already exists!\n";
            return;
        }
    }

    std::cout << "Enter Name: ";
    std::getline(std::cin, newStudent.name);
    std::cout << "Enter Age: ";
    std::cin >> newStudent.age;
    std::cin.ignore();
    std::cout << "Enter Course: ";
    std::getline(std::cin, newStudent.course);

    studentList.push_back(newStudent);
    std::cout << "Student added successfully!\n";
}

// Function to display all students
void displayStudents() {
    std::cout << "\n--- Student List ---\n";
    if (studentList.empty()) {
        std::cout << "No student records found.\n";
        return;
    }

    for (const auto& s : studentList) {
        std::cout << "ID: " << s.id 
                  << " | Name: " << s.name 
                  << " | Age: " << s.age 
                  << " | Course: " << s.course << "\n";
    }
}

// Function to search for a student by ID
void searchStudent() {
    std::cout << "\n--- Search Student ---\n";
    if (studentList.empty()) {
        std::cout << "No student records available to search.\n";
        return;
    }

    int searchId;
    std::cout << "Enter Student ID to search: ";
    std::cin >> searchId;

    for (const auto& s : studentList) {
        if (s.id == searchId) {
            std::cout << "\nStudent Found:\n";
            std::cout << "ID: " << s.id << "\n";
            std::cout << "Name: " << s.name << "\n";
            std::cout << "Age: " << s.age << "\n";
            std::cout << "Course: " << s.course << "\n";
            return;
        }
    }
    std::cout << "Student with ID " << searchId << " not found.\n";
}

// Function to update a student's information
void updateStudent() {
    std::cout << "\n--- Update Student Information ---\n";
    if (studentList.empty()) {
        std::cout << "No student records available to update.\n";
        return;
    }

    int searchId;
    std::cout << "Enter Student ID to update: ";
    std::cin >> searchId;

    for (auto& s : studentList) {
        if (s.id == searchId) {
            std::cin.ignore();
            std::cout << "Enter New Name (Current: " << s.name << "): ";
            std::getline(std::cin, s.name);
            std::cout << "Enter New Age (Current: " << s.age << "): ";
            std::cin >> s.age;
            std::cin.ignore();
            std::cout << "Enter New Course (Current: " << s.course << "): ";
            std::getline(std::cin, s.course);
            
            std::cout << "Student records updated successfully!\n";
            return;
        }
    }
    std::cout << "Student with ID " << searchId << " not found.\n";
}

// Function to delete a student from the system
void deleteStudent() {
    std::cout << "\n--- Delete Student Record ---\n";
    if (studentList.empty()) {
        std::cout << "No student records available to delete.\n";
        return;
    }

    int searchId;
    std::cout << "Enter Student ID to delete: ";
    std::cin >> searchId;

    for (auto it = studentList.begin(); it != studentList.end(); ++it) {
        if (it->id == searchId) {
            studentList.erase(it);
            std::cout << "Student record deleted successfully!\n";
            return;
        }
    }
    std::cout << "Student with ID " << searchId << " not found.\n";
}