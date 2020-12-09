#include <iostream>		
#include <string>
#include <sstream>
#include "start.h"
#include "maze.h"

using namespace std;
using namespace cv;

int main() {
	Start start;
	int input;
	int choice;
	
	choice = start.userControl();

	if (choice == 1) {
		cout << "read in save coordinate from .txt file" << endl; 
	}
	else if (choice == 0) {
		cout << "start new game" << endl;

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
			cout << "pause" << endl;
		}
		else if (input == 2) {		
			cout << "mini game" << endl;
		}
		input = maze.userControl();
	}

	return 0;
}
