#pragma once

#include "game/item.h"
#include "maths/maths.h"

class ItemDatabase {
public:
    ItemDatabase(maths::Random& rand)
        : rand(rand) 
    {}

    // Weapons
    Weapon iron_dagger();
    Weapon steel_dagger();
    Weapon gold_dagger();
    Weapon mythril_dagger();
    Weapon adamantite_dagger();

    Weapon wood_short_sword();
    Weapon iron_short_sword();
    Weapon steel_short_sword();
    Weapon gold_short_sword();
    Weapon mythril_short_sword();
    Weapon adamantite_short_sword();

    Weapon wood_long_sword();
    Weapon iron_long_sword();
    Weapon steel_long_sword();
    Weapon gold_long_sword();
    Weapon mythril_long_sword();
    Weapon adamantite_long_sword();

    Weapon wood_great_sword();
    Weapon iron_great_sword();
    Weapon steel_great_sword();
    Weapon gold_great_sword();
    Weapon mythril_great_sword();
    Weapon adamantite_great_sword();

    Weapon wood_axe();
    Weapon iron_axe();
    Weapon steel_axe();
    Weapon gold_axe();
    Weapon mythril_axe();
    Weapon adamantite_axe();

    Weapon iron_mace();
    Weapon steel_mace();
    Weapon gold_mace();
    Weapon mythril_mace();
    Weapon adamantite_mace();

    Weapon wood_warhammer();
    Weapon iron_warhammer();
    Weapon steel_warhammer();
    Weapon gold_warhammer();
    Weapon mythril_warhammer();
    Weapon adamantite_warhammer();

    Weapon iron_spear();
    Weapon steel_spear();
    Weapon gold_spear();
    Weapon mythril_spear();
    Weapon adamantite_spear();

    Weapon iron_halberd();
    Weapon steel_halberd();
    Weapon gold_halberd();
    Weapon mythril_halberd();
    Weapon adamantite_halberd();

    Weapon short_bow();
    Weapon long_bow();

    // Armour
    Armour leather_hat();
    Armour leather_doublet();
    Armour leather_trousers();
    Armour leather_shoes();

    Armour linen_hat();
    Armour linen_robes();
    Armour linen_tunic();
    Armour linen_trousers();

    Armour wool_hat();
    Armour wool_robes();
    Armour wool_tunic();
    Armour wool_trousers();

    Armour silk_hat();
    Armour silk_robes();
    Armour silk_tunic();
    Armour silk_trousers();

    Armour satin_hat();
    Armour satin_robes();
    Armour satin_tunic();
    Armour satin_trousers();

    Armour runesilk_hat();
    Armour runesilk_robes();
    Armour runesilk_trousers();
    Armour runesilk_boots();

    Armour moonthread_hat();
    Armour moonthread_robes();
    Armour moonthread_trousers();
    Armour moonthread_boots();

    Armour manaweave_hat();
    Armour manaweave_robes();
    Armour manaweave_trousers();
    Armour manaweave_boots();

    Armour aethercloth_hat();
    Armour aethercloth_robes();
    Armour aethercloth_trousers();
    Armour aethercloth_boots();

    Armour voidcloth_hat();
    Armour voidcloth_robes();
    Armour voidcloth_trousers();
    Armour voidcloth_boots();

    Armour iron_helmet();
    Armour iron_breastplate();
    Armour iron_leggings();
    Armour iron_greaves();

    Armour steel_helmet();
    Armour steel_breastplate();
    Armour steel_leggings();
    Armour steel_greaves();

    Armour gold_helmet();
    Armour gold_breastplate();
    Armour gold_leggings();
    Armour gold_greaves();

    Armour mythril_helmet();
    Armour mythril_breastplate();
    Armour mythril_leggings();
    Armour mythril_greaves();
    
    Armour adamantite_helmet();
    Armour adamantite_breastplate();
    Armour adamantite_leggings();
    Armour adamantite_greaves();
private:
    maths::Random& rand;
};