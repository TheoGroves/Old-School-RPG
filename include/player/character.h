#pragma once
#include "maths/maths.h"
#include <string>

class Character {
public:
    Character(maths::Random rand, std::string name)
        : rand(rand), name(name) {}

    std::string name;
    std::string archetype; // Derived from stats

    int level = 1;    // Controls power of character
    int xp = 0;       // Controls level

    int strength;     // Controls damage
    int dexterity;    // Controls accuracy and evasion
    int vitality;     // Controls health and defence
    int intelligence; // Controls spell power
    int wisdom;       // Controls mana
    int luck;         // Controls critical hits, loot and events

    int health;
    
    int armour = 0; // TODO: replace with proper equipment system
    
    int max_health() const;
    int base_damage() const;
    int defence() const;
    float damage_multiplier() const; // Calculates how defence affects damage taken
    float hit_chance(Character& other) const;
    float dodge_chance() const;
    float crit_chance() const;
    float crit_multiplier() const;

    void generate_character();
    void print() const;
private:
    maths::Random rand;
};