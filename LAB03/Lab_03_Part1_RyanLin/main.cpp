#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream fin("input.dat");
    ofstream fout("output.dat");
    string content;

    if(fin.fail()){
        cerr << "error opening input file" << endl;
        exit(1);
    }
    if (fout.fail()) {
        cerr << "error opening input file" << endl;
        exit(1);
    }
    cout << "Reading and writing " <<endl;

    fin >> content;
    fout << content;
    fin.close();
    fout.close();
    system("pause");
    return 0;
}