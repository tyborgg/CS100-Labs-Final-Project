#include "PauseMenu.hpp"

#include "minigameOptions.hpp"

#include <iostream>

int main() {
    //PauseMenu* menu = menu->getInstance();
    //menu->userControl();
    //menu->outputMenu();
    //menu->resume();
    //menu->save(1, 4);

    MinigameOptions* m = new MinigameOptions();
    m->userControl();

    //Player* player = new Player();
    //Minigame_Compositor* mc = new Minigame_Compositor("play", player);

    return 0;
}