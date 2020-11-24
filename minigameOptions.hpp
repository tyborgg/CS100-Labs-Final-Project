#ifndef __MINIGAME_OPTIONS__
#define __MINIGAME_OPTIONS__

#include "header/Minigame_Compositor.hpp"

class MinigameOptions{
    private:
    public:
        MinigameOptions(){};
        void getSelection(){
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
        };
};

#endif