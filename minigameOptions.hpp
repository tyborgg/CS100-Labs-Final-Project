#ifndef __MINIGAME_OPTIONS_HPP__
#define __MINIGAME_OPTIONS_HPP__

#include "Minigame_Compositor.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include "opencv2\imgproc.hpp"
using namespace std;
using namespace cv;

class MinigameOptions {
    public:
        static MinigameOptions* instance;
        MinigameOptions() {};
        static MinigameOptions* getInstance();
        int userControl();
        string outputMenu(int img);

};

#endif
