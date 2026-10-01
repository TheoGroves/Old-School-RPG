#include "game/character.h"
#include "maths/maths.h"
#include "util/util.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <format>

constexpr int separator_size = 23;

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
    std::cout << util::separator(separator_size) << '\n';
    std::cout << std::format("{} - {} - Lvl.{} ({} xp)\n", name, archetype, level(), xp);
    std::cout << util::separator(separator_size) << '\n';
    std::cout << std::format("STR {:>2}  DEX {:>2}  VIT {:>2}\n", strength, dexterity, vitality);
    std::cout << std::format("INT {:>2}  WIS {:>2}  LCK {:>2}\n", intelligence, wisdom, luck);
    std::cout << util::separator(separator_size) << "\n\n";

    std::cout << util::header("INVENTORY", separator_size) << '\n';
    std::vector<Item*> all_items = inventory.get_all();

    for (size_t i = 0; i < all_items.size(); ++i) {
        std::cout << std::format("{:>2}. {} [{}]\n", i+1, all_items[i]->name, all_items[i]->quality);
    }
    if (all_items.empty()) {
        std::cout << "Empty\n";
    }

    std::cout << util::separator(separator_size) << '\n';
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
    return static_cast<int>(0.8f * vitality + armour);
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