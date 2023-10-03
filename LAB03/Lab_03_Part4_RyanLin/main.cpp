#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;
#define PI M_PI
int main(){
    ofstream foutCos("cosine.txt");
    ofstream foutSine("sine.txt");
    ifstream finCos("cosine.txt");
    ifstream finSine("sine.txt");
    ofstream foutResult("result.txt");

    int count = 0;
    double rmse = 0.0;
    if(foutCos.fail() || finCos.fail()){
        cerr << "Error cosine.txt could not be opened" << endl;
        exit(1);
    }
    if(foutSine.fail() || finSine.fail()){
        cerr << "Error sine.txt could not be opened" << endl;
        exit(1);
    }
    if(foutResult.fail()){
        cerr << "Error result.txt could not be opened" << endl;
        exit(1);
    }
    int sample;
    cout << "Enter sample size: \n";
    cin >> sample;
    double step = (2 * PI) / sample;
    if (sample < 50)
    {
        cout << "Sample size too small\n";
        exit(1);
    }
    for(int i = 0; i < sample  ; i++){
    double angle;
    
    angle = i * step; 
    foutCos << fixed << setprecision(2) << angle << "\t" << cos(angle) << endl;
    foutSine << fixed << setprecision(2) << angle << "\t" << sin(angle) << endl;
    }
    double read_angle;
    double read_cos, identity, read_sine;
    while(finCos >> read_angle >> read_cos && finSine >> read_angle >> read_sine){
        identity = pow(read_sine,2) + pow(read_cos, 2);
        // cout << identity << endl;
        foutResult << identity << endl;
        count++;

    //calculate RMSE 
    double expectedValue = 1.0;
    double error = identity - expectedValue;
        rmse += error * error;
    }

    rmse = sqrt(rmse / count);
    
    cout << "Root Mean Squared Error (RMSE): " << rmse << endl;

    foutCos.close();
    foutSine.close();
    foutResult.close();
    finCos.close();
    finSine.close();
}