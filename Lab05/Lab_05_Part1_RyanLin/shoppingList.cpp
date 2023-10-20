#include "shoppingList.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

ShoppingList::ShoppingList()
{
    string file_name = "itemCatalog.txt";
    fstream myFile = "";
    string monst_expensive_item = " ";
    string name = "";
    double price = 0;
    double max_price = 0;
}

bool ShoppingList::fileOpen(istream& in){
    in >> file_name;
    myFile.open(file_name);
    return myFile.is_open();
}
//task 1
void ShoppingList::printAll(){
    int count = 0;
    cout << endl;
    while(!myFile.eof()){
        myFile >> name >> price;
        cout << ++count << ". " << name << "\t\t$" << price << endl;
    }
    myFile.seekg(0, ios::beg);
    cout << endl;
}

void ShoppingList::printTranspose(){
    while(!myFile.eof())
    {
        myFile >> name >>price;
        int best_width = ceil(max(name.length(), to_string(price).length()))+1;
        cout << setw(best_width) << left << name;
    }
    cout << endl;
    myFile.seekg(0, ios::beg);
     while(!myFile.eof())
    {
        myFile >> name >>price;
        int best_width = ceil(max(name.length(), to_string(price).length()))+1;
        cout << setw(best_width) << left << price;
    }
    cout << endl;
    myFile.seekg(0, ios::beg);
}