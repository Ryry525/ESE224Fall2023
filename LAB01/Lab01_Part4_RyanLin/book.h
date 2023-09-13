#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std;

class Book{
private: 
    int num;
    string title;
    string author;
    string genre;
    int page;
public:
    Book(int num, string title, string author, string genre, int page);

    void display();
};

#endif