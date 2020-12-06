#include "PauseMenu.cpp"
#include "minigameOptions.hpp"
#include "header/GameStrategy.hpp"
#include "header/Minigame_Compositor.hpp"
#include "header/mockPlayer.hpp"
#include "header/SkipStrategy.hpp"
#include "header/Minigame_Strategy.hpp"
#include <iostream>

int main() {
    PauseMenu* menu = menu->getInstance();
    menu->outputMenu();
    //menu->resume();

    //MinigameOptions* m = new MinigameOptions();
    //m->getSelection();

    //Player* player = new Player();
    //Minigame_Compositor* mc = new Minigame_Compositor("play", player);

    return 0;
}