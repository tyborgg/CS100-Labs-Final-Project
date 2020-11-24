#include "SetupMaze.hpp"

SetupMaze* SetupMaze::instance = nullptr;

SetupMaze* SetupMaze::getInstance(){
    if (instance == nullptr){
        instance = new SetupMaze();
    }
    return instance;
}