#include <iostream>
#include "player.h"
#include <ctime>
#include <random>
using namespace std;

int main(){
    Player p1;
    Player p2;
    int inputChoice;
    srand(time(NULL));
    p1.setcoins(200);
    p2.setcoins(200);
    for(int i = 0; i < 3; i++)
    {
    cout << "\nRound " << i+1 << ":" <<endl;
    int dice = rollDice();
    cout << "Player 1 input choice(1-6): ";
    cin >> inputChoice; 
    p1.setchoice(inputChoice);
    cout << "\nPlayer 2 input choice(1-6): ";
    cin >> inputChoice; 
    p2.setchoice(inputChoice);
    p1.playround(dice);
    p2.playround(dice);
    }
    p2.winner(p1);
}