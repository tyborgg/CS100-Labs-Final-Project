#include "PauseMenu.hpp"

#include "minigameOptions.hpp"

#include <iostream>

int main() {
    PauseMenu* menu = menu->getInstance();
    menu->userControl();
    menu->resume();

    return 0;
}