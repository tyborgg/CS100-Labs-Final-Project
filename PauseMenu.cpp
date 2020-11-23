#include "PauseMenu.hpp"

PauseMenu* PauseMenu::instance = nullptr;

PauseMenu* PauseMenu::getInstance(){
    if (instance == nullptr){
        instance = new PauseMenu();
    }
    return instance;
}