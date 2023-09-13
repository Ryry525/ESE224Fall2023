#include "student.h"
#include <iostream>
using namespace std;

int main(){
    Student std;
    std.getDetails();
    cout << endl;
    std.displayDetails();
    cout << endl;
    Student std2;
    std2.getDetails();
    cout << endl;
    std2.displayDetails();
    cout << endl;
    std2.comparison(std);

    return 0;
}