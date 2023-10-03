#include <iostream>
#include <random>
#include <cmath>
using namespace std;

int main(){
    srand(time(NULL));
    int n;
    cout << "Input amount of time \n";
    cin >> n;
    double min = __DBL_MAX__, max=0.0, sum=0.0, average=0.0;
    for(int i = 0; i < n; i++){
        double randomNumber = 1.0 + (double)(rand()) / (double(RAND_MAX / (2.0 - 1.0)));
        if(randomNumber > max){
            max = randomNumber;
        }
        if(randomNumber < min){
            min = randomNumber;
        }
        sum += randomNumber;
        average = sum / n;
    }
    cout << "The Maximum number is " << max << endl;
    cout << "The Minimum number is " << min << endl;
    cout << "The average is " << average << endl;
}