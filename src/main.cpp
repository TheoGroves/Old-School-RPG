#include "maths/maths.h"
#include "game/character.h"
#include "game/item_database.h"
#include "game/loot_table.h"
#include "game/location.h"
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

    std::shared_ptr<Location> test_town = std::make_shared<Location>(Location("Test Town"));
    std::shared_ptr<Location> west_town = std::make_shared<Location>(Location("West Town"));
    std::shared_ptr<Location> east_town = std::make_shared<Location>(Location("East Town"));

    test_town->connect(west_town, 5.0);
    test_town->connect(east_town, 10.0);

    //util::print("Enter character name: ");
    //std::cin >> name;

    Character player(rand, name, true);
    player.generate_character();
    player.set_location(test_town.get());
    //player.give_xp(500);
    player.give_item(table.roll());
    player.give_item(table.roll());
    player.give_item(table.roll());
    player.give_item(table.roll());

    Character npc(rand, "Test Character", false);
    npc.generate_character();
    npc.set_location(test_town.get());

    test_town->display_connections();

    std::vector<std::string> choices = {"Use Item in Hands", "Open Inventory", "Inspect Self", "Open Equipment", "Exit"};

    while (true) {
        util::display_vector(choices);
        int choice = util::prompt("What do you want to do", 1, static_cast<int>(choices.size()));

        if (choice == 1) {
            if (!player.equipment.hands)
                util::print("You aren't holding anything.\n");
                continue;

            std::unique_ptr<Item> item = std::move(player.equipment.hands);
            player.use_item(item, true);
        }
        else if (choice == 2) {
            auto item = player.choose_item();
            player.use_item(item);
        }
        else if (choice == 3) {
            player.print();
        }
        else if (choice == 4) {
            player.open_equipment();
        }
        else if (choice == 5) {
            break;
        }
    }

    return 0;
}

