#include "item.h"
#include "maths/maths.h"
#include <vector>
#include <memory>
#include <unordered_map>
#include <functional>

class LootTable {
public:
    LootTable(maths::Random& rand)
        : rand(rand)
    {}

    template <typename Func>
    void add_item(Func&& func, float weight) {
        loot_registry.push_back({
            [f = std::forward<Func>(func)]() -> std::unique_ptr<Item> {
                return std::make_unique<decltype(f())>(f());
            },
            weight
        });
    };

    std::unique_ptr<Item> roll();

private:
    maths::Random& rand;

    struct LootEntry {
        std::function<std::unique_ptr<Item>()> factory;
        float weight;
    };

    std::vector<LootEntry> loot_registry;
};