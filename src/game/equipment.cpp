#include "game/equipment.h"
#include "util/util.h"
#include <stdexcept>
#include <memory>

constexpr int header_width = 20;

void Equipment::equip(ItemSlot slot, std::unique_ptr<Item> item) {
    switch (slot) {
        case ItemSlot::head:
            head = move_item<Armour>(std::move(item));
            break;

        case ItemSlot::body:
            body = move_item<Armour>(std::move(item));
            break;

        case ItemSlot::legs:
            legs = move_item<Armour>(std::move(item));
            break;

        case ItemSlot::feet:
            feet = move_item<Armour>(std::move(item));
            break;

        case ItemSlot::hands:
            hands = std::move(item);
            break;
        
        default:
            throw std::runtime_error("Unhandled Item Slot selected.");
    }
}

void Equipment::print() {
    std::cout << util::header("Equipped", header_width) << '\n';
    if (head != nullptr) {
        std::cout << std::format("HEAD {:<10} [{:<9}] DEF {}\n", head->name, head->quality, head->defence);
    } else {
        std::cout << "HEAD None DEF 0\n";
    }
    if (body != nullptr) {
        std::cout << std::format("BODY {:<10} [{:<9}] DEF {}\n", body->name, head->quality, body->defence);
    } else {
        std::cout << "BODY None DEF 0\n";
    }
    if (legs != nullptr) {
        std::cout << std::format("LEGS {:<10} [{:<9}] DEF {}\n", legs->name, legs->quality, legs->defence);
    } else {
        std::cout << "LEGS None DEF 0\n";
    }
    if (feet != nullptr) {
        std::cout << std::format("FEET {:<10} [{:<9}] DEF {}\n", feet->name, feet->quality, feet->defence);
    } else {
        std::cout << "FEET None DEF 0\n";
    }
}