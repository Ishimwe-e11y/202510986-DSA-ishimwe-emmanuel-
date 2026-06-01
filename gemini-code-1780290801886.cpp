#include "LibraryBook.h"
#include <iostream>
#include <iomanip>

// Default Constructor
LibraryBook::LibraryBook() {
    bookID = 0;
    title = "";
    author = "";
    borrowerName = "";
    daysBorrowed = 0;
    isBorrowed = false;
}

// Parameterized Constructor
LibraryBook::LibraryBook(int id, std::string t, std::string a) {
    bookID = id;
    title = t;
    author = a;
    borrowerName = "";
    daysBorrowed = 0;
    isBorrowed = false;
}

// Destructor
LibraryBook::~LibraryBook() {
    std::cout << "[Destructor]: Book ID " << bookID << " (\"" << title << "\") object is destroyed.\n";
}

// Getters
int LibraryBook::getBookID() const { return bookID; }
std::string LibraryBook::getTitle() const { return title; }
std::string LibraryBook::getAuthor() const { return author; }
std::string LibraryBook::getBorrowerName() const { return borrowerName; }
int LibraryBook::getDaysBorrowed() const { return daysBorrowed; }
bool LibraryBook::getBorrowStatus() const { return isBorrowed; }

// Setters
void LibraryBook::setBookID(int id) { bookID = id; }
void LibraryBook::setTitle(std::string t) { title = t; }
void LibraryBook::setAuthor(std::string a) { author = a; }
void LibraryBook::setBorrowerName(std::string name) { borrowerName = name; }
void LibraryBook::setDaysBorrowed(int days) { daysBorrowed = days; }
void LibraryBook::setBorrowStatus(bool status) { isBorrowed = status; }

// Business Logic
void LibraryBook::borrowBook(std::string borrower, int days) {
    isBorrowed = true;
    borrowerName = borrower;
    daysBorrowed = days;
}

void LibraryBook::returnBook() {
    isBorrowed = false;
    borrowerName = "";
    daysBorrowed = 0;
}

bool LibraryBook::isOverdue() const {
    // School rule: Books must be returned within 14 days
    return (isBorrowed && daysBorrowed > 14);
}

double LibraryBook::calculateFine() const {
    if (!isOverdue()) return 0.0;
    int overdueDays = daysBorrowed - 14;
    return overdueDays * 150.0; // 150 RWF fine per extra day
}

void LibraryBook::displayBookDetails() const {
    std::cout << std::left << std::setw(8) << bookID 
              << std::setw(25) << title 
              << std::setw(20) << author 
              << std::setw(12) << (isBorrowed ? "Borrowed" : "Available")
              << std::setw(18) << (isBorrowed ? borrowerName : "-")
              << std::setw(15) << daysBorrowed;
    if (isOverdue()) {
        std::cout << std::setw(10) << "YES" << " (" << calculateFine() << " RWF)";
    } else {
        std::cout << std::setw(10) << "NO";
    }
    std::cout << "\n";
}