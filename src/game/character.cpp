#include "game/character.h"
#include "maths/maths.h"
#include "util/util.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <format>
#include <map>
#include <vector>
#include <limits>
#include <string_view>

static int generate_stat(maths::Random& rand, float mean = 10.0f, float standard_deviation = 2.5f, int min = 1, int max = 20) {
    return std::clamp(static_cast<int>(std::round(rand.normal(mean, standard_deviation))), min, max);
}

int Character::level() const {
    return static_cast<int>(std::floor(3.4f * std::sqrtf(xp / 100.0f * 0.3f + maths::epsilon) + 1.0f));
}

void Character::generate_character() {
    stats.strength = generate_stat(rand);
    stats.dexterity = generate_stat(rand);
    stats.vitality = generate_stat(rand);
    stats.intelligence = generate_stat(rand);
    stats.wisdom = generate_stat(rand);
    stats.luck = generate_stat(rand);

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
    std::cout << std::format("STR {:>2}  DEX {:>2}  VIT {:>2}\n", stats.strength, stats.dexterity, stats.vitality);
    std::cout << std::format("INT {:>2}  WIS {:>2}  LCK {:>2}\n", stats.intelligence, stats.wisdom, stats.luck);
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

void Character::give_xp(float amount) {
    int old_level = level();
    xp += amount;

    int new_level = level();

    while (old_level < new_level) {
        ++old_level;
        handle_level_up(old_level);
    }
}

static std::vector<std::string> generate_choices(maths::Random& rand) {
    std::vector<std::string> choices = {"Strength", "Dexterity", "Vitality", "Intelligence", "Wisdom", "Luck"};
    return rand.choice(choices, 3);
}

void Character::handle_level_up(int level) {
    auto choices = generate_choices(rand);
    std::string chosen_stat;

    // If player controls this character allow the player to choose which stat to improve
    if (player_controlled) {
        std::cout << util::header("Level Up", util::separator_size) << '\n';
        std::cout << std::format("You have now reached Level {}\n\n", level);
        std::cout << "You have the option of increasing one of:\n";
        util::display_vector(choices);
        int choice = util::prompt("Please choose a stat to upgrade", 1, 3);
        chosen_stat = choices[choice - 1];
    }
    // If this is an NPC we choose for them a suitable stat to improve. 
    else {
        chosen_stat = rand.choice(choices);
    }

    apply_upgrade(chosen_stat);
}

void Character::apply_upgrade(std::string stat) {
    if (stat == "Strength") {
        stats.strength++;
    }
    else if (stat == "Dexterity") {
        stats.dexterity++;
    }
    else if (stat == "Vitality") {
        stats.vitality++;
    }
    else if (stat == "Intelligence") {
        stats.intelligence++;
    }
    else if (stat == "Wisdom") {
        stats.wisdom++;
    }
    else if (stat == "Luck") {
        stats.luck++;
    } else {
        std::cerr << std::format("Error: Upgrade applied to invalid stat '{}'.\n", stat);
    }
}

int Character::max_health() const {
    return static_cast<int>(50 + 8 * stats.vitality + 12 * std::pow(level(), 1.15));
}

int Character::base_damage() const {
    return static_cast<int>(2 * std::pow(stats.strength, 1.15) * std::pow(level(), 0.35));
}

int Character::defence() const {
    return static_cast<int>(0.8f * stats.vitality + equipment.defence());
}

float Character::damage_multiplier() const {
    return 100.0f / (100.0f + defence());
}

float Character::hit_chance(Character& other) const {
    return 1.0f / (1.0f + std::exp(-0.15 * (stats.dexterity - other.stats.dexterity + 5)));
}

float Character::dodge_chance() const {
    return 0.45f * (1.0f - std::exp(-0.045f * stats.dexterity));
}

float Character::crit_chance() const {
    return 0.02f + 0.003f * stats.luck + 0.001 * stats.dexterity;
}

float Character::crit_multiplier() const {
    return 1.5f + 0.02f * stats.luck;
}

std::unique_ptr<Item> Character::get_item(std::string_view name) {
    return inventory.get_first(name);
}

std::unique_ptr<Item> Character::choose_item() {
    std::vector<Item*> items = inventory.get_all();

    util::display_vector(items);
    int choice = util::prompt("Which item do you want to choose", 1, static_cast<int>(items.size()));

    return inventory.get_by_ptr(items[choice-1]);
}

void Character::give_item(std::unique_ptr<Item> item) {
    if (player_controlled) {
        std::cout << std::format("You recieved {}\n", item->get_display_name());
    }

    inventory.add_item(std::move(item));
}

void Character::use_item(std::unique_ptr<Item>& item) {
    std::string prompt = std::format("What will you do with the {}> ", item->name);

    if (auto* weapon = util::as<Weapon>(item)) {
        if (player_controlled) {
            std::vector<std::string> choices = {"Inspect", "Equip", "Attack"};
            util::display_vector(choices);
            int choice = util::prompt(prompt, 1, static_cast<int>(choices.size()));
            
            if (choice == 1) {
                weapon->inspect();
            } 
            else if (choice == 2) {
                equipment.equip(ItemSlot::hands, item);
            }
            else if (choice == 3) {
                std::vector<std::string> targets = {"Noone"};
                util::display_vector(targets);
                int choice = util::prompt("Attack who", 1, static_cast<int>(choices.size()));

                // Hard code attack at nobody. TODO: find nearby Characters.
                weapon->attack(*this, nullptr);
            }
        }
    }
    else if (auto* armour = util::as<Armour>(item)) {
        if (player_controlled) {
            std::vector<std::string> choices = {"Inspect", "Equip"};
            util::display_vector(choices);
            int choice = util::prompt(prompt, 1, static_cast<int>(choices.size()));

            if (choice == 1) {
                armour->inspect();
            } 
            else if (choice == 2) {
                equipment.equip(static_cast<ItemSlot>(armour->slot), item);
            }
        }
    } else {
        std::cerr << std::format("Error: Unhandled item {} selected.\n", item->get_display_name());
    }
}

ArchetypeResult Character::archetype() const{
    Archetype current_archetype = Archetype::Unformed;

    float strength_score =     (static_cast<float>(stats.strength)     - 10.0f) / 10.0f;
    float dexterity_score =    (static_cast<float>(stats.dexterity)    - 10.0f) / 10.0f;
    float vitality_score =     (static_cast<float>(stats.vitality)     - 10.0f) / 10.0f;
    float intelligence_score = (static_cast<float>(stats.intelligence) - 10.0f) / 10.0f;
    float wisdom_score =       (static_cast<float>(stats.wisdom)       - 10.0f) / 10.0f;
    float luck_score =         (static_cast<float>(stats.luck)         - 10.0f) / 10.0f;

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
    if (it->first > 0.1) {
        affinity = it->first;
        current_archetype = it->second;
    }

    return {current_archetype, affinity};
}
