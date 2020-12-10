#include "PauseMenu.hpp"

#include "minigameOptions.hpp"

#include <iostream>

int main() {
    PauseMenu* menu = menu->getInstance();
    menu->userControl();
    menu->save(1, 4);

    return 0;
}