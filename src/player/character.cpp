#include "player/character.h"
#include "maths/maths.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <format>

static int generate_stat(maths::Random& rand, float mean = 10.0f, float standard_deviation = 2.5f, int min = 1, int max = 20) {
    return std::clamp(static_cast<int>(std::round(rand.normal(mean, standard_deviation))), min, max);
}

static std::string repeat(const std::string& s, int n) {
    std::string result;
    for (int i = 0; i < n; ++i) {
        result += s;
    }
    return result;
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
    std::string title = std::format("{} - {} - Lvl.{}\n", name, archetype, level);

    std::cout << title;
    std::cout << repeat("-", title.length()) << '\n';
    std::cout << std::format("STR {:>2}  DEX {:>2}  VIT {:>2}\n", strength, dexterity, vitality);
    std::cout << std::format("INT {:>2}  WIS {:>2}  LCK {:>2}\n", intelligence, wisdom, luck);
    std::cout << repeat("-", title.length()) << '\n';

}

int Character::max_health() const {
    return static_cast<int>(50 + 8 * vitality + 12 * std::pow(level, 1.15));
}

int Character::base_damage() const {
    return static_cast<int>(2 * std::pow(strength, 1.15) * std::pow(level, 0.35));
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