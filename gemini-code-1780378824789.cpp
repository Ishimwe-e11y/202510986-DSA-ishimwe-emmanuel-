#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// Requirement 1: Create a Student Object to store student information [cite: 17]
class Student {
public:
    string rollNumber; // Stored as string to handle any formatting, leading zeros, or alphanumeric IDs safely [cite: 13]
    string name;       // [cite: 14]
    int age;           // [cite: 15]

    // Constructor for easy object instantiation
    Student(string roll, string n, int a) {
        rollNumber = roll;
        name = n;
        age = a;
    }

    // Helper method to format object data into a CSV string line [cite: 8]
    string toCSV() const {
        return rollNumber + "," + name + "," + to_string(age);
    }

    // Helper method to display a student's details cleanly to the console [cite: 20]
    void display() const {
        cout << "Roll Number: " << rollNumber << "\n";
        cout << "Name:        " << name << "\n";
        cout << "Age:         " << age << "\n";
        cout << "-----------------------\n";
    }
};

// Global constant for the file name [cite: 7]
const string FILE_NAME = "student.txt";

// Helper function to read all records from the CSV file into a vector of Student objects [cite: 26, 35]
vector<Student> loadAllStudents() {
    vector<Student> students;
    ifstream file(FILE_NAME); // [cite: 35]
    
    // If the file doesn't exist yet, just return an empty vector
    if (!file.is_open()) {
        return students;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue; // Skip empty lines if any

        stringstream ss(line);
        string roll, name, ageStr;

        // Parse CSV format split by commas [cite: 8]
        if (getline(ss, roll, ',') && getline(ss, name, ',') && getline(ss, ageStr, ',')) {
            // Trim potential leading/trailing whitespace around parsed data [cite: 9, 10, 11]
            try {
                int age = stoi(ageStr);
                students.push_back(Student(roll, name, age));
            } catch (...) {
                // Catch parsing errors gracefully if file gets corrupted
                continue;
            }
        }
    }
    file.close();
    return students;
}

// Helper function to rewrite the entire CSV file with the current vector data [cite: 23, 25, 26]
void saveAllStudents(const vector<Student>& students) {
    ofstream file(FILE_NAME, ios::trunc); // Overwrites the file permanently [cite: 23, 25, 35]
    if (!file.is_open()) {
        cout << "Error: Could not open file for writing!\n";
        return;
    }
    for (const auto& student : students) {
        file << student.toCSV() << "\n";
    }
    file.close();
}

// Requirement 2: Implement a function to display all students stored in the file [cite: 18, 28]
void displayAllStudents() {
    vector<Student> students = loadAllStudents();
    if (students.empty()) {
        cout << "\nNo student records found in " << FILE_NAME << ".\n";
        return;
    }

    cout << "\n--- ALL STUDENT RECORDS ---\n";
    for (const auto& student : students) {
        student.display();
    }
}

// Requirement 3: Search for a student by Roll Number [cite: 19, 29]
void searchStudent() {
    string searchRoll;
    cout << "\nEnter Roll Number to search: ";
    cin >> searchRoll;

    vector<Student> students = loadAllStudents();
    bool found = false;

    for (const auto& student : students) {
        if (student.rollNumber == searchRoll) {
            cout << "\nStudent Found:\n";
            student.display(); // [cite: 20]
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nStudent not found\n"; // [cite: 21]
    }
}

// Requirement 4: Update a student's information [cite: 22, 30]
void updateStudent() {
    string searchRoll;
    cout << "\nEnter Roll Number to update: ";
    cin >> searchRoll;

    vector<Student> students = loadAllStudents();
    bool found = false;

    for (auto& student : students) {
        if (student.rollNumber == searchRoll) {
            found = true;
            cout << "\nCurrent Details:\n";
            student.display();

            cout << "Enter New Name: ";
            cin.ignore(); // Clear input buffer
            getline(cin, student.name);
            cout << "Enter New Age: ";
            cin >> student.age;

            break;
        }
    }

    if (found) {
        saveAllStudents(students); // Saved permanently [cite: 23]
        cout << "\nStudent information updated successfully!\n";
    } else {
        cout << "\nStudent not found\n";
    }
}

// Requirement 5: Delete a student's record permanently from the file [cite: 24, 25, 31]
void deleteStudent() {
    string searchRoll;
    cout << "\nEnter Roll Number to delete: ";
    cin >> searchRoll;

    vector<Student> students = loadAllStudents();
    bool found = false;

    // Iterate and remove the element if the roll number matches
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->rollNumber == searchRoll) {
            students.erase(it);
            found = true;
            break;
        }
    }

    if (found) {
        saveAllStudents(students); // Removed permanently [cite: 25]
        cout << "\nStudent record deleted successfully!\n";
    } else {
        cout << "\nStudent not found\n";
    }
}

// Requirement 7: Menu-driven system using a loop and switch statement [cite: 27]
int main() {
    int choice;

    do {
        cout << "\n===============================\n";
        cout << "      STUDENT SYSTEM MENU      \n";
        cout << "===============================\n";
        cout << "1. Display All Students\n"; // [cite: 28]
        cout << "2. Search Student\n";       // [cite: 29]
        cout << "3. Update Student\n";       // [cite: 30]
        cout << "4. Delete Student\n";       // [cite: 31]
        cout << "5. Exit\n";                 // [cite: 32]
        cout << "Enter your choice: ";        // [cite: 33]
        
        // Input validation for menu choices
        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) { // [cite: 27]
            case 1:
                displayAllStudents();
                break;
            case 2:
                searchStudent();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                cout << "\nExiting program. Goodbye!\n"; // [cite: 32]
                break;
            default:
                cout << "\nInvalid option! Please try again.\n";
        }
    } while (choice != 5); // [cite: 27]

    return 0;
}