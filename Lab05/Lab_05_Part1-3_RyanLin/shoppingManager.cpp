#include "shoppingList.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
//use (g++ -std=c++11 shoppingList.cpp shoppingManager.cpp -o shoppingProgram) to run program 
void controlPanel(istream&, ShoppingList&); 

int main(){
    cout << "Opening Shopping_List_Manage . . ." << endl << endl;
    cout << "Please enter the file name: ";
    ShoppingList shoppingList;
    if (!shoppingList.fileOpen(cin)){
        cerr << "Error opening the target file!" <<endl;
        exit(1);
    }
    cout <<"\nSuccessfully opened the target file!" <<endl;
    controlPanel(cin, shoppingList);
    cout << "\nExiting the program..." <<endl;
    return 0;
}

void controlPanel(istream& in, ShoppingList &shoppingList)
{
    char expression = 'l';
    while (expression != 'q'){
        cout << "\n(a) - add an item and its price" <<endl;
        cout << "\n(e) - print the most expensive item in the list" <<endl;
        cout << "\n(i) - check to see if this item exists" <<endl;
        cout << "\n(p) - print all items and its price" <<endl;
        cout << "\n(q) - quit the program" <<endl;
        cout << "\n(s) - print in price decending order" <<endl;
        cout << "\n(t) - print transposed form" <<endl;
        cout <<"\nPlease select an option: ";
        in >> expression;
        switch (expression)
        {
        case 'p':
            shoppingList.printAll();
            break;
        case 't':
            shoppingList.printTranspose();
            break;
        case 'i':
            shoppingList.itemExists(cin);
            break;
        case 'a':
            shoppingList.addItem(cin);
            break;
        case 'e':
            shoppingList.printMostExpensiveItem();
            break;
        case 's':
            shoppingList.priceSort();
            break;
        default: 
            break;
        }
    }
}