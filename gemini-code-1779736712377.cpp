#include <iostream>

// Function definition for swapping two numbers using pointers
void swapNumbers(int* a, int* b) {
    if (a == nullptr || b == nullptr) return; // Safety check
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1 = 10;
    int num2 = 20;

    std::cout << "Before swap: num1 = " << num1 << ", num2 = " << num2 << "\n";
    
    // Pass the addresses of num1 and num2 using the address-of (&) operator
    swapNumbers(&num1, &num2);

    std::cout << "After swap: num1 = " << num1 << ", num2 = " << num2 << "\n";

    return 0;
}