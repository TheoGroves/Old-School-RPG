#include "maths/maths.h"
#include "game/character.h"
#include "game/item_database.h"
#include <string>
#include <iostream>
#include <chrono>
#include <cstdint>

int main() {
    std::uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();

    maths::Random rand(seed);

    std::string name = "Test";

    ItemDatabase idb = ItemDatabase(rand);

    //std::cout << "Enter character name: ";
    //std::cin >> name;

    Character player(rand, name, true);
    player.generate_character();
    player.give_xp(500);
    player.print();

    return 0;
}

