#include <iostream>
#include <random>
#include <cmath>
#include <ctime>
using namespace std;

int displayMenu();

int main()
{
    srand(time(NULL));
    int i=1;
    do {
    double num1 = rand() % 500;
    double num2 = rand() % 500; 
    int choice = displayMenu();
    cin >> choice;
    switch (choice){
        case 1:
            cout << "Performing addition: " << num1 << " + " << num2 << " = " << num1 + num2 << endl << endl;
            break;
        case 2:
            cout << "Performing subtraction: " << num1 << " - " << num2 << " = " << num1 - num2 << endl << endl;
            break;
        case 3:
            cout << "Performing multiplication: " << num1 << " * " << num2 << " = " << num1 * num2 << endl << endl;
            break;
        case 4:
            cout << "Performing division: " << num1 << " / " << num2 << " = " << num1 / num2 << endl << endl;
            break;
        case 5:
            cout << "Ending the program" << endl;
            system("pause");
            i = 0;
            break;
        default:
            cout << "Invalid choice. Please try again\n";
        }
    }while (i != 0);
} 

int displayMenu(){
    cout << "Input a number 1 - 5 to select a random problem or exit the game." << endl << "1 - Addition\n2 - Subtraction\n3 - Multiplication\n4 - Division\n5 - Exit\n"; 
    return 0;
}
