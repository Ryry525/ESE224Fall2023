#include <iostream>
#include <random>
#include <ctime>
#include <cmath>
using namespace std;

int main(){
    //use monte carlo integration
    int numPoints = 10000000;
    int pointsCircle= 0;
    srand(time(NULL));
    for (int i = 0; i < numPoints; i++){
        double x = (double)(rand())/ RAND_MAX * 2 - 1;
        double y = (double)(rand())/ RAND_MAX * 2 - 1;

        if (x * x + y * y <= 1){
            pointsCircle++;
        }
    }
    double estimatedArea = static_cast<double>(pointsCircle) / numPoints * 4;

    cout.precision(6);
    cout << "Estimated area of circle is: " << estimatedArea << endl;
}