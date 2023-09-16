#ifndef WATERLEVELMONITOR_H
#define WATERLEVELMONITOR_H
#include <string>
using namespace std;

class WaterLevelMonitor
{
private: 
    double currentLevel;
    double averageLevel;
    double highestLevel;
    double lowestLevel;
    int countLevel;
    double sumLevel;
public:
    WaterLevelMonitor();

    void receiveData(double level);
    double getCurrentLevel() const;
    double getAverageLevel() const;
    double getHighestLevel() const;
    double getLowestLevel() const;
    double getCountLevel();
    double getSumLevel();
};
#endif
