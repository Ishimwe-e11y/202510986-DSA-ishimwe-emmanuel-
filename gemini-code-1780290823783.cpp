#include "Functions.h"
#include <iostream>
#include <iomanip>

void addBook(LibraryBook books[], int &bookCount, int maxBooks) {
    if (bookCount >= maxBooks) {
        std::cout << "Error: Library database is full.\n";
        return;
    }

    int id;
    std::string title, author;

    std::cout << "\nEnter Book ID: ";
    std::cin >> id;
    std::cin.ignore(); // Clean newline left in buffer

    // Check for duplicate ID tracking
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getBookID() == id) {
            std::cout << "Error: A book with this ID already exists.\n";
            return;
        }
    }

    std::cout << "Enter Book Title: ";
    std::getline(std::cin, title);
    std::cout << "Enter Book Author: ";
    std::getline(std::cin, author);

    // Append standard tracking object
    books[bookCount] = LibraryBook(id, title, author);
    bookCount++;
    std::cout << "Book added successfully!\n";
}

void displayBooks(const LibraryBook books[], int bookCount) {
    if (bookCount == 0) {
        std::cout << "\nNo books available in the system library database.\n";
        return;
    }

    std::cout << "\n" << std::string(95, '=') << "\n";
    std::cout << std::left << std::setw(8) << "ID" 
              << std::setw(25) << "Title" 
              << std::setw(20) << "Author" 
              << std::setw(12) << "Status"
              << std::setw(18) << "Borrower"
              << std::setw(15) << "Days Borrowed"
              << std::setw(10) << "Overdue?" << "\n";
    std::cout << std::string(95, '=') << "\n";

    for (int i = 0; i < bookCount; i++) {
        books[i].displayBookDetails();
    }
    std::cout << std::string(95, '=') << "\n";
}

void searchBook(const LibraryBook books[], int bookCount) {
    if (bookCount == 0) {
        std::cout << "\nLibrary is empty.\n";
        return;
    }

    int id;
    std::cout << "\nEnter Book ID to search: ";
    std::cin >> id;

    for (int i = 0; i < bookCount; i++) {
        if (books[i].getBookID() == id) {
            std::cout << "\nBook Found:\n";
            books[i].displayBookDetails();
            return;
        }
    }
    std::cout << "Book with ID " << id << " not found.\n";
}

void borrowBookMenu(LibraryBook books[], int bookCount) {
    int id;
    std::cout << "\nEnter Book ID to borrow: ";
    std::cin >> id;

    for (int i = 0; i < bookCount; i++) {
        if (books[i].getBookID() == id) {
            if (books[i].getBorrowStatus()) {
                std::cout << "Sorry, this book is already checked out by " << books[i].getBorrowerName() << ".\n";
                return;
            }
            
            std::string borrower;
            int days;
            std::cin.ignore();
            std::cout << "Enter Student Borrower Name: ";
            std::getline(std::cin, borrower);
            std::cout << "Enter number of days to borrow: ";
            std::cin >> days;

            books[i].borrowBook(borrower, days);
            std::cout << "Book successfully checked out to " << borrower << ".\n";
            return;
        }
    }
    std::cout << "Book with ID " << id << " not found.\n";
}

void returnBookMenu(LibraryBook books[], int bookCount) {
    int id;
    std::cout << "\nEnter Book ID to return: ";
    std::cin >> id;

    for (int i = 0; i < bookCount; i++) {
        if (books[i].getBookID() == id) {
            if (!books[i].getBorrowStatus()) {
                std::cout << "This book is already safe inside the library stack.\n";
                return;
            }
            
            if (books[i].isOverdue()) {
                std::cout << "ALERT: This book is overdue! Structural Fine: " << books[i].calculateFine() << " RWF.\n";
            }
            
            books[i].returnBook();
            std::cout << "Book safely processed and returned.\n";
            return;
        }
    }
    std::cout << "Book with ID " << id << " not found.\n";
}

void displayOverdueBooks(const LibraryBook books[], int bookCount) {
    bool foundAny = false;
    std::cout << "\n--- OVERDUE BOOKS REGISTRY ---\n";
    
    for (int i = 0; i < bookCount; i++) {
        if (books[i].isOverdue()) {
            books[i].displayBookDetails();
            foundAny = true;
        }
    }
    
    if (!foundAny) {
        std::cout << "Excellent status! No overdue items found today.\n";
    }
}

void calculateTotalFines(const LibraryBook books[], int bookCount) {
    double grandTotal = 0.0;
    for (int i = 0; i < bookCount; i++) {
        grandTotal += books[i].calculateFine();
    }
    std::cout << "\n=========================================\n";
    std::cout << " Total Outstanding Library Fines: " << grandTotal << " RWF\n";
    std::cout << "=========================================\n";
}