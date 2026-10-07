#include "maths/maths.h"
#include "game/character.h"
#include "game/item_database.h"
#include "game/loot_table.h"
#include "util/util.h"
#include <string>
#include <iostream>
#include <chrono>
#include <cstdint>

int main() {
    std::uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();

    maths::Random rand(seed);

    std::string name = "Test";

    ItemDatabase idb(rand);

    LootTable table(rand);
    table.add_item([&]() { return idb.wood_short_sword(); }, 0.5f);
    table.add_item([&]() { return idb.wood_long_sword(); }, 0.5f);
    table.add_item([&]() { return idb.wood_axe(); }, 0.5f);
    table.add_item([&]() { return idb.wood_warhammer(); }, 0.5f);

    //std::cout << "Enter character name: ";
    //std::cin >> name;

    Character player(rand, name, true);
    player.generate_character();
    //player.give_xp(500);
    player.give_item(table.roll());
    player.give_item(table.roll());
    player.give_item(table.roll());
    player.give_item(table.roll());

    std::vector<std::string> choices = {"Use Item", "Inspect Self", "Exit"};

    while (true) {
        util::display_vector(choices);
        int choice = util::prompt("What do you want to do", 1, static_cast<int>(choices.size()));

        if (choice == 1) {
            auto item = player.choose_item();
            player.use_item(item);
        }
        else if (choice == 2) {
            player.print();
        }
        else if (choice == 3) {
            break;
        }
    }

    return 0;
}

