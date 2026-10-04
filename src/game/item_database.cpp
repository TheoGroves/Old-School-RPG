#include "game/item_database.h"

Weapon ItemDatabase::iron_dagger() { return Weapon(rand, "Iron Dagger", "The ol' reliable.", 25, false, 5, 1.5, WeaponType::short_blade); }
Weapon ItemDatabase::steel_dagger() { return Weapon(rand, "Steel Dagger", "A little more expensive, a little better for stabbing.", 40, false, 7, 1.5, WeaponType::short_blade); }
Weapon ItemDatabase::gold_dagger() { return Weapon(rand, "Gold Dagger", "Flashy but weak. Great for stabbing in style.", 150, true, 8, 1.5, WeaponType::short_blade); }
Weapon ItemDatabase::mythril_dagger() { return Weapon(rand, "Mythril Dagger", "You can feel the magical energy pulsating through it. Light and very sharp.", 300, true, 12, 1.5, WeaponType::short_blade); }
Weapon ItemDatabase::adamantite_dagger() { return Weapon(rand, "Adamantite Dagger", "Razor-sharp and sturdy but might be a little over the top.", 450, false, 18, 1.8, WeaponType::short_blade); }

Weapon ItemDatabase::wood_short_sword() { return Weapon(rand, "Wooden Short Sword", "It's a sword. Just about.", 40, false, 7, 1.5, WeaponType::short_blade); }
Weapon ItemDatabase::iron_short_sword() { return Weapon(rand, "Iron Short Sword", "A perfect beginner's sword. Great at just about anything you want from a short sword.", 75, false, 10, 1.5, WeaponType::short_blade); }
Weapon ItemDatabase::steel_short_sword() { return Weapon(rand, "Steel Short Sword", "Iron but better.", 90, false, 13, 1.5, WeaponType::short_blade); }
Weapon ItemDatabase::gold_short_sword() { return Weapon(rand, "Gold Short Sword", "Because I want to spend all my silver.", 250, true, 14, 1.5, WeaponType::short_blade); }
Weapon ItemDatabase::mythril_short_sword() { return Weapon(rand, "Mythril Short Sword", "Light, sharp and pulsing with magical energy.", 500, true, 15, 1.5, WeaponType::short_blade); }
Weapon ItemDatabase::adamantite_short_sword() { return Weapon(rand, "Adamantite Short Sword", "Apparently, size really doesn't matter.", 750, false, 22, 1.7, WeaponType::short_blade); }

Weapon ItemDatabase::wood_long_sword() { return Weapon(rand, "Wooden Long Sword", "Essentially a big long stick.", 70, false, 10, 1.6, WeaponType::long_blade); }
Weapon ItemDatabase::iron_long_sword() { return Weapon(rand, "Iron Long Sword", "A classic adventurer's choice.", 120, false, 15, 1.6, WeaponType::long_blade); }
Weapon ItemDatabase::steel_long_sword() { return Weapon(rand, "Steel Long Sword", "Sharp, long and reliable.", 150, false, 17, 1.6, WeaponType::long_blade); }
Weapon ItemDatabase::gold_long_sword() { return Weapon(rand, "Gold Long Sword", "A sword made of money.", 500, true, 18, 1.6, WeaponType::long_blade); }
Weapon ItemDatabase::mythril_long_sword() { return Weapon(rand, "Mythril Long Sword", "Long and lethal. If you put your ear up to it you can hear the magical vibrations.", 1000, true, 20, 1.6, WeaponType::long_blade); }
Weapon ItemDatabase::adamantite_long_sword() { return Weapon(rand, "Adamantite Long Sword", "One of the best you can buy.", 1500, false, 25, 1.9, WeaponType::long_blade); }

Weapon ItemDatabase::wood_great_sword() { return Weapon(rand, "Wooden Great Sword", "Why did you buy this?", 120, false, 12, 1.7, WeaponType::long_blade); }
Weapon ItemDatabase::iron_great_sword() { return Weapon(rand, "Iron Great Sword", "When nothing is ever big enough.", 250, false, 20, 1.7, WeaponType::long_blade); }
Weapon ItemDatabase::steel_great_sword() { return Weapon(rand, "Steel Great Sword", "Bigger and better.", 300, false, 25, 1.6, WeaponType::long_blade); }
Weapon ItemDatabase::gold_great_sword() { return Weapon(rand, "Gold Great Sword", "The blacksmith offered to take you back to his place to try out his 'sword' after purchasing this.", 1000, true, 23, 1.7, WeaponType::long_blade); }
Weapon ItemDatabase::mythril_great_sword() { return Weapon(rand, "Mythril Great Sword", "Surprisingly light for a sword of its size.", 2500, true, 35, 1.7, WeaponType::long_blade); }
Weapon ItemDatabase::adamantite_great_sword() { return Weapon(rand, "Adamantite Great Sword", "If it won't go down with this, get the hell outta there.", 3500, false, 45, 2.1, WeaponType::long_blade); }

Weapon ItemDatabase::wood_axe() { return Weapon(rand, "Wooden Axe", "It's an axe. Made of wood. I have a feeling this won't work.", 30, false, 5, 2.0, WeaponType::axe); }
Weapon ItemDatabase::iron_axe() { return Weapon(rand, "Iron Axe", "Great for trees, even better on a goblin.", 80, false, 12, 2.0, WeaponType::axe); }
Weapon ItemDatabase::steel_axe() { return Weapon(rand, "Steel Axe", "Chop with confidence.", 110, false, 15, 2.0, WeaponType::axe); }
Weapon ItemDatabase::gold_axe() { return Weapon(rand, "Gold Axe", "You're gonna impress that tree with this thing.", 300, true, 17, 2.0, WeaponType::axe); }
Weapon ItemDatabase::mythril_axe() { return Weapon(rand, "Mythril Axe", "Swinging with speed and knocking down anything in its path.", 650, true, 20, 2.0, WeaponType::axe); }
Weapon ItemDatabase::adamantite_axe() { return Weapon(rand, "Adamantite Axe", "This'll scare those trees. Pretty good against enemies too.", 950, false, 25, 2.5, WeaponType::axe); }

Weapon ItemDatabase::iron_mace() { return Weapon(rand, "Iron Mace", "When you don't care about subtlety.", 80, false, 20, 1.3, WeaponType::short_blunt); }
Weapon ItemDatabase::steel_mace() { return Weapon(rand, "Steel Mace", "Good at caving skulls in.", 105, false, 23, 1.3, WeaponType::short_blunt); }
Weapon ItemDatabase::gold_mace() { return Weapon(rand, "Gold Mace", "Expensive blunt force trauma.", 350, true, 24, 1.3, WeaponType::short_blunt); }
Weapon ItemDatabase::mythril_mace() { return Weapon(rand, "Mythril Mace", "Magically increases the power of your swing.", 800, true, 30, 1.3, WeaponType::short_blunt); }
Weapon ItemDatabase::adamantite_mace() { return Weapon(rand, "Adamantite Mace", "Strength doesn't matter when you're wielding this.", 1200, false, 40, 1.6, WeaponType::short_blunt); }

Weapon ItemDatabase::wood_warhammer() { return Weapon(rand, "Wooden Warhammer", "Basically just a hammer.", 70, false, 15, 1.5, WeaponType::long_blunt); }
Weapon ItemDatabase::iron_warhammer() { return Weapon(rand, "Iron Warhammer", "A big iron block on a stick.", 150, false, 25, 1.5, WeaponType::long_blunt); }
Weapon ItemDatabase::steel_warhammer() { return Weapon(rand, "Steel Warhammer", "Smack em' silly.", 200, false, 27, 1.5, WeaponType::long_blunt); }
Weapon ItemDatabase::gold_warhammer() { return Weapon(rand, "Gold Warhammer", "Both a weapon and a waste of your silver.", 700, true, 30, 1.5, WeaponType::long_blunt); }
Weapon ItemDatabase::mythril_warhammer() { return Weapon(rand, "Mythril Warhammer", "Heavy enough to hurt, yet magically light enough to swing at great speeds.", 1750, true, 35, 1.5, WeaponType::long_blunt); }
Weapon ItemDatabase::adamantite_warhammer() { return Weapon(rand, "Adamantite Warhammer", "Strike fear into the hearts of your enemies.", 2500, false, 45, 1.8, WeaponType::long_blunt); }

Weapon ItemDatabase::iron_spear() { return Weapon(rand, "Iron Spear", "A pointy stick.", 110, false, 15, 1.6, WeaponType::spear); }
Weapon ItemDatabase::steel_spear() { return Weapon(rand, "Steel Spear", "A pointier stick.", 150, false, 17, 1.6, WeaponType::spear); }
Weapon ItemDatabase::gold_spear() { return Weapon(rand, "Gold Spear", "Stabbing from a safe distance.", 375, true, 18, 1.6, WeaponType::spear); }
Weapon ItemDatabase::mythril_spear() { return Weapon(rand, "Mythril Spear", "Long, unpleasant and terrifying.", 750, true, 25, 1.6, WeaponType::spear); }
Weapon ItemDatabase::adamantite_spear() { return Weapon(rand, "Adamantite Spear", "I wouldn't recommend getting close to this one.", 1200, false, 30, 1.8, WeaponType::spear); }

Weapon ItemDatabase::iron_halberd() { return Weapon(rand, "Iron Halberd", "The love child of a spear and an axe.", 150, false, 15, 2.0, WeaponType::spear); }
Weapon ItemDatabase::steel_halberd() { return Weapon(rand, "Steel Halberd", "It has an alarming number of sharp edges.", 200, false, 20, 2.0, WeaponType::spear); }
Weapon ItemDatabase::gold_halberd() { return Weapon(rand, "Gold Halberd", "The expensive solution to all your combat problems.", 600, true, 22, 2.0, WeaponType::spear); }
Weapon ItemDatabase::mythril_halberd() { return Weapon(rand, "Mythril Halberd", "Far too many weapons on one stick.", 1500, true, 27, 2.0, WeaponType::spear); }
Weapon ItemDatabase::adamantite_halberd() { return Weapon(rand, "Adamantite Halberd", "The most terrifying stick an orc has ever laid eyes on.", 2500, false, 35, 2.5, WeaponType::spear); }

Weapon ItemDatabase::short_bow() { return Weapon(rand, "Short Bow", "Great at taking your arrows from point A to point B, provided point B isn't too far away.", 300, true, 25, 1.5, WeaponType::archery); }
Weapon ItemDatabase::long_bow() { return Weapon(rand, "Long Bow", "Bigger and much more powerful but harder to aim.", 800, true, 15, 5.0, WeaponType::archery); }

// Armour
Armour ItemDatabase::leather_hat() { return Armour(rand, "Leather Hat", "You look a little like a cowboy.", 20, false, 5, Slot::head); }
Armour ItemDatabase::leather_doublet() { return Armour(rand, "Leather Doublet", "I mean technically it's armour.", 50, false, 7, Slot::body); }
Armour ItemDatabase::leather_trousers() { return Armour(rand, "Leather Trousers", "Don't forget protection.", 30, false, 4, Slot::legs); }
Armour ItemDatabase::leather_shoes() { return Armour(rand, "Leather Shoes", "Protects your feet from those sharp, sharp rocks.", 25, false, 3, Slot::feet); }

Armour ItemDatabase::linen_hat() { return Armour(rand, "Linen Hat", "Fashionable and flammable.", 15, false, 3, Slot::head); }
Armour ItemDatabase::linen_robes() { return Armour(rand, "Linen Robes", "For looking like a wizard on a budget.", 40, false, 5, Slot::body); }
Armour ItemDatabase::linen_tunic() { return Armour(rand, "Linen Tunic", "Comfortable. Not very protective.", 30, false, 4, Slot::body); }
Armour ItemDatabase::linen_trousers() { return Armour(rand, "Linen Trousers", "Keep it in your pants.", 25, false, 2, Slot::legs); }

Armour ItemDatabase::wool_hat() { return Armour(rand, "Wool Hat", "You keep finding bits of fluff in your hair.", 25, false, 4, Slot::head); }
Armour ItemDatabase::wool_robes() { return Armour(rand, "Wool Robes", "Excellent for the cold. Not so much for orcs with axes.", 75, false, 6, Slot::body); }
Armour ItemDatabase::wool_tunic() { return Armour(rand, "Wool Tunic", "Nice and cozy.", 45, false, 5, Slot::body); }
Armour ItemDatabase::wool_trousers() { return Armour(rand, "Wool Trousers", "Great at keeping your legs warm.", 30, false, 2, Slot::legs); }

Armour ItemDatabase::silk_hat() { return Armour(rand, "Silk Hat", "+5 style or something.", 60, false, 2, Slot::head); }
Armour ItemDatabase::silk_robes() { return Armour(rand, "Silk Robes", "Get a load of Mr Fancy over here.", 120, false, 4, Slot::body); }
Armour ItemDatabase::silk_tunic() { return Armour(rand, "Silk Tunic", "Soft enough that you might just forget the silver you wasted on it.", 90, false, 3, Slot::body); }
Armour ItemDatabase::silk_trousers() { return Armour(rand, "Silk Trousers", "Comfy yet somewhat impractical.", 75, false, 1, Slot::legs); }

Armour ItemDatabase::satin_hat() { return Armour(rand, "Satin Hat", "+10 style or something.", 80, false, 1, Slot::head); }
Armour ItemDatabase::satin_robes() { return Armour(rand, "Satin Robes", "Excellent for those trying to look like royalty.", 200, false, 3, Slot::body); }
Armour ItemDatabase::satin_tunic() { return Armour(rand, "Satin Tunic", "For those who refuse to appear poor.", 150, false, 2, Slot::body); }
Armour ItemDatabase::satin_trousers() { return Armour(rand, "Satin Trousers", "Your enemies will die knowing you looked incredible.", 100, false, 1, Slot::legs); }

Armour ItemDatabase::runesilk_hat() { return Armour(rand, "Runesilk Hat", "Finally, a hat that's actually cool.", 225, true, 6, Slot::head); }
Armour ItemDatabase::runesilk_robes() { return Armour(rand, "Runesilk Robes", "Robes that seem to shift and flow in the light.", 400, true, 8, Slot::body); }
Armour ItemDatabase::runesilk_trousers() { return Armour(rand, "Runesilk Trousers", "Trousers... but magic?", 300, true, 7, Slot::legs); }
Armour ItemDatabase::runesilk_boots() { return Armour(rand, "Runesilk Boots", "Enchanted boots, what could go wrong?", 275, true, 3, Slot::feet); }

Armour ItemDatabase::moonthread_hat() { return Armour(rand, "Moonthread Hat", "Woven from threads imbued with the essence of moonlight.", 400, true, 7, Slot::head); }
Armour ItemDatabase::moonthread_robes() { return Armour(rand, "Moonthread Robes", "All the other mages at the tavern will be jealous of you.", 850, true, 9, Slot::body); }
Armour ItemDatabase::moonthread_trousers() { return Armour(rand, "Moonthread Trousers", "Your trousers glow a soft blue at night.", 650, true, 8, Slot::legs); }
Armour ItemDatabase::moonthread_boots() { return Armour(rand, "Moonthread Boots", "Walk like you're floating. Probably because you are.", 500, true, 4, Slot::feet); }

Armour ItemDatabase::manaweave_hat() { return Armour(rand, "Manaweave Hat", "Just about magical enough to justify the price.", 700, true, 8, Slot::head); }
Armour ItemDatabase::manaweave_robes() { return Armour(rand, "Manaweave Robes", "These robes just emanate power.", 1400, true, 10, Slot::body); }
Armour ItemDatabase::manaweave_trousers() { return Armour(rand, "Manaweave Trousers", "You have magical legs now.", 1000, true, 9, Slot::legs); }
Armour ItemDatabase::manaweave_boots() { return Armour(rand, "Manaweave Boots", "A lightweight pair of boots created from mana-infused threads.", 850, true, 5, Slot::feet); }

Armour ItemDatabase::aethercloth_hat() { return Armour(rand, "Aethercloth Hat", "A hat woven from matter found in the heavens above.", 1000, true, 9, Slot::head); }
Armour ItemDatabase::aethercloth_robes() { return Armour(rand, "Aethercloth Robes", "Flowing fabric that glows in the sun.", 2250, true, 11, Slot::body); }
Armour ItemDatabase::aethercloth_trousers() { return Armour(rand, "Aethercloth Trousers", "Apparently heaven-made trousers are pretty good.", 1500, true, 10, Slot::legs); }
Armour ItemDatabase::aethercloth_boots() { return Armour(rand, "Aethercloth Boots", "These boots let you float as you run, making long journeys surprisingly effortless.", 1300, true, 6, Slot::feet); }

Armour ItemDatabase::voidcloth_hat() { return Armour(rand, "Voidcloth Hat", "The hat reflects light outside of the visible spectrum leading to it appearing completely black.", 2500, true, 10, Slot::head); }
Armour ItemDatabase::voidcloth_robes() { return Armour(rand, "Voidcloth Robes", "Made from fabric grown in secret by the greatest necromancers of this plane. Pulsating with evil energy.", 4500, true, 13, Slot::body); }
Armour ItemDatabase::voidcloth_trousers() { return Armour(rand, "Voidcloth Trousers", "Woven from threads that seem to have been pulled from the fabric of the void itself.", 3500, true, 12, Slot::legs); }
Armour ItemDatabase::voidcloth_boots() { return Armour(rand, "Voidcloth Boots", "Your footsteps make no sound when wearing these boots... neither does your silver bag.", 2225, true, 7, Slot::feet); }

Armour ItemDatabase::iron_helmet() { return Armour(rand, "Iron Helmet", "The typical helmet of a warrior. Protects your head from most hits.", 100, false, 10, Slot::head); }
Armour ItemDatabase::iron_breastplate() { return Armour(rand, "Iron Breastplate", "Heavy, reliable and difficult to sleep in.", 250, false, 15, Slot::body); }
Armour ItemDatabase::iron_leggings() { return Armour(rand, "Iron Leggings", "Walking has never been this difficult.", 180, false, 13, Slot::legs); }
Armour ItemDatabase::iron_greaves() { return Armour(rand, "Iron Greaves", "You need to protect your feet too you know.", 120, false, 10, Slot::feet); }

Armour ItemDatabase::steel_helmet() { return Armour(rand, "Steel Helmet", "Just like iron but minorly better.", 150, false, 12, Slot::head); }
Armour ItemDatabase::steel_breastplate() { return Armour(rand, "Steel Breastplate", "Heavy but strong enough to prevent swords from penetrating you.", 350, false, 17, Slot::body); }
Armour ItemDatabase::steel_leggings() { return Armour(rand, "Steel Leggings", "Your legs weigh significantly more now.", 275, false, 16, Slot::legs); }
Armour ItemDatabase::steel_greaves() { return Armour(rand, "Steel Greaves", "Shin protection for the serious explorer.", 175, false, 10, Slot::feet); }

Armour ItemDatabase::gold_helmet() { return Armour(rand, "Gold Helmet", "At least you'll look great as your skull gets caved in.", 400, true, 8, Slot::head); }
Armour ItemDatabase::gold_breastplate() { return Armour(rand, "Gold Breastplate", "The heaviest and most over the top breastplate you'll ever own.", 900, true, 13, Slot::body); }
Armour ItemDatabase::gold_leggings() { return Armour(rand, "Gold Leggings", "Now what are you compensating for?", 700, true, 10, Slot::legs); }
Armour ItemDatabase::gold_greaves() { return Armour(rand, "Gold Greaves", "Your feet are now more expensive than most people's homes.", 500, true, 6, Slot::feet); }

Armour ItemDatabase::mythril_helmet() { return Armour(rand, "Mythril Helmet", "This helmet is strong, light and helps channel your magical abilities.", 900, true, 15, Slot::head); }
Armour ItemDatabase::mythril_breastplate() { return Armour(rand, "Mythril Breastplate", "You can feel the magic coursing through you.", 1700, true, 20, Slot::body); }
Armour ItemDatabase::mythril_leggings() { return Armour(rand, "Mythril Leggings", "Smooth and strong, these leggings don't affect your movement much.", 1350, true, 18, Slot::legs); }
Armour ItemDatabase::mythril_greaves() { return Armour(rand, "Mythril Greaves", "The smoothest greaves you have ever felt, these protect well and don't limit movement.", 1000, true, 14, Slot::feet); }

Armour ItemDatabase::adamantite_helmet() { return Armour(rand, "Adamantite Helmet", "The most expensive helmet you'll ever own.", 1350, false, 25, Slot::head); }
Armour ItemDatabase::adamantite_breastplate() { return Armour(rand, "Adamantite Breastplate", "If this fails to protect you, you'd be better off praying to the gods.", 2750, false, 32, Slot::body); }
Armour ItemDatabase::adamantite_leggings() { return Armour(rand, "Adamantite Leggings", "Your legs are now essentially a fortress.", 2250, false, 28, Slot::legs); }
Armour ItemDatabase::adamantite_greaves() { return Armour(rand, "Adamantite Greaves", "Your feet have never felt safer.", 1800, false, 20, Slot::feet); }