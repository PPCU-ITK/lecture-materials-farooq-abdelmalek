#include <iostream>
#include <vector>
#include <string>

// EXERCISE 3: Virtual Functions

class Character {
public:
    // TODO: Fix the "Static Binding" problem here.
    // We want the derived classes to handle the attack.
    void attack() { 
        std::cout << "Generic character swings a fist.\n";
    }
};

class Warrior : public Character {
public:
    // TODO: Add the 'override' keyword for best practices
    void attack() {
        std::cout << "Warrior swings a GIANT SWORD!\n";
    }
};

class Mage : public Character {
public:
    // TODO: Add the 'override' keyword for best practices
    void attack() {
        std::cout << "Mage casts a FIREBALL!\n";
    }
};

int main() {
    // A party of different characters
    std::vector<Character*> party;
    
    party.push_back(new Warrior());
    party.push_back(new Mage());
    party.push_back(new Warrior());

    std::cout << "--- Battle Start ---\n";
    for (Character* c : party) {
        // Currently, this calls Character::attack() (Static binding).
        // We want it to call the specific class method (Dynamic binding).
        c->attack();
    }
    std::cout << "--- Battle End ---\n";

    // Cleanup memory
    for (Character* c : party) {
        delete c;
    }
    party.clear();

    return 0;
}