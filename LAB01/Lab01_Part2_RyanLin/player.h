//player.hpp

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

class Player
{
private: 
    string name;
    int age;
    double height;
    string nationality;

public:
    //constructor
    Player();

    //Getter Method
    string getName() const;
    int getAge() const;
    double getHeight() const;
    string getNationality() const;

    //setter Method
    void setName(const string& newName);
    void setAge(int newAge);
    void setHeight(double newHeight);
    void setNationality(const string& newNationality);
    void prediction(Player p2);
   
};

#endif 
