#include "employee.h"
#include <iostream>
#include <string>
using namespace std;

Employee::Employee()
{
    id = 0;
    name = "";
    salary = 0;
}
Employee::Employee(int e_id, string e_name, int e_salary){
    id = e_id;
    name = e_name;
    salary = e_salary;
}
int Employee::getID()
{
    return id;
}