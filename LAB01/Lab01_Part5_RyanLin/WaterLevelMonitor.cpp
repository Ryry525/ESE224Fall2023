// WaterLevelMonitor.cpp

#include "WaterLevelMonitor.h"

WaterLevelMonitor::WaterLevelMonitor() {
    currentLevel = 0.0;
    averageLevel = 0.0;
    highestLevel = 0.0;
    lowestLevel = 0.0;
}

void WaterLevelMonitor::receiveData(double level) {
    currentLevel = level;

    if (level > highestLevel) {
        highestLevel = level;
    }

    if (level < lowestLevel) {
        lowestLevel = level;
    }

    averageLevel = (averageLevel + level) / 2.0;
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
