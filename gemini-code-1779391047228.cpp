#include <iostream>
#include <string>

using namespace std;

// Global constants for configuration
const int MAX_TRANSACTIONS = 100; // [cite: 79]
const int DEFAULT_PIN = 12345; // [cite: 68]

// Function Prototypes to respect modular requirements
void displayMainMenu(); // [cite: 27]
void checkBalance(int balance); // [cite: 27]
void depositMoney(int &balance, string transactionHistory[], int &transCount); // [cite: 27]
void withdrawMoney(int &balance, string transactionHistory[], int &transCount); // [cite: 27]
void viewTransactionHistory(const string transactionHistory[], int transCount); // [cite: 27]

int main() {
    int maxAttempts = 3; // [cite: 74]
    int pin, choice; // [cite: 76]
    int balance = 0; // [cite: 76]
    string transactionHistory[MAX_TRANSACTIONS]; // [cite: 79]
    int transCount = 0; // [cite: 81]

    // Set header text to cyan color
    cout << "\033[36m"; // [cite: 84]
    cout << "\t\t==============================\n"; // [cite: 86]
    cout << "\t\t        BK ATM SYSTEM         \n"; // [cite: 91]
    cout << "\t\t==============================\n"; // [cite: 95]
    cout << "\033[0m" << endl; // [cite: 97]

    // Outer authentication loop
    do {
        cout << "\tEnter your PIN: "; // [cite: 120]
        cin >> pin; // [cite: 120]
        maxAttempts--; // [cite: 121]

        if (pin == DEFAULT_PIN) { // [cite: 122]
            cout << "\033[32m\n\tLogin Successful\033[0m\n"; // [cite: 123, 124, 125]
            cout << "\033[35m\tWelcome to BK ATM\033[0m\n"; // [cite: 126, 127, 128]
            
            // Inner menu loop
            do {
                displayMainMenu();
                cout << "\nEnter your choice: "; // [cite: 159]
                cin >> choice; // [cite: 160]

                switch (choice) {
                    case 1:
                        checkBalance(balance);
                        break;
                    case 2:
                        depositMoney(balance, transactionHistory, transCount);
                        break;
                    case 3:
                        withdrawMoney(balance, transactionHistory, transCount);
                        break;
                    case 4:
                        viewTransactionHistory(transactionHistory, transCount);
                        break;
                    case 5:
                        cout << "\033[33m\nThank You For Using BK ATM\033[0m\n"; // [cite: 289, 290, 292]
                        break;
                    default:
                        cout << "\033[31m\nInvalid Choice\033[0m\n"; // [cite: 301, 302, 306]
                        break;
                }
            } while (choice != 5); // [cite: 310]
            
            break; 
        } 
        else {
            cout << "\033[31m\nWrong PIN\033[0m\n"; // [cite: 326, 327, 328]
            if (maxAttempts > 0) { // [cite: 329]
                cout << "\033[33mRemaining Attempts : " << maxAttempts << "\033[0m\n\n"; // [cite: 331]
            }
        }
    } while (pin != DEFAULT_PIN && maxAttempts > 0); // [cite: 346]

    if (maxAttempts == 0 && pin != DEFAULT_PIN) { // [cite: 347]
        cout << "\033[31m\nATM BLOCKED\033[0m\n"; // [cite: 349]
    }

    return 0; // [cite: 356]
}

void displayMainMenu() {
    cout << "\n\033[34m=========== MAIN MENU ===========\033[0m\n"; // [cite: 130]
    cout << "  [1] Check Balance\n"; // [cite: 134]
    cout << "  [2] Deposit Money\n"; // [cite: 137]
    cout << "  [3] Withdraw Money\n"; // [cite: 140]
    cout << "  [4] Transaction History\n"; // [cite: 143]
    cout << "  [5] Exit\n"; // [cite: 146]
    cout << "\033[34m=================================\033[0m\n"; // [cite: 148]
}

void checkBalance(int balance) {
    cout << "\033[32m\nCurrent Balance: " << balance << " FRW\033[0m\n"; // [cite: 162, 163, 165]
}

void depositMoney(int &balance, string transactionHistory[], int &transCount) {
    int amount;
    cout << "\nEnter amount to deposit: "; // [cite: 183]
    cin >> amount; // [cite: 184]
    
    if (amount <= 0) {
        cout << "\033[31mInvalid amount!\033[0m\n";
        return;
    }

    balance += amount; // [cite: 186]
    cout << "\033[32m\nDeposit Successful\033[0m\n"; // [cite: 188, 189]
    cout << "New Balance: " << balance << " FRW\n"; // [cite: 191]

    if (transCount < MAX_TRANSACTIONS) {
        transactionHistory[transCount] = "Deposited: " + to_string(amount) + " FRW"; // [cite: 190, 192]
        transCount++; // [cite: 194]
    }
}

void withdrawMoney(int &balance, string transactionHistory[], int &transCount) {
    int amount;
    cout << "\nEnter amount to withdraw: "; // [cite: 205]
    cin >> amount; // [cite: 205]

    if (amount > balance) { // [cite: 206]
        cout << "\033[31m\nInsufficient Funds\033[0m\n"; // [cite: 211, 214]
    } else if (amount <= 0) {
        cout << "\033[31m\nInvalid withdrawal amount!\033[0m\n";
    } else {
        balance -= amount; // [cite: 224]
        cout << "\033[32m\nWithdrawal Successful\033[0m\n"; // [cite: 229]
        cout << "Withdrawn Amount: " << amount << " FRW\n"; // [cite: 231]
        cout << "Remaining Balance: " << balance << " FRW\n"; // [cite: 234]

        if (transCount < MAX_TRANSACTIONS) {
            transactionHistory[transCount] = "Withdrawn : " + to_string(amount) + " FRW"; // [cite: 240, 241]
            transCount++; // [cite: 243]
        }
    }
}

void viewTransactionHistory(const string transactionHistory[], int transCount) {
    cout << "\n\033[36m====== TRANSACTION HISTORY ======\033[0m\n"; // [cite: 260]
    if (transCount == 0) { // [cite: 261]
        cout << "\033[31mNo Transactions Found\033[0m\n"; // [cite: 263]
    } else {
        for (int i = 0; i < transCount; i++) { // [cite: 272]
            cout << (i + 1) << " " << transactionHistory[i] << "\n"; // [cite: 275]
        }
    }
}