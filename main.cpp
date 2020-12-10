#include <iostream>		
#include <string>
#include <sstream>
#include "start.hpp"
#include "maze.hpp"
#include "PauseMenu.hpp"
#include "minigameOptions.hpp"
#include "Minigame_Compositor.hpp"
#include "mockPlayer.hpp"

using namespace std;
using namespace cv;


int main() {
	Start start;
	int input;
	int choice;
	int pause;
	int mini;
	PauseMenu pauseM;
	MinigameOptions game;
	Player* p1 = new Player();
	Minigame_Compositor* comp1 = new Minigame_Compositor();
	
	
	choice = start.userControl();

	if (choice == 1) {
		cout << "read in save coordinate from .txt file" << endl; 
	}
	else if (choice == 0) {
		ofstream start;
		start.open("coordinate.txt");
		start << "0 0";
		start.close();
		start.open("direction.txt");
		start << "";
		start.close();
	}

	Maze maze;
	input = maze.userControl();

	while (input != 0) {
		if (input == 1) {			
			pause = pauseM.userControl();
			if (pause == 5) {
				input = maze.userControl();
			}
			else if (pause == 6) {
				input = maze.userControl();
			}
			else {
				input = 0;
			}
		}
		else if (input == 2) {		
			mini = game.userControl();
			if (mini == 2) {
				comp1->play(p1);
				input = maze.userControl();
			}
			else {
				comp1->skip(p1);
				input = maze.userControl();
			}
		}
	}

	return 0;
}
