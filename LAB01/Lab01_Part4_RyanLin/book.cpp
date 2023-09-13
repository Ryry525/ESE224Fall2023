#include "book.h"
#include <iostream>
#include <string>
using namespace std;

Book::Book(int num, string title, string author, string genre, int page){
    this->num = num;
    this->title = title;
    this->author = author;
    this->genre = genre;
    this->page = page;
    
}

void Book::display() {
    cout << "Book Number: " << num << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Genre: " << genre << endl;
    cout << "Pages: " << page << endl <<endl;
}