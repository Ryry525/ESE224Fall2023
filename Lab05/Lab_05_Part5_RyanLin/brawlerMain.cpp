#include <iostream>
#include <string>
#include <fstream>
#include "brawler.h"
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;


int main(){
    
    vector<Brawler> brawlers;
    ifstream fin("Brawlers.dat");

    if (fin.fail()){
        cerr << "Error opening the file";
        exit(1);
    }
    string name, type;
    int level, damage, health;

    while (getline(fin, name, ',')) {
    fin >> level;  // Read level
    fin.get();     // Read and discard the comma after level
    getline(fin, type, ',');
    fin >> damage;  // Read damage
    fin.get();      // Read and discard the comma after damage
    fin >> health;  // Read health

    Brawler newBrawler(name, level, type, damage, health);
    brawlers.push_back(newBrawler);
}
    fin.close();
    
    //sort brawlers alphabetically by name and print it 
    sort(brawlers.begin(), brawlers.end(), Brawler::sortBrawlers);
    cout << "\n\nThe sorted brawlers: " <<endl; 
    for (const Brawler& brawler : brawlers) {
        cout << brawler.getName() << " (Level: " << brawler.getLevel() << ", Type: " << brawler.getType()
             << ", Damage: " << brawler.getDamage() << ", Health: " << brawler.getHealth() << ")" << endl;
    }

    // Print epic brawlers with health above 8000
    cout << "\n\nEpic Brawlers with Health above 8000:" << endl;
    for (const Brawler& brawler : brawlers) {
        if (brawler.isEpic() && brawler.getHealth() > 8000) {
            cout << brawler.getName() << " (Level " << brawler.getLevel() << ", Type: " << brawler.getType() << ", Damage: " << brawler.getDamage() << ", Health: " << brawler.getHealth() << ")" << endl;
        }
    }

    // Print super-rare brawlers with damage below 4000
    cout << "\n\nSuper-Rare Brawlers with Damage below 4000:" << endl;
    for (const Brawler& brawler : brawlers) {
        if (brawler.isSuperRare() && brawler.getDamage() < 4000) {
            cout << brawler.getName() << " (Level " << brawler.getLevel() << ", Type: " << brawler.getType() << ", Damage: " << brawler.getDamage() << ", Health: " << brawler.getHealth() << ")" << endl;
        }
    }
    
    return 0;
}