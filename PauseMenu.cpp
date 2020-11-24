#include "PauseMenu.hpp"

PauseMenu* PauseMenu::instance = nullptr;

PauseMenu* PauseMenu::getInstance(){
    if (instance == nullptr){
        instance = new PauseMenu();
    }
    return instance;
}

void PauseMenu::outputMenu(){
    cout << "PAUSED" << endl;

    cout << "Select an option: " << "\n" << "s - save" << "\n" << "q - exit menu" << endl;
    
    /*string selection = "";
    cin >> selection;
    if(selection == "s"){
        save();
    }*/
}

