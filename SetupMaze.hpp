#ifndef __SETUPMAZE_HPP__
#define __SETUPMAZE_HPP__

#include <iostream>
using namespace std;

//utilize the singleton pattern
class SetupMaze
{
    private:
        static SetupMaze* instance;
        //private constructor
        SetupMaze(){};
    public:
        static SetupMaze* getInstance();
};

#endif