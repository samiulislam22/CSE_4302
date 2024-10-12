#include "Employee.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

Employee::Employee() : name("John Doe"), dateOfBirth("1 January 2002"), baseSalary(10000), joiningYear(2000), age(18), totalSalary(0) {}

void Employee::setName(const std::string& name) {
    if (name.length() > 2) {
        this->name = name;
    } else {
        this->name = "John Doe";
    }
}

void Employee::setDateOfBirth(const std::string& dob) {
    // Assume age is calculated from dob
    if (age > 18) {
        this->dateOfBirth = dob;
    } else {
        this->dateOfBirth = "1 January 2002";
        this->age = 18;
    }
}

void Employee::setBaseSalary(double salary) {
    if (salary >= 10000 && salary <= 100000) {
        this->baseSalary = salary;
    } else {
        this->baseSalary = 10000;
    }
}

void Employee::setJoiningYear(int year) {
    this->joiningYear = year;
}

void Employee::setAge(int age) {
    if (age >= 18) {
        this->age = age;
    } else {
        this->age = 18;
    }
}

void Employee::calculateTotalSalary() {
    double transportAllowance = baseSalary * 0.10;
    double housingAllowance = baseSalary * 0.30;
    double miscAllowance = baseSalary * 0.10;
    totalSalary = baseSalary + transportAllowance + housingAllowance + miscAllowance;

    int years = 2024 - joiningYear;
    for (int i = 0; i < years; ++i) {
        baseSalary *= 1.03;
    }
}

double Employee::calculateBonus(const std::string& status) const {
    if (status == "Low") return baseSalary * 0.05;
    else if (status == "Moderate") return baseSalary * 0.10;
    else if (status == "High") return baseSalary * 0.15;
    return 0.0;
}

std::string Employee::getStatus() const {
    if (age <= 25 && totalSalary <= 20000) return "Low";
    if (age <= 25 && totalSalary > 20000) return "Moderate";
    if (age > 25 && totalSalary <= 21000) return "Low";
    if (age > 25 && totalSalary > 21000 && totalSalary <= 60000) return "Moderate";
    return "High";
}

void Employee::setInfo(const std::string& name, const std::string& dob, double salary, int year, int age) {
    setName(name);
    setDateOfBirth(dob);
    setBaseSalary(salary);
    setJoiningYear(year);
    setAge(age);
    calculateTotalSalary();
}

void Employee::getInfo() const {
    std::cout << "Name: " << name << "\n"
              << "Date of Birth: " << dateOfBirth << "\n"
              << "Base Salary: " << baseSalary << "\n"
              << "Joining Year: " << joiningYear << "\n"
              << "Age: " << age << "\n"
              << "Total Salary: " << totalSalary << "\n"
              << "Status: " << getStatus() << "\n";
}

const Employee& Employee::compareTotalSalary(const Employee& e) const {
    if (totalSalary > e.totalSalary) return *this;
    return e;
}

double Employee::getTotalSalary() const {
    return totalSalary;
}

void generateInformationRandom(Employee& e) {
    std::string randomName = "Random Name";  // Example random name
    std::string randomDob = "15 July 2000";  // Example random DOB
    double randomSalary = 10000 + (rand() % 90000);
    int randomYear = 2000 + (rand() % 24);
    int randomAge = 18 + (rand() % 40);
    
    e.setInfo(randomName, randomDob, randomSalary, randomYear, randomAge);
}

void ShowAllBasedOnTotalSalary(Employee ar[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (ar[i].getTotalSalary() > ar[j].getTotalSalary()) {
                std::swap(ar[i], ar[j]);
            }
        }
    }
    for (int i = 0; i < size; ++i) {
        std::cout << ar[i].getTotalSalary() << " - " << ar[i].getStatus() << std::endl;
    }
}
