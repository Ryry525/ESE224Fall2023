#include "Point.hpp"
#include <math.h>


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

double Point::dist2origin()
{
	return sqrt(xCoord * xCoord + yCoord * yCoord);
}
