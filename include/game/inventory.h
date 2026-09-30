#pragma once
#include "item.h"
#include <vector>
#include <memory>

class Inventory {
public:
    void add_item(std::unique_ptr<Item> item);
    bool remove_item(Item* item_ptr);
    std::unique_ptr<Item> pop_item(Item* item_ptr);

    template <typename T>
    std::vector<T*> get_items() const {
        std::vector<T*> filtered;

        for (const auto& item : items) {
            T* derived = dynamic_cast<T*>(item.get());
            if (derived != nullptr) {
                filtered.push_back(derived);
            }
        }

        return filtered;
    }

    std::vector<Item*> get_all() const;

private:
    std::vector<std::unique_ptr<Item>> items;
};