#include "line.h"
#include <cmath>
#include <iostream>
using namespace std;

Line::Line(double k, double b)
{
    slope = k;
    intercept = b;
}

void Line::Print()
{
    cout <<"y = "<< slope << "x + " << intercept << endl;
}
void Line::operator *(double ck){
    slope = (ck * slope);
}
void Line::operator +(double cb){
    intercept = (cb + intercept);
}
bool Line::operator ==(const Line& l2) const{
    return(l2.intercept == intercept) && (l2.slope == slope);
}