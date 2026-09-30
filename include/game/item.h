#pragma once
#include "maths/maths.h"
#include <string>
#include <vector>

// Forward declare character to be used in Weapon without including the entire character.h
class Character;

class Item {
public:
    Item(maths::Random& rand, std::string name, int price)
        : rand(rand), name(name), price(price) 
    {
        std::vector<std::string> qualities = {"Awful", "Poor", "Normal", "Good", "Excellent", "Masterwork", "Legendary"};
        quality = rand.choice(qualities);
    }

    std::string name;
    int price;
    std::string quality;

    virtual ~Item() = default;
    virtual void inspect() = 0;
protected:
    maths::Random& rand;
};

class Weapon: public Item {
public:
    Weapon(maths::Random& rand, std::string name, int price, int damage, float crit)
        : Item(rand, name, price),
          damage(damage),
          crit(crit) {}

    void inspect() override;
    void attack(Character& target);

private:
    int damage;
    float crit;
};