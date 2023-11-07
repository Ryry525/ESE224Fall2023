#include "student.h"
#include <string>
#include <iostream>
#include <math.h>
using namespace std;

Student::Student(){
    name = "";
    roll_n = 0;
    mark = 0;
    percent = 0.0;
}

void Student::getPercent(){
    int max_mark = 500;
    if (mark == 0) 
    {
    cout << "Warning: Mark is 0. Make sure to set a valid mark before calling getPercent." << endl;
    }    
    percent = static_cast<double>(mark) / max_mark * 100.00; 
}

void Student::comparison(Student s2){
    if(mark > s2.mark){
        cout << name << " is Rank one\n";
    }
    else{ 
        cout << s2.name << " is Rank one\n";
    }
}

void Student::getDetails(){
    cout << "Enter name of student: \n";
    cin >> name;
    cout << "Enter roll number: \n";
    cin >> roll_n;
    cout << "Enter marks: \n";
    cin >> mark;
    getPercent();
}

void Student::displayDetails(){
    cout << "Student information";
    cout << "\nStudent name: " << name;
    cout << "\nRoll Number: " << roll_n;
    cout << "\nMark: " << mark;
    cout << "\nPercent: " << percent << "%" << endl;
}