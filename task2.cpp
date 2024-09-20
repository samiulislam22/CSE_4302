#include <bits/stdc++.h>
using namespace std;

enum etype { laborer, secretary, manager, accountant, executive, researcher };

int main() {
    char letter;
    etype employeeType;

    cout << "Enter employee type (first letter only)\n";
    cout << "laborer, secretary, manager, accountant, executive, researcher): ";
    cin >> letter;

    switch (letter) {
        case 'l': employeeType = laborer; 
        break;
        case 's': employeeType = secretary; 
        break;
        case 'm': employeeType = manager; 
        break;
        case 'a': employeeType = accountant; 
        break;
        case 'e': employeeType = executive; 
        break;
        case 'r': employeeType = researcher; 
        break;
        default:
            cout << "Invalid input!" << endl;
            return 1;
    }

    cout << "Employee type is ";
    switch (employeeType) {
        case laborer: cout << "laborer"; 
        break;
        case secretary: cout << "secretary"; 
        break;
        case manager: cout << "manager"; 
        break;
        case accountant: cout << "accountant"; 
        break;
        case executive: cout << "executive"; 
        break;
        case researcher: cout << "researcher"; 
        break;
    }
    cout << "." << endl;

    return 0;
}
