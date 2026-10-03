#pragma once
#include "maths/maths.h"
#include "game/inventory.h"
#include "game/equipment.h"
#include <string>
#include <string_view>

enum class Archetype {
    Unformed,

    Juggernaut,
    Duelist,
    Rogue,
    Mage,
    Warlock,
    Cleric,
    Battlemage,
    Survivor
};

struct ArchetypeResult {
    Archetype archetype;
    float affinity;
};

constexpr std::string_view to_string(Archetype archetype) {

    switch (archetype) {
        case Archetype::Unformed: return "Unformed";
        case Archetype::Juggernaut: return "Juggernaut";
        case Archetype::Duelist: return "Duelist";
        case Archetype::Rogue: return "Rogue";
        case Archetype::Mage: return "Mage";
        case Archetype::Warlock: return "Warlock";
        case Archetype::Cleric: return "Cleric";
        case Archetype::Battlemage: return "Battlemage";
        case Archetype::Survivor: return "Survivor";
    }

    return "Unknown";
}

class Character {
public:
    Character(maths::Random& rand, std::string name)
        : rand(rand), name(name) {}

    std::string name;

    int level() const; // Controls power of character (derived from xp)
    int xp = 0;        // Controls level

    int strength;      // Controls damage
    int dexterity;     // Controls accuracy and evasion
    int vitality;      // Controls health and defence
    int intelligence;  // Controls spell power
    int wisdom;        // Controls mana
    int luck;          // Controls critical hits, loot and events

    int health;
    
    int armour = 0;

    int silver = 500; // Starting silver

    Inventory inventory;
    Equipment equipment;
    
    void generate_character();
    void print() const;

    void deal_damage(float damage);

    int max_health() const;
    int base_damage() const;
    int defence() const;
    float damage_multiplier() const; // Calculates how defence affects damage taken
    float hit_chance(Character& other) const;
    float dodge_chance() const;
    float crit_chance() const;
    float crit_multiplier() const;

    ArchetypeResult archetype() const;
private:
    maths::Random& rand;
};