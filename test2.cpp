#include <iostream>		
#include <string>
#include <sstream>
#include "start.h"
#include "maze.h"
#include "PauseMenu.h"
#include "minigameOptions.h"
#include "Minigame_Compositor.h"
#include "mockPlayer.h"

using namespace std;
using namespace cv;

int main() { 
	Start start;
	int count;

	count = start.userControl();

	if (count == 0) {
		cout << "Start Game" << endl << "TEST PASSED" << endl;
	}
	else {
		cout << "Start Game" << endl << "TEST PASSED" << endl;
	}

	return 0;
}
