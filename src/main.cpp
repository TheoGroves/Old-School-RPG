#include "maths/maths.h"
#include "game/character.h"
#include <string>
#include <iostream>

int main() {
    maths::Random rand(0);

    std::string name;

    std::cout << "Enter character name: ";
    std::cin >> name;

    Character player(rand, name);
    player.generate_character();

    player.print();

    return 0;
}

