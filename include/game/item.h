#pragma once
#include "maths/maths.h"
#include <string>
#include <vector>

// Forward declare character to be used in Weapon without including the entire character.h
class Character;

class Item {
public:
    Item(maths::Random& rand, std::string name, std::string description, int price, bool enchantable)
        : rand(rand), name(name), description(description), price(price), enchantable(enchantable) 
    {
        std::vector<std::string> qualities = {"Awful", "Poor", "Normal", "Good", "Excellent", "Masterwork", "Legendary"};
        quality = rand.choice(qualities);
    }

    std::string name;
    std::string description;
    int price;
    std::string quality;
    bool enchantable;

    virtual ~Item() = default;
    virtual void inspect() = 0;

    virtual std::string get_display_name() const;
protected:
    maths::Random& rand;
};

struct HitData {
    bool hit;
    float damage;
    Character* target;
    bool crit;
};

enum class WeaponType {
    short_blunt,
    long_blunt,
    short_blade,
    long_blade,
    axe,
    spear,
    archery,
    throwable
};

class Weapon: public Item {
public:
    Weapon(maths::Random& rand, std::string name, std::string description, int price, bool enchantable, int damage, float crit, WeaponType weapon_type)
        : Item(rand, name, description, price, enchantable),
            base_damage(damage),
            crit(crit),
            weapon_type(weapon_type)
        {}

    void inspect() override;
    HitData attack(Character& user, Character* target);

    int base_damage;
    float crit;
    WeaponType weapon_type;
};

enum class Slot {
    head,
    body,
    legs,
    feet
};

class Armour: public Item {
public:
    Armour(maths::Random& rand, std::string name, std::string description, int price, bool enchantable, int defence, Slot slot)
        : Item(rand, name, description, price, enchantable),
            defence(defence), slot(slot)
        {}

    void inspect() override;

    int defence;
    Slot slot;
};