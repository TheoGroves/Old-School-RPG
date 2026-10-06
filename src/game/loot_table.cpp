#include "game/loot_table.h"

std::unique_ptr<Item> LootTable::roll() {
    if (loot_registry.empty()) {
        return nullptr;
    }

    std::vector<float> weights;
    weights.reserve(loot_registry.size());

    for (const auto& entry : loot_registry) {
        weights.push_back(entry.weight);
    }

    std::vector<size_t> indices(loot_registry.size());
    for (size_t i = 0; i < loot_registry.size(); ++i) {
        indices[i] = i;
    }

    size_t chosen = rand.choice(indices, weights);

    return loot_registry[chosen].factory();
}