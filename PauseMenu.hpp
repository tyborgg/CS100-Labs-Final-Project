#ifndef __PAUSEMENU_HPP__
#define __PAUSEMENU_HPP__

#include <iostream>
#include <sstream>
#include <fstream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include "opencv2\imgproc.hpp"
using namespace std;
using namespace cv;

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
        string outputMenu(int img);
        void resume();
        void save(int x, int y);
};

#endif