#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<int> sortedArray;
    
    int target;
    int value;
    cout << "Enter a sorted Array (end inputting by writing a -1): ";
    while (value != -1)
    {
    cin >> value;
    sortedArray.push_back(value); 
    }
}