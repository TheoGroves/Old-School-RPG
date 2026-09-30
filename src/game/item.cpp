#include "game/item.h"
#include "game/character.h"
#include "util/util.h"
#include <iostream>
#include <format>

void Weapon::inspect() {
    std::string title = std::format("{} - {}\n", name, quality);
    std::cout << title;
    std::cout << util::repeat("-", title.length()) << '\n';
    std::cout << std::format("DMG {:>3}  CRT {:>3}", damage, crit);
    std::cout << util::repeat("-", title.length()) << '\n';
}