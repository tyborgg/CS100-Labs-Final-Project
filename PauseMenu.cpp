#include "PauseMenu.hpp"

PauseMenu* PauseMenu::instance = nullptr;

PauseMenu* PauseMenu::getInstance(){
    if (instance == nullptr){
        instance = new PauseMenu();
    }
    return instance;
}

int PauseMenu::userControl(){
    cout << "Enter your user controls: " << "\n";

    string up;
    string down;

    cout << "To choose above option: ";
    cin >> up;
    cout << "\n";

    cout << "To choose below option: ";
    cin >> up;
    cout << "\n";
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

void PauseMenu::resume(){
    //resume the game
    //exit the pause menu
}

void PauseMenu::save(int x, int y){
    /*read in coordinates
    set x and y to the coordinates
    create text file to save the coordinates to*/
}

void PauseMenu::exit(){
    /*if user selects exit
    exit the game
    return to start menu*/
}

