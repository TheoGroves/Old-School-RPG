#include "game/inventory.h"
#include <algorithm>
#include <memory>
#include <unordered_set>

void Inventory::add_item(std::unique_ptr<Item>& item) {
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

std::vector<Item*> Inventory::get_all_unique() const {
    std::vector<Item*> all;
    std::unordered_set<std::string> seen_names;

    all.reserve(items.size());
    seen_names.reserve(items.size());

    for (const auto& item : items) {
        Item* item_ptr = item.get();

        if (seen_names.insert(item_ptr->name).second) {
            all.push_back(item_ptr);
        }
    }

    all.shrink_to_fit();

    return all;
}


// Remove item by name from inventory and return to user as unique_ptr, if doesn't exist return nullptr
std::unique_ptr<Item> Inventory::get_first(std::string_view name) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it) && (*it)->name == name) {
            std::unique_ptr<Item> found_item = std::move(*it);
            
            items.erase(it);
            
            return found_item;
        }
    }
    return nullptr;
}

// Remove item by ptr from inventory and return to user as unique_ptr, if doesn't exist return nullptr
std::unique_ptr<Item> Inventory::get_by_ptr(Item* item) {
    if (!item) return nullptr;

    auto it = std::find_if(items.begin(), items.end(), [item](const std::unique_ptr<Item>& ptr) {
        return ptr.get() == item;
    });

    if (it != items.end()) {
        std::unique_ptr<Item> found_item = std::move(*it);
        items.erase(it);
        return found_item;
    }

    return nullptr;
}
