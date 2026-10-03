#include "game/character.h"
#include "maths/maths.h"
#include "util/util.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <format>
#include <map>

static int generate_stat(maths::Random& rand, float mean = 10.0f, float standard_deviation = 2.5f, int min = 1, int max = 20) {
    return std::clamp(static_cast<int>(std::round(rand.normal(mean, standard_deviation))), min, max);
}

int Character::level() const {
    return static_cast<int>(std::floor(3.4f * std::sqrtf(xp / 100.0f * 0.3f + maths::epsilon) + 1.0f));
}

void Character::generate_character() {
    strength = generate_stat(rand);
    dexterity = generate_stat(rand);
    vitality = generate_stat(rand);
    intelligence = generate_stat(rand);
    wisdom = generate_stat(rand);
    luck = generate_stat(rand);

    health = max_health();
}

void Character::print() const {
    std::cout << util::separator(util::separator_size) << '\n';
    std::cout << std::format("{} - Lvl.{} ({} xp)\n", name, level(), xp);
    std::cout << util::separator(util::separator_size) << '\n';
    auto archetype_result = archetype();
    std::cout << std::format("Archetype: {}\n", to_string(archetype_result.archetype));
    std::cout << std::format("Affinity:  {:.1f}%\n", archetype_result.affinity * 50.0f);
    std::cout << util::separator(util::separator_size) << '\n';
    std::cout << std::format("STR {:>2}  DEX {:>2}  VIT {:>2}\n", strength, dexterity, vitality);
    std::cout << std::format("INT {:>2}  WIS {:>2}  LCK {:>2}\n", intelligence, wisdom, luck);
    std::cout << util::separator(util::separator_size) << "\n\n";

    std::cout << util::header("Inventory", util::separator_size) << '\n';
    std::vector<Item*> all_items = inventory.get_all();

    for (size_t i = 0; i < all_items.size(); ++i) {
        std::cout << std::format("{:>2}. {} [{}]\n", i+1, all_items[i]->name, all_items[i]->quality);
    }
    if (all_items.empty()) {
        std::cout << "Empty\n";
    }

    std::cout << util::separator(util::separator_size) << "\n\n";

    equipment.print();

    std::cout << util::separator(util::separator_size) << "\n\n";
}

void Character::deal_damage(float damage) {
    health -= damage;
}

int Character::max_health() const {
    return static_cast<int>(50 + 8 * vitality + 12 * std::pow(level(), 1.15));
}

int Character::base_damage() const {
    return static_cast<int>(2 * std::pow(strength, 1.15) * std::pow(level(), 0.35));
}

int Character::defence() const {
    return static_cast<int>(0.8f * vitality + equipment.defence());
}

float Character::damage_multiplier() const {
    return 100.0f / (100.0f + defence());
}

float Character::hit_chance(Character& other) const {
    return 1.0f / (1.0f + std::exp(-0.15 * (dexterity - other.dexterity + 5)));
}

float Character::dodge_chance() const {
    return 0.45f * (1.0f - std::exp(-0.045f * dexterity));
}

float Character::crit_chance() const {
    return 0.02f + 0.003f * luck + 0.001 * dexterity;
}

float Character::crit_multiplier() const {
    return 1.5f + 0.02f * luck;
}

ArchetypeResult Character::archetype() const{
    Archetype current_archetype = Archetype::Unformed;

    float strength_score =     (static_cast<float>(strength)     - 10.0f) / 10.0f;
    float dexterity_score =    (static_cast<float>(dexterity)    - 10.0f) / 10.0f;
    float vitality_score =     (static_cast<float>(vitality)     - 10.0f) / 10.0f;
    float intelligence_score = (static_cast<float>(intelligence) - 10.0f) / 10.0f;
    float wisdom_score =       (static_cast<float>(wisdom)       - 10.0f) / 10.0f;
    float luck_score =         (static_cast<float>(luck)         - 10.0f) / 10.0f;

    std::map<float, Archetype> affinities = {
        {strength_score + vitality_score,     Archetype::Juggernaut},
        {strength_score + dexterity_score,    Archetype::Duelist},
        {dexterity_score + luck_score,        Archetype::Rogue},
        {intelligence_score + wisdom_score,   Archetype::Mage},
        {intelligence_score + luck_score,     Archetype::Warlock},
        {wisdom_score + vitality_score,       Archetype::Cleric},
        {strength_score + intelligence_score, Archetype::Battlemage},
        {vitality_score + luck_score,         Archetype::Survivor}
    };

    auto it = std::prev(affinities.end());
    float affinity = 0.0f;
    if (it->first > 0.5) {
        affinity = it->first;
        current_archetype = it->second;
    }

    return {current_archetype, affinity};
}
