#include "game/equipment.h"
#include "util/util.h"
#include <stdexcept>
#include <memory>
#include <string_view>

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

void Equipment::print() const {
    std::cout << util::header("Equipped", util::separator_size) << '\n';

    const auto print_slot = [](std::string_view slot, auto& item) {
        if (item) {
            if (auto* armour = util::as<Armour>(item)) {
                std::cout << std::format(
                    "{:<5} {:<10} [{:<9}] DEF {}\n",
                    slot, armour->name, armour->quality, armour->defence
                );
            } else {
                std::cout << std::format(
                    "{:<5} {:<10} [{:<9}]\n",
                    slot, item->name, item->quality
                );
            }

        } else {
            std::cout << std::format("{:<5} None DEF 0\n", slot);
        }
    };

    print_slot("HEAD", head);
    print_slot("BODY", body);
    print_slot("LEGS", legs);
    print_slot("FEET", feet);
    print_slot("HANDS", hands);
}

int Equipment::defence() const{
    int total = 0;

    if (head) 
        total += head->defence;

    if (body)
        total += body->defence;

    if (legs)
        total += legs->defence;

    if (feet)
        total += feet->defence;

    return total;
}