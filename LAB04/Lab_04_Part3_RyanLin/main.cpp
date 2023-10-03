#include <iostream>
using namespace std;

int g_c_d(int a, int b);

int main(){
    int n1, n2;
    cout << "Enter number 1: "; 
    cin >> n1;
    cout << endl << "Enter Number 2: ";
    cin >> n2;

    int result = g_c_d(n1,n2);
    cout << endl << "The Greatest common divisor is: " << result << endl;
}

int g_c_d(int a, int b){
    if (a <= 0 || b <= 0){
        return 0;
    }

    while (b != 0){
        int temp = b;
        b = a %b;
        a = temp;
    }
    return a;
}