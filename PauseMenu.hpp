#ifndef __PAUSEMENU_HPP__
#define __PAUSEMENU_HPP__

#include <iostream>
using namespace std;

//utilize the singleton pattern
class PauseMenu
{
    private:
        static PauseMenu* instance;
        //private constructor
        PauseMenu(){};
        //~PauseMenu();
    public:
        static PauseMenu* getInstance();
        int userControl();
        void outputMenu();
        void resume();
        void save(int x, int y);
        void exit();
};

#endif