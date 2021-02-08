# rpgProject

Just a little project i've been working on for a while.
Still active, but drown in shitcode

Level proceeds through main, battle level is levels[0], level switch request is described as levelResult.
<b>Object</b> is a class for map objects, <b>Character</b> is a class for battle stats and functions, therefore <b>Enemy</b> is a class for objects you can fight with.

Each level has a input method state, which is "INPUT_DEFAULT", "INPUT_HUD", "INPUT_NOINPUT".
With INPUT_HUD all input goes into HUD except stuff like window close button,
with INPUT_NOINPUT all input goes into nothing except some stuff/

GameCore is a divine objects, althougth it can be easily edited or expanded without bug problems. The only actual problem about is that the game is closely tied to the
target resolution ({640, 360} - like 640x480, but 16:9) so it's hard to change it and 16x16 sprites are quite small. And also i idk how to properly keep SFX and music
so i just load it all here. And, yeah, text system is nice and all, but all fonts are should be registered somewhere and you need to know their ID to use them, and
changing it will break all ID's.

HUD is the worst part of this code. I thought it's gonna be small, but it seems this game depends on it too much, so I had
to make a big interface and make it just like a whole sub-level and now it's insanely hard to edit and expand.
I would be glad if somebody will give some info about good HUD architecture in this situation, I don't think it's effective to use regular
windows-like system (keep many windows at once, one is focused and catches input) or state system (sometimes i show many menus at once, sometimes I don't).
Besides, player is supposed to do lots of things through the HUD (inventory / chest management, skill description / usage of heal, restore, etc, growth (not done yes)) so
sending requests to the level is not effective as well.

I'll describe all changes here

=== 08.02.2021 ===
Changed all HUD to dark, added SkillsFactory, removed all skill constructors from other code, got rid of BattleMessageBox (which was an outdated copy of MessageBox), added a proper beginBattle and beginBattleInstantly functions, changed weapon equip logic and weapon class, created a new demo map with battle on trigger, weapon with unique spells, secret route and battle on trigger.
