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

struct Stats {
    int strength;      // Controls damage
    int dexterity;     // Controls accuracy and evasion
    int vitality;      // Controls health and defence
    int intelligence;  // Controls spell power
    int wisdom;        // Controls mana
    int luck;          // Controls critical hits, loot and events
};

enum class Specialization {
    Strength,
    Dexterity,
    Vitality,
    Intelligence,
    Wisdom,
    Luck
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
    Character(maths::Random& rand, std::string name, bool player_controlled=false)
        : rand(rand), name(name), player_controlled(player_controlled) {}

    bool player_controlled; // Does the player control this character currently? Allows certain functions to pass choices to the player.

    std::string name;

    int level() const;             // Controls power of character (derived from xp)
    int xp = 0;                    // Controls level
    Specialization specialization; // Late-game specialization allows one stat to go over level 20 cap

    Stats stats;

    int health;
    
    int armour = 0;

    int silver = 500;  // Starting silver

    Inventory inventory;
    Equipment equipment;
    
    void generate_character();
    void print() const;

    void deal_damage(float damage);

    void give_xp(float amount);
    void handle_level_up(int level);
    void apply_upgrade(std::string stat);

    int max_health() const;
    int base_damage() const;
    int defence() const;
    float damage_multiplier() const; // Calculates how defence affects damage taken
    float hit_chance(Character& other) const;
    float dodge_chance() const;
    float crit_chance() const;
    float crit_multiplier() const;

    std::unique_ptr<Item> get_item(std::string_view name);
    std::unique_ptr<Item> choose_item();
    void open_equipment();

    void give_item(std::unique_ptr<Item> item);
    void use_item(std::unique_ptr<Item>& item);

    ArchetypeResult archetype() const;
private:
    maths::Random& rand;
};