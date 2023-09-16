//Ryan Lin 114737153

#include <iostream>
#include "player.h"
using namespace std;

int main()
{
    Player player1;
    player1.setName("Christian Ronaldo");
    player1.setAge(38);
    player1.setHeight(6.2);
    player1.setNationality("Portugal");

    Player player2;
    player2.setName("Leonel Messi");
    player2.setAge(36);
    player2.setHeight(5.7);
    player2.setNationality("Argentina");

    cout << "Player Information:\n";
    cout << "Name: " << player1.getName() << endl;
    cout << "age: " << player1.getAge() << endl;
    cout << "Height: " << player1.getHeight() << endl;
    cout << "Nationality: " << player1.getNationality() << endl << endl;

    cout << "Player2 Information:\n";
    cout << "Name: " << player2.getName() << endl;
    cout << "age: " << player2.getAge() << endl;
    cout << "Height: " << player2.getHeight() << endl;
    cout << "Nationality: " << player2.getNationality() << endl;

    player2.prediction(player1);

    return 0;
}
