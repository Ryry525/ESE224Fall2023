#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
#define PI M_PI
int main(){
    ofstream foutCos("cosine.txt");
    ofstream foutSine("sine.txt");
    ifstream finCos("cosine.txt");
    ifstream finSine("sine.txt");
    ofstream foutResult("result.txt");
    ifstream finResult("result.txt");

    double radian;
    int count = 0;
    double rmse = 0.0;
    if(foutCos.fail()){
        cerr << "Error cosine.txt could not be opened" << endl;
        exit(1);
    }
    if(foutSine.fail()){
        cerr << "Error sine.txt could not be opened" << endl;
        exit(1);
    }
    if(foutResult.fail()){
        cerr << "Error result.txt could not be opened" << endl;
        exit(1);
    }
    if(finCos.fail()){
        cerr << "Error cosine.txt could not be opened" << endl;
        exit(1);
    }
    if(finSine.fail()){
        cerr << "Error sine.txt could not be opened" << endl;
        exit(1);
    }
    if(finResult.fail()){
        cerr << "Error sine.txt could not be opened" << endl;
        exit(1);
    }

    for(int i = 0; i < 50 ; i++){
    cout << "Enter radians: \n";
    cin >> radian;
    double angle;
    angle = radian * 180/PI; 
    foutCos << fixed << setprecision(2) << angle << "\t" << cos(radian) << endl;
    foutSine << fixed << setprecision(2) << angle << "\t" << sin(radian) << endl;
    }
    double read_angle;
    double read_temp, identity;
    while(finCos >> read_angle >> read_temp){
        identity = (sin(read_angle)*sin(read_angle)) + ((cos(read_angle)*cos(read_angle)));
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
    finResult.close();
    finCos.close();
    finSine.close();
}