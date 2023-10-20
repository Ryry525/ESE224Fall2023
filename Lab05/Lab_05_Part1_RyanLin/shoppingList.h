#include <string>
#include <fstream>
using namespace std;

class ShoppingList{
private:
    string file_name;
    fstream myFile;
    string monst_expensive_item;
    string name;
    double price;
    double max_price;
public:
    ShoppingList();
    bool fileOpen(istream& in);
    bool itemExists(istream& in);
    void addItem(istream& in);
    void printMostExpensiveItem();
    void printAll();
    void printTranspose();
    void priceSort();
};
