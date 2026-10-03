#pragma once
#include "item.h"
#include <memory>
#include <format>
#include <iostream>

template <typename T>
static std::unique_ptr<T> move_item(std::unique_ptr<Item> item) {
    T* raw = dynamic_cast<T*>(item.get());
    if (raw == nullptr) {
        std::cerr << "Error: Cannot convert Item to target type.\n";
        return nullptr;
    }

    item.release();

    return std::unique_ptr<T>(raw);
}

enum class ItemSlot {
    // Gear
    head,
    body,
    legs,
    feet,

    hands
};

class Equipment {
public:
    void equip(ItemSlot slot, std::unique_ptr<Item> item);
    void print() const;

    int defence() const;
private:
    std::unique_ptr<Armour> head = nullptr;
    std::unique_ptr<Armour> body = nullptr;
    std::unique_ptr<Armour> legs = nullptr;
    std::unique_ptr<Armour> feet = nullptr;

    std::unique_ptr<Item> hands = nullptr;
};