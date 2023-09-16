#include "WaterLevelMonitor.h"
#include <iostream>

using namespace std;

int main(){
    WaterLevelMonitor monitor;
    cout << "Current water level:" << monitor.getCurrentLevel() << endl;
    cout << "Average water level:" << monitor.getAverageLevel() << endl;
    cout << "Highest water level:" << monitor.getHighestLevel() << endl;
    cout << "Lowest water level:" << monitor.getLowestLevel() << endl;    

    double level;

    for (int i = 0; i<10; i++)
    {
        cout << "input the " <<i+1<< "th data: ";
        cin >> level;
        monitor.receiveData(level);
        cout << "Current water level:" << monitor.getCurrentLevel() << endl;
        cout << "Average water level:" << monitor.getAverageLevel() << endl;
        cout << "Highest water level:" << monitor.getHighestLevel() << endl;
        cout << "Lowest water level:" << monitor.getLowestLevel() << endl <<endl; 
        cout << "count level: "<< monitor.getCountLevel() << endl;
        cout << "sum level: "<< monitor.getSumLevel() << endl;
    }
    system("pause");

    return 0;
}