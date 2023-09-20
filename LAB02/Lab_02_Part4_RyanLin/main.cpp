#include <iostream>
#include "line.h"
using namespace std;

int main()
{
    double k , b, ck, cb;
    cout << "Enter the parameter for l1: " << endl;
    cin >> k >> b;
    Line l1(k, b);
    l1.Print();
    cout << "Enter the parameter for l2: " << endl;
    cin >> k >> b;
    Line l2(k, b);
    l2.Print();

    cout << "Enter a number to change the slope of line 2 : " << endl;
    cin >> ck;
    l2 * ck;
    l2.Print();

    cout << "Enter a number to increment the intercept of line 2: " << endl;
    cin >> cb;
    l2 + cb;
    l2.Print();
    cout << "l1 == l2 ? " << (l2 == l1) << endl;
    system("pause");
    return 0;
}