#include "player.h"
#include <iostream>
#include <string>
#include <random>
using namespace std;

Player::Player(){
    int choice = 0;
    int coins = 0;
}

void Player::playround(int dice){
    if (choice == dice)
    {
        coins = coins * 2;
    }
    else
    {
        coins = coins - 50;
    }
}
int Player::getcoins() const{
    return coins;
}
void Player::setcoins(int coin){
    coins = coin;
}
int Player::getchoice() const{
    return choice;
}
void Player::setchoice(int nchoice){
    choice = nchoice;
}
void Player::winner(Player p2){
    if(coins < p2.coins){
        cout << "The winner is Player 1 with " << p2.coins << " coins" <<endl;
        cout << "The loser is Player 2 with " << coins << " coins" << endl;
    }
    else if(coins > p2.coins){
        cout << "The winner is Player 2 with " << coins << " coins" << endl;
        cout << "The loser is Player 1 with " << p2.coins << " coins" << endl;
    }
    else{
        cout << "There is a tie with both players having " << coins << " coins" <<endl;
    }
}
int rollDice(){
    return (rand() % 6) + 1;
}
