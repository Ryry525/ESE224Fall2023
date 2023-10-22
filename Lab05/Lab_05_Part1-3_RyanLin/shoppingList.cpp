#include "shoppingList.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ShoppingList::ShoppingList()
{
    string file_name = "";
    fstream myFile;
    string most_expensive_item = "";
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
//task 2 
bool ShoppingList::itemExists(istream& in){
    string item_search;
    cout << "\nEnter the item name: ";
    in >> item_search;
    while(!myFile.eof()){
    myFile >> name;
    if (item_search == name){
        cout << "\nItem exists in the list." << endl;
        myFile.seekg(0, ios::beg);
        return true;
    }
    }
    cout << "\nItem does not exist in the list." << endl;
    myFile.seekg(0, ios::beg);
    return false;
}
void ShoppingList::addItem(istream& in){
    myFile.seekg(0, ios::end);
    string newItem;
    double newPrice;
    cout << "\nEnter item name to add: ";
    cin >> newItem;

    cout << "Enter its price: ";
    cin >> newPrice;

    myFile << "\n" << newItem << " " << newPrice;
    myFile.seekg(0, ios::beg);
    cout << "\nItem added successfully" << endl;
}
void ShoppingList::printMostExpensiveItem(){
    string itemName;
    double itemPrice;
    string mostExpensiveItem;
    while(!myFile.eof()){
        myFile >> itemName >> itemPrice;

        if (itemPrice > max_price){
            max_price = itemPrice;
            mostExpensiveItem = itemName;
        }
    }
    myFile.seekg(0, ios::beg);
    cout << "\nThe most expensive item is " << mostExpensiveItem << " and it costs $" << max_price << endl;
}
//task 3
//if program doesnt run use the c++11 standard 
void ShoppingList::priceSort(){
    vector<pair<string, double>> items;     //Vector to store items as pairs
    
    myFile.seekg(0, ios::beg);
    while (!myFile.eof()) {
        string name;
        double price;
        myFile >> name >> price;
        items.push_back(make_pair(name, price));
    }
     // Sort items by price in descending order
    sort(items.begin(), items.end(), [](const pair<string, double>& a, const pair<string, double>& b) {
        return a.second > b.second;
    });

    int count = 0;
    for (const pair<string, double>& item : items) {
        cout << ++count << ". " << item.first << "\t\t$" << item.second << endl;
    }
    
    myFile.seekg(0, ios::beg);
}
