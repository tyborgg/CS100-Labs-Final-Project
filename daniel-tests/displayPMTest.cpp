#include "PauseMenu.hpp"

#include "minigameOptions.hpp"

#include <iostream>

int main() {
    PauseMenu* menu = menu->getInstance();
    cout << menu->userControl() << endl;   //tests whether it returns the right number
    menu->userControl();

    return 0;
}
