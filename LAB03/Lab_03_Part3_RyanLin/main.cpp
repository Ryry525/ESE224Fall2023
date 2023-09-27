#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;

int fibonacciSequence(int number)
{
    if (number <= 1) {
        return number;
    }
    return fibonacciSequence(number - 1) + fibonacciSequence(number - 2);
}
int main(){
    int n;
ifstream fin("data3.txt");
ofstream fout("output.txt");

if(fin.fail()){
    cerr << "Error opening the intput file";
    exit(1);
}
if(fout.fail()){
    cerr << "Error opening the output file";
    exit(1);
}
while(fin >> n){
    fout << "Fibonacci of " << n << " is " << fibonacciSequence(n) << endl; 
}
cout << "Completed Fibonacci sqeuence";
fin.close();
fout.close();

}