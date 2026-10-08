#include "game/location.h"
#include "util/util.h"
#include <iostream>
#include <format>
#include <algorithm>

std::string Location::get_display_name() const {
    return name;
}

void Location::display_connections() {
    util::print(util::header(get_display_name(), util::separator_size) + '\n');

    // Build vector of connection destinations + distances
    std::vector<std::string> connections_str;

    for (auto& conn : connections) {
        // Confirm destination exists before adding the string
        if (auto shared_dest = conn.destination.lock()) {
            connections_str.push_back(std::format("{} - {}km", shared_dest->name, conn.distance));
        }
    }

    util::display_vector(connections_str);

    util::print(util::separator(util::separator_size) + '\n');
}

void Location::connect(std::shared_ptr<Location> location, float distance) {
    connections.push_back({location, distance});
    location->connections.push_back({shared_from_this(), distance});
}

void Location::add_character(Character* character) {
    characters.push_back(character);
}

void Location::remove_character(Character* character) {
    std::erase(characters, character);
}