#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
private:
    std::string name;
    std::string dateOfBirth;
    double baseSalary;
    int joiningYear;
    int age;
    double totalSalary;

    void setName(const std::string& name);
    void setDateOfBirth(const std::string& dob);
    void setBaseSalary(double salary);
    void setJoiningYear(int year);
    void setAge(int age);
    void calculateTotalSalary();
    
public:
    Employee();
    void setInfo(const std::string& name, const std::string& dob, double salary, int year, int age);
    void getInfo() const;
    std::string getStatus() const;
    double calculateBonus(const std::string& status) const;
    const Employee& compareTotalSalary(const Employee& e) const;
    double getTotalSalary() const;
};

void generateInformationRandom(Employee& e);
void ShowAllBasedOnTotalSalary(Employee ar[], int size);

#endif // EMPLOYEE_H
