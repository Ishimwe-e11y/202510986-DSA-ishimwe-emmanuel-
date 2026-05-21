#include <iostream>
#include <fstream> // [cite: 33]
#include <string>

using namespace std;

// Function Prototypes
void displayMainMenu(); // [cite: 27]
void showHistorySection(); // [cite: 27]
void showConceptsSection(); // [cite: 27]
void renderFileOrFallback(const string &filename, const string &fallbackContent);

int main() {
    int choice; // [cite: 30]

    do {
        displayMainMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) { // [cite: 30]
            case 1:
                showHistorySection(); // [cite: 31]
                break;
            case 2:
                showConceptsSection(); // [cite: 32]
                break;
            case 3:
                cout << "\nExiting the book system.\n"; // [cite: 30]
                break;
            default:
                cout << "\n\033[31mInvalid Selection. Try again.\033[0m\n";
                break;
        }
    } while (choice != 3);

    return 0;
}

void displayMainMenu() {
    cout << "\n=============================================\n";
    cout << "     FOUNDATIONS AND HISTORY OF C++ SYSTEM    \n"; // [cite: 29]
    cout << "=============================================\n";
    cout << " [1] View the History of C++\n"; // [cite: 30]
    cout << " [2] Learn About C++ Concepts\n"; // [cite: 32]
    cout << " [3] Exit Program\n"; // [cite: 30]
    cout << "=============================================\n";
}

void renderFileOrFallback(const string &filename, const string &fallbackContent) {
    ifstream contentFile(filename); // [cite: 33]
    
    cout << "\n---------------------------------------------\n";
    if (contentFile.is_open()) { // [cite: 33]
        string textLine;
        while (getline(contentFile, textLine)) { // [cite: 33]
            cout << textLine << "\n";
        }
        contentFile.close();
    } else {
        // Fallback display if external .txt files are missing [cite: 34]
        cout << "[Displaying Internal Content]\n\n" << fallbackContent << "\n";
    }
    cout << "---------------------------------------------\n";
}

void showHistorySection() {
    // Structural layout mapped directly from the tree reference diagram [cite: 31]
    string backupHistory = 
        "History and Evolution of C++:\n"
        " - Base Roots: Fortran -> Algol 60 -> CPL -> BCPL -> C\n" // [cite: 35, 39, 40, 41]
        " - Parallel Frameworks: PL/I, Pascal, Algol 68\n" // [cite: 36, 43, 45]
        " - Structural Impact: Simula 67, Object-Oriented paradigms\n" // [cite: 42]
        " - Conception: 'C with Classes' developed by Bjarne Stroustrup\n" // [cite: 48]
        " - Evolution Roadmap: C++ -> C++ar -> ANSI C -> C++std Standard"; // [cite: 52, 54, 56, 57]
        
    renderFileOrFallback("history.txt", backupHistory); // [cite: 33]
}

void showConceptsSection() {
    // Structural layout detailing the foundational topics requested [cite: 32]
    string backupConcepts = 
        "Core C++ Technical Manual Chapters:\n"
        " 1. Data Types   : Standard allocation types (int, float, char, bool).\n" // [cite: 32]
        " 2. Control Flow : Evaluation statements using if-else and switch-case blocks.\n" // [cite: 30, 32]
        " 3. Loops        : Repetitive control flow operations (while, do-while, for).\n" // [cite: 16, 24, 32]
        " 4. Arrays       : Indexed collection data matrices mapped to continuous memory.\n" // [cite: 17, 32]
        " 5. File Streams : Using dynamic external data stream tracking structures (<fstream>)."; // [cite: 32, 33]

    renderFileOrFallback("concepts.txt", backupConcepts); // [cite: 33]
}