#include "game/item.h"
#include "game/character.h"
#include "util/util.h"
#include <iostream>
#include <format>

std::string Item::get_display_name() const { 
    return std::format("{} ({}){}", name, quality, enchantable ? " [ENCHANTABLE]" : ""); 
}

void Weapon::inspect() {
    std::string title = get_display_name();
    util::print(title + '\n');
    util::print(util::repeat("-", title.length()) + '\n');
    util::print(std::format("DMG {:>3}  CRT {:>3}", base_damage, crit) + '\n');
    util::print(util::repeat("-", title.length()) + '\n');
}

HitData Weapon::attack(Character& user, Character* target) {
    HitData data{false, 0.0f, target, false};
    
    if (!target) {
        return data;
    }
    
    if (rand.uniform() < target->hit_chance(user)) {
        float crit = 1.0f;
        if (rand.uniform() < user.crit_chance()) {
            crit = user.crit_multiplier();
            data.crit = true;
        }
        
        float damage = (user.base_damage() + base_damage) * crit * target->damage_multiplier();
        target->deal_damage(damage);
        data.damage = damage;
        data.hit = true;
    }

    return data;
}

void Armour::inspect() {
    std::string title = get_display_name();
    util::print(title + '\n');
    util::print(util::repeat("-", title.length()) + '\n');
    util::print(std::format("DEF {:>3}", defence));
    util::print(util::repeat("-", title.length()) + '\n');
}