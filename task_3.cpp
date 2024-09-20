#include <bits/stdc++.h>

using namespace std;

struct fraction {
    int numerator;
    int denominator;
};

int main() {
    fraction f1, f2, result;

    cout << "Enter the numerator and denominator of the first fraction: ";
    cin >> f1.numerator >> f1.denominator;

    cout << "Enter the numerator and denominator of the second fraction: ";
    cin >> f2.numerator >> f2.denominator;

    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;

    cout << "The sum of the fractions is: " 
         << result.numerator << "/" << result.denominator << endl;

    return 0;
}
