#include "factorial.h"
#include <string>
using namespace std;
#include <iostream>


unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int trailZero(unsigned long long number) {
    string numStr = to_string(number);
    int count = 0;
    for (int i = numStr.length() - 1; i >= 0 && numStr[i] == '0'; i--) {
        count++;
    }
    return count;
}

int displayMenu(){
    cout << "Menu:\n1. Calculate the number of trailing zeros\n2. Change the negative number to positive\n3. Terminate\n";
    return 0;
}
