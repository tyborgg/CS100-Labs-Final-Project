#include "PauseMenu.hpp"

#include "minigameOptions.hpp"

#include <iostream>

int main() {

    MinigameOptions* m = new MinigameOptions();
    cout << m->userControl() << endl;      //tests whether it returns the correct number
    m->userControl();

    return 0;
}
