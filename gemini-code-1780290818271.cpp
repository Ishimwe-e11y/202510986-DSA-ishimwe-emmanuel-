#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "LibraryBook.h"

// System state utility declarations
void addBook(LibraryBook books[], int &bookCount, int maxBooks);
void displayBooks(const LibraryBook books[], int bookCount);
void searchBook(const LibraryBook books[], int bookCount);
void borrowBookMenu(LibraryBook books[], int bookCount);
void returnBookMenu(LibraryBook books[], int bookCount);
void displayOverdueBooks(const LibraryBook books[], int bookCount);
void calculateTotalFines(const LibraryBook books[], int bookCount);

#endif