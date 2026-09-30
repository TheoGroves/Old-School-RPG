#include "game/inventory.h"
#include <algorithm>
#include <memory>

void Inventory::add_item(std::unique_ptr<Item> item) {
    if (item) {
        items.push_back(std::move(item));
    }
}

bool Inventory::remove_item(Item* item_ptr) {
    if (!item_ptr) return false;

    auto it = std::find_if(items.begin(), items.end(), 
        [item_ptr](const std::unique_ptr<Item>& item) {
            return item.get() == item_ptr;
        });

    if (it != items.end()) {
        items.erase(it);
        return true;
    }

    return false;
}

std::unique_ptr<Item> Inventory::pop_item(Item* item_ptr) {
    if (!item_ptr) return nullptr;

    auto it = std::find_if(items.begin(), items.end(), 
        [item_ptr](const std::unique_ptr<Item>& item) {
            return item.get() == item_ptr;
        });

    if (it != items.end()) {
        std::unique_ptr<Item> extracted_item = std::move(*it);

        items.erase(it);

        return extracted_item;
    }

    return nullptr;
}

std::vector<Item*> Inventory::get_all() const {
    std::vector<Item*> all;
    all.reserve(items.size());

    for (const auto& item : items) {
        all.push_back(item.get());
    }

    return all;
}