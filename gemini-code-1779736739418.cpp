#include <iostream>
#include "student.h"

int main() {
    int choice;

    do {
        std::cout << "\n==================================\n";
        std::cout << "    STUDENT MANAGEMENT SYSTEM    \n";
        std::cout << "==================================\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Display All Students\n";
        std::cout << "3. Search Student by ID\n";
        std::cout << "4. Update Student Info\n";
        std::cout << "5. Delete a Student\n";
        std::cout << "6. Exit Program\n";
        std::cout << "==================================\n";
        std::cout << "Enter your choice (1-6): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(); // [cite: 36]
                break;
            case 2:
                displayStudents(); // [cite: 36]
                break;
            case 3:
                searchStudent(); // [cite: 36]
                break;
            case 4:
                updateStudent(); // [cite: 36]
                break;
            case 5:
                deleteStudent(); // [cite: 36]
                break;
            case 6:
                std::cout << "\nExiting the system. Goodbye!\n";
                break;
            default:
                std::cout << "\nInvalid choice! Please select a valid option (1-6).\n";
        }
    } while (choice != 6); // Loop ends only when option 6 is selected [cite: 35, 37]

    return 0;
}