#include <string>
using namespace std;

#ifndef BRAWLER_H
#define BRAWLER_H


class Brawler{
private:
    string name;
    int level;
    string type;
    int damage;
    int health;
public:
    Brawler(const string& name, int level, const string& type, int damage, int health);
    static bool sortBrawlers(const Brawler& b1, const Brawler& b2);
    
    string getName() const;
    int getLevel() const;
    string getType() const;
    int getDamage() const;
    int getHealth() const;
    bool isEpic() const;
    bool isSuperRare() const;
};

#endif