#include "book.h"
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]){
    cout << "constructing 5 book objects" << endl;
    Book b1(1,"b1", "b1a", "b1g", 1);
    Book b2(2,"b2", "b2a", "b2g", 10);
    Book b3(3,"b3", "b3a", "b3g", 11);
    Book b4(4,"b4", "b4a", "b4g", 100);
    Book b5(5,"b5", "b5a", "b5g", 101);

    b1.display();
    b2.display();
    b3.display();
    b4.display();
    b5.display();
    b5 = b1;
    b5.display();
    
    return 0;
}