// Simple ATM interface using OOP in C++

#include <iostream>
#include <limits>
using namespace std;

class ATM {
private:
    double balance;
    int pin;

public:
    ATM() : balance(1000.00), pin(1234) {}

    bool verifyPin(int enteredPin) const {
        return enteredPin == pin;
    }

    void displayMenu() const {
        cout << "\n===== ATM Menu =====\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "====================\n";
    }

    void checkBalance() const {
        cout << "Your current balance is: Rs." << balance << endl;
    }

    void depositMoney() {
        double amount;
        cout << "Enter the amount to deposit: Rs.";
        cin >> amount;

        if (cin.fail()) {
            cin.clear(); // Clear error
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
            return;
        }

        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited successfully! New balance: Rs." << balance << endl;
        } else {
            cout << "Invalid amount! Must be greater than zero.\n";
        }
    }

    void withdrawMoney() {
        double amount;
        cout << "Enter the amount to withdraw: Rs.";
        cin >> amount;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
            return;
        }

        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Amount withdrawn successfully! New balance: Rs." << balance << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance!\n";
        } else {
            cout << "Invalid amount!\n";
        }
    }

    void run() {
        int choice;
        int enteredPin;
        int attempts = 0;
        const int maxAttempts = 3;

        cout << "Welcome to the ATM!\n";

        while (attempts < maxAttempts) {
            cout << "Please enter your PIN: ";
            cin >> enteredPin;

            if (verifyPin(enteredPin)) {
                do {
                    displayMenu();
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                        case 1:
                            checkBalance();
                            break;
                        case 2:
                            depositMoney();
                            break;
                        case 3:
                            withdrawMoney();
                            break;
                        case 4:
                            cout << "Thank you for using the ATM. Goodbye!\n";
                            break;
                        default:
                            cout << "Invalid choice. Please try again.\n";
                    }

                } while (choice != 4);
                return;
            } else {
                attempts++;
                cout << "Incorrect PIN. Attempts left: " << (maxAttempts - attempts) << "\n";
            }
        }

        cout << "Too many incorrect attempts. Access denied.\n";
    }
};

int main() {
    ATM atm;
    atm.run();
    return 0;
}
