#include <iostream>
#include <fstream>
#include <cfloat>
using namespace std;
#define MAX DBL_MAX

int main(){
    ifstream fin("data1.dat");
    ofstream fout("data1report.dat");
    double width, height;
    int rectangleCount = 0, squareCount = 0;
    double maxArea = 0, minArea = MAX, avgArea = 0, squareArea = 0, avgSqareArea = 0, totalArea = 0;
    double minWidth, minHeight, maxWidth, maxHeight;

    if (fin.fail()){
        cerr << "error opening input file" << endl;
        exit(1);
    }
    if (fout.fail()){
        cerr << "error opening output file" << endl;
        exit(1);
    }

    while (fin >> width >> height){
        double area = width * height;
        rectangleCount++;
        totalArea += area;

    if(width == height){
        squareCount++;
        squareArea += area;
    }
    if(area < minArea){
        minArea = area;
        minWidth = width;
        minHeight = height;
    }
    if(area > maxArea){
        maxArea = area;
        maxWidth = width;
        maxHeight = height;
    }
    }
    if (rectangleCount > 0)
    {
        avgArea = totalArea / rectangleCount;
        avgSqareArea = squareArea / squareCount;

        fout << "Max Area: " << maxArea << " " << maxWidth << " " << maxHeight << endl;
        fout << "Min Area: " << minArea << " " << minWidth << " " << minHeight << endl;
        fout << "Average area of all rectangle: " << avgArea << endl;
        fout << "Average area of all square: " << avgSqareArea << endl;
    
    cout << "Report has been written to data1report.dat." << endl;
    }
    else {
    cout << "No data found in data1.dat." << endl;
    }
    fin.close();
    fout.close();
}