#include <bits/stdc++.h>

using namespace std;

class BankAccount {
private:
    string customerName;
    int accountNumber;
    string accType;
    double balanceAmount;

public:
    BankAccount() : balanceAmount(0.0) {}

    void customerDetails() {
        cout << "Enter customer name: ";
        getline(cin, customerName);
        cout << "Enter account number: ";
        cin >> accountNumber;
        cin.ignore(); 
    }

    void accountType() {
        cout << "Enter account type (Current/Saving): ";
        getline(cin, accType); 
    }

    void balance() {
        cout << "Current balance: " << balanceAmount << endl;
    }

    void deposit() {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        balanceAmount += amount;
        cout << "New balance: " << balanceAmount << endl;
    }

    void withdraw() {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount > balanceAmount) {
            cout << "Insufficient balance." << endl;
        } else {
            balanceAmount -= amount;
            cout << "New balance: " << balanceAmount << endl;
        }
    }

    void display() {
        cout << "Customer Name: " << customerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balanceAmount << endl;
    }
};

int main() {
    BankAccount customer;
    customer.customerDetails();
    customer.accountType();
    customer.deposit();
    customer.withdraw();
    customer.display();
    return 0;
}
