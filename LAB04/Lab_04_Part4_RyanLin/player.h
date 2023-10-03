#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
    int coins;
    int choice;
public:
    Player();
    void playround(int dice);
    int getcoins() const;
    void setcoins(int coin);
    int getchoice() const;
    void setchoice(int nchoice);
    void winner(Player p2);
};
int rollDice();

#endif