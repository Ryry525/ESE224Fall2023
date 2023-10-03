#include <iostream>
#include <fstream>
using namespace std;

void swap(double&, double&);
void fakeswap(double a, double b);

int main(){
    double a, b;
    ifstream datain;
    datain.open("input.dat");
    if (datain.fail()){
        cerr << "Error file cannot be opened";
        exit(1);
    }
    ofstream dataout;
    dataout.open("Output.dat");
    if(dataout.fail())
    {
        cerr << "Error file cannot be opened";
        exit(1);
    }
    while(!datain.eof()){
        datain >> a >> b;
        fakeswap(a, b);
        dataout << a << " " << b << endl;
        swap(a, b);
        dataout << a << " " << b << endl;
    }
}

void swap(double& a, double& b){
    double temp;
    temp = a;
    a = b;
    b = temp;
}

void fakeswap(double a, double b){
    double temp = a;
    a = b;
    b = temp;
}