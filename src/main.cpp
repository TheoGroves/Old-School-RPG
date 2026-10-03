#include "maths/maths.h"
#include "game/character.h"
#include <string>
#include <iostream>
#include <chrono>
#include <cstdint>

int main() {
    std::uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();

    maths::Random rand(seed);

    std::string name = "Test";

    //std::cout << "Enter character name: ";
    //std::cin >> name;

    Character player(rand, name, true);
    player.generate_character();
    player.give_xp(10000);
    player.print();

    return 0;
}

