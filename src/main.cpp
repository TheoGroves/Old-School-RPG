#include "maths/maths.h"
#include "game/character.h"
#include <string>
#include <iostream>
#include <chrono>
#include <cstdint>

int main() {
    std::uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();

    maths::Random rand(seed);

    std::string name;

    //std::cout << "Enter character name: ";
    //std::cin >> name;

    for (int i = 0; i < 5; i++) {
        Character player(rand, std::to_string(i));
        player.generate_character();
        player.print();
    }

    return 0;
}

