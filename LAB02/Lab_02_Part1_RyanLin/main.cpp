#include <iostream>
#include "point.h"
using namespace std;

int main(){
    double x, y, r;
    cout << "Enter the coordinates of p1: " << endl;
    cin >> x >> y;
    Point p1(x, y);
    p1.Print();
    cout << "Enter the coordinates of p2: " << endl;
    cin >> x >> y;
    Point p2(x, y);
    p2.Print();

    cout << "The distance between the two point is " << p1.Distance(p2) << endl;
    cout << "The distance between the two point is " << p1 - p2 << endl;
    cout << "Are the two point the same? The answer is " << p2.Equal(p1) << endl;
    cout << "Are the two point the same? The answer is " << (p1==p2) << endl;
    cout << "Enter a number to multiply p2 by: \n";
    cin >> r;
    p2 * r;
    p2.Print();
    cout << "p1 > p2 ? " << (p1 > p2) << endl;
}