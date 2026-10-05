#pragma once
#include "item.h"
#include <vector>
#include <memory>
#include <string_view>

class Inventory {
public:
    void add_item(std::unique_ptr<Item>& item);
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
    std::vector<Item*> get_all_unique() const;

    std::unique_ptr<Item> get_first(std::string_view name);
    std::unique_ptr<Item> get_by_ptr(Item* item);

private:
    std::vector<std::unique_ptr<Item>> items;
};