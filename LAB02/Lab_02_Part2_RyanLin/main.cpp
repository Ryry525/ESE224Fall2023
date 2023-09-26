#include <iostream>
#include <string>
#include <vector>
#include "employee.h"
using namespace std;

int displayMenu(){
    cout << "1. Add Employee\n2. Update Employee\n3. Delete Employee\n4. Display Employee Information\n5. Display All Employees\n6. Calculate Average Salary\n7. Exit";
}

int main()
{
    vector<Employee> employees;

    while(true){
        int choice = displayMenu();

        switch(choice) {
            case 1: 
                //addEmployee(employees);
                break;
            case 2: 
                //updateEmployee(employees); 
            case 3:
                //displayEmployee(employees);
                break;
        }
    }
}