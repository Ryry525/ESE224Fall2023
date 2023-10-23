#include "brawler.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

Brawler::Brawler(const string& name, int level, const string& type, int damage, int health) : name(name), level(level), type(type), damage(damage), health(health){
}

bool Brawler::sortBrawlers(const Brawler& b1, const Brawler& b2) {
    string name1 = b1.getName();
    string name2 = b2.getName();
    // Convert both names to lowercase for case-insensitive comparison
    transform(name1.begin(), name1.end(), name1.begin(), ::tolower);
    transform(name2.begin(), name2.end(), name2.begin(), ::tolower);
    return name1 < name2;
}
string Brawler::getName()const {
    return name;
}
int Brawler::getLevel() const{
    return level;
}
string Brawler::getType() const{
    return type;
}
int Brawler::getDamage() const{
    return damage;
}
int Brawler::getHealth() const{
    return health;
}
bool Brawler::isEpic() const {
    return type == "epic";
}

bool Brawler::isSuperRare() const {
    return type == "super-rare";
}