#include "player.h"
#include <string>
#include <iostream>
using namespace std;
#include <random>

Player::Player()
{
    name = "";
    age = 0;
    height = 0.0;
    nationality = "";
}

string Player::getName() const{
    return name;
}
int Player::getAge() const{
    return age;
}
double Player::getHeight() const{
    return height;
}
string Player::getNationality() const{
    return nationality;
}

void Player::setName(const string& newName){
    name = newName;
}
void Player::setAge(int newAge){
    age = newAge;
}
void Player::setHeight(double newHeight){
    height = newHeight;
}
void Player::setNationality(const string& newNationality){
    nationality = newNationality;
}


void Player::prediction(Player p2){
    if (age < p2.age && height > p2.height)
    {
        cout << "The winner is: " << name << endl;
    }
    else if (age > p2.age && height < p2.height)
    {
        cout << "The winner is: " << p2.name << endl;
    }
    else 
    {
        random_device rd;
        default_random_engine generator(rd());
        uniform_real_distribution<double> distribution(0.0, 1.0);
        double random_number = distribution(generator);

        //code to choose random player that wins
        if (random_number < 0.5)
        {
        cout << "The winner is: " << name << endl;
        // cout << random_number;
        }
        else 
        {
        cout << "The winner is: " << p2.name << endl;
        // cout << random_number;
        }
    }
}
