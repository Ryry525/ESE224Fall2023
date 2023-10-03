#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <cstdio>
#include "factorial.h"

using namespace std;

int main(){
    ifstream fin("input.txt");
    ofstream foutTemp("temp.txt");
    ifstream finTemp("temp.txt");
    ofstream fout("output.txt");

    int num;
    if(fin.fail()){
        cerr << "Error input.txt cannot be opened";
        exit(1);
    }
    if(fout.fail()){
        cerr << "Error output.txt cannot be opened";
        exit(1);
    }
    if(foutTemp.fail()){
        cerr << "error temp.txt cannot be opened";
        exit(1);
    }
    if(finTemp.fail()){
        cerr << "error temp.txt cannot be opened";
        exit(1);
    }

    int terminate = 0;
    do{
        fin >> num;
        //using unsigned long long b/c the factorial is positive
        //and will be a big number if the factorial is big
        unsigned long long fact = factorial(num);
        cout << "Number read from the file is " << num << endl;
        int oper = displayMenu();
        cout << "Enter your choice (1/2/3): ";
        cin >> oper;
        switch(oper)
        {
            case 1:
                if (num > 0){
                    int zeroCount = trailZero(fact);
                    fout << zeroCount;
                    cout << "\nResult has been written to output.txt\n";
                }
                break;
            case 2:
                if (num < 0){
                    int posNum = abs(num);
                    cout << "Positive Number: " << posNum << endl;
                    foutTemp << posNum << endl;
                    finTemp >> num;
                if (remove("input.txt") != 0) {
                    cerr << "Error: Unable to delete input file." << endl;
                    return 1;
                }
                
                if (rename("temp.txt", "input.txt") != 0) {
                    cerr << "Error: Unable to rename temporary file." << endl;
                    return 1;
                }
                }
                break;
            case 3:
                cout << "Program is terminating...\n";
                terminate = 1;
                system("pause");
                break;
            default:
                cout << "Invalid choice. Please try again\n";
        }
    }while (terminate != 1);

    fin.close();
    fout.close();
}