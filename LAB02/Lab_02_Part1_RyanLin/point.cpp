#include "point.h"
#include <cmath>
#include <iostream>
using namespace std;

Point::Point()
{
	xCoord = 0;
	yCoord = 0;
}
Point::Point(double x, double y)
{
	xCoord = x;
	yCoord = y;
}
double Point::getX()
{
	return xCoord;
}
double Point::getY()
{
	return yCoord;
}
void Point::setX(double x)
{
	xCoord = x;
}
void Point::setY(double y)
{
	yCoord = y;
}
double Point::Distance(const Point& p2) const{
    double dx = p2.xCoord - xCoord;
    double dy = p2.yCoord - yCoord;
    return sqrt(pow(dx,2) + pow(dy, 2));
}
double Point::operator -(const Point& p2) const{
    double dx = p2.xCoord - xCoord;
    double dy = p2.yCoord - yCoord;
    return sqrt(pow(dx,2) + pow(dy, 2));
}
bool Point::Equal(const Point& p2) const{
    return (p2.xCoord == xCoord) && (p2.yCoord == yCoord);
}
bool Point::operator ==(const Point& p2) const{
    return (p2.xCoord == xCoord) && (p2.yCoord == yCoord);
}
void Point::Print(){
    cout.setf(ios::fixed);
    cout.precision(3);
    cout << "The point is (" << xCoord << ", " << yCoord << ")" << endl;
}
void Point::operator * (double n){
    xCoord = (n * xCoord);
    yCoord = (n * yCoord);
}
bool Point::operator > (const Point& p2) const{
    double d1 = sqrt(pow(xCoord,2) + pow(yCoord, 2));
    double d2 = sqrt(pow(p2.xCoord,2) + pow(p2.yCoord, 2));
    return d1 > d2;
}
