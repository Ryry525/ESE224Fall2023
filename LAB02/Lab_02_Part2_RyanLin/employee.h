#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <vector>
using namespace std;

class Employee
{
private:
    int id;
    string name;
    int salary;
public:
    Employee();
    Employee(int e_id, string e_name, int e_salary);
    //getter 
    int getID();
    string getName();
    double getSalary();

    //setter
    int setID();
    string setName();
    double setSalary();

    // void addEmployee(Employee) const;
    // void updateEmployee(Employee e2) const;
    // void deleteEmployee(Employee e2) const;
    // void displayEmployee(Employee e2) const;
    // void displayALLEmplplyees(Employee e2) const;
    // void calcuatedAverageSalary(Employee e2) const;
};



#endif 