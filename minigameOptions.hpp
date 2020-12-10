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
    //public:
        static MinigameOptions* getInstance();
        int userControl();
        string outputMenu(int img);
        /*void getSelection() {
            Player* player = new Player();
            string choice = "";

            cout << "Would you like to play this minigame?" << endl;
            cin >> choice;

            Minigame_Compositor* mg = new Minigame_Compositor("play", player);
            //Minigame_Compositor* j = new Minigame_Compositor();
            mg->play(player);
            //mg->skip(player);

            //GameStrategy* gs = new GameStrategy(choice, player);
            //gs->display();
        };*/
};

#endif