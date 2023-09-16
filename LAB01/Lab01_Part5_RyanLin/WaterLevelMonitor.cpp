// WaterLevelMonitor.cpp

#include "WaterLevelMonitor.h"
#include <iostream>
using namespace std;

WaterLevelMonitor::WaterLevelMonitor() {
    currentLevel = 0.0;
    averageLevel = 0.0;
    highestLevel = 0.0;
    lowestLevel = 0.0;
    countLevel = 0;
    sumLevel = 0.0;
}
void WaterLevelMonitor::receiveData(double level) {
    currentLevel = level;
    countLevel++;
    if (level > highestLevel) {
        highestLevel = level;
    }

    if (level < lowestLevel) {
        lowestLevel = level;
    }
    sumLevel += level;
    averageLevel = sumLevel / countLevel;
    // cout << "count level: "<< countLevel << endl;
    // cout << "sum level: "<< sumLevel << endl;
}

double WaterLevelMonitor::getCurrentLevel() const {
    return currentLevel;
}

double WaterLevelMonitor::getAverageLevel() const {
    return averageLevel;
}

double WaterLevelMonitor::getHighestLevel() const {
    return highestLevel;
}

double WaterLevelMonitor::getLowestLevel() const {
    return lowestLevel;
}
double WaterLevelMonitor::getCountLevel(){
    return countLevel;
}
double WaterLevelMonitor::getSumLevel(){
    return sumLevel;
}
