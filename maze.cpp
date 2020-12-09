#include "maze.h"

Maze* Maze::instance = nullptr;

Maze::Maze() {
	int out;
	int out1;

	ifstream mazeFile;
	mazeFile.open("maze.txt");

	if (!mazeFile.is_open()) {
		cout << "Error: could not open maze.txt file" << endl;
		return;
	}

	while (mazeFile >> out) {
		coordX.push_back(out);
		mazeFile >> out1;
		coordY.push_back(out1);
	}

	mazeFile.close();
}

Maze* Maze::getInstance() {
	if (instance == nullptr) {
		instance = new Maze();
	}
	return instance;
}

int Maze::userControl(){
	getInstance();

	int currX;
	int currY;
	string saveX;
	string saveY;
	bool valid;
	string dir = "";
	string temp = "";
	string point = "";
	string tempX = "";
	string tempY = "";
	ofstream save;
	ifstream coord;

	ifstream control;
	control.open("controls.txt");
	string set;

	control >> set;
	fwd = set;
	control >> set;
	rt = set;
	control >> set;
	lt = set;
	control >> set;
	dwn = set;

	control.close();

	coord.open("coordinate.txt");
	coord >> currX;
	coord >> currY;
	coord.close();

	coord.open("direction.txt");
	while (coord >> temp) {
		dir += temp;
	}
	coord.close();

	cout << "cuurX = " << currX << endl;
	cout << "cuurY = " << currY << endl;

	tempX = to_string(currX);
	tempY = to_string(currY);
	point = tempX + tempY + dir;

	Mat image;
	image = imread("C:\\Users\\tyler\\Downloads\\MazeGameImages\\00.png");

	if (image.empty()) {
		cout << "Image was not successfully loaded!" << endl;
	}

	resize(image, image, Size(), 0.8, 0.8);
	namedWindow("MazeGame", WINDOW_AUTOSIZE);
	imshow("MazeGame", image);

	char in = waitKey(0);

	stringstream ss;
	ss << in;
	string input = ss.str();

	while (input != "p") {
		if (input == fwd && (currX != 0 || currY != 4) && (currX != 1 || currY != 6) && (currX != -1 || currY != 6)) {
			valid = search(currX, currY);

			if (valid == true) {
				cout << "display" << endl << "moved up" << endl;
				currY++;
				input = display(currX, currY, dir);
			}
			cout << "cuurX = " << currX << endl;
			cout << "lol" << endl;
			cout << "cuurY = " << currY << endl;
		}
		else if (input == rt && ((currX == 0 && currY == 4) || (currX == 1 && currY == 6) || (currX == -1 && currY == 6))) {
			dir += "r";
			currX++;
			cout << "currX " << currX << endl;
			valid = search(currX, currY);

			if (valid == true) {
				input = display(currX, currY, dir);
				cout << "moved right" << endl;
			}
			else {
				currX--;
				input = displayImage(currX, currY, dir);
			}
			cout << "currX = " << currX << endl;
			cout << "currY = " << currY << endl;
		}
		else if (input == lt && ((currX == 0 && currY == 4) || (currX == 1 && currY == 6) || (currX == -1 && currY == 6))) {
			dir += "l";
			currX--;
			valid = search(-currX, currY);

			if (valid == true) {
				input = display(currX, currY, dir);
				cout << "moved left" << endl;
			}
			else {
				currX++;
				input = displayImage(currX, currY, dir);
			}
		}
		else if (input == dwn && ((currX == 1 && currY == 4) || (currX == -1 && currY == 4) || (currX == 2 && currY == 6) || (currX == -2 && currY == 6) || (currX == 0 && currY == 6))) {
			input = displayEasterEgg(currX, currY, dir);
		}
		else {
			input = displayImage(currX, currY, dir);
		}

		if (currY == 7) {
			ofstream restart;
			restart.open("coordinate.txt");
			restart << "0 0";
			restart.close();
			restart.open("direction.txt");
			restart << "";
			restart.close();

			return 0;
		}
		else {
			save.open("coordinate.txt");

			saveX = to_string(currX);
			saveY = to_string(currY);

			cout << "saveX " << saveX << endl;
			cout << "saveY " << saveY << endl;

			save << saveX;
			save << " ";
			save << saveY;

			save.close();

			save.open("direction.txt");
			save << dir;
			save.close();

			if (input == "game") {
				return 2;
			}
		}
	}

	return 1;
}

bool Maze::search(int x, int y) {
	for (unsigned int i = 0; i < coordX.size(); i++) {
		if (x == coordX.at(i) && y == coordY.at(i)) {
			cout << "true" << endl;
			return true;
		}
	}
	
	cout << "false" << endl;

	return false;
}

string Maze::display(int x, int y, string str) {
	char c;
	string num1 = to_string(x);
	string num2 = to_string(y);
	string all = num1 + num2 + str;
	cout << "all: " << all << endl;

	VideoCapture cap("C:\\tmp\\MazeGame\\" + all + ".avi");

	if (!cap.isOpened()) {
		cout << "Error opening video stream or file" << endl;
		return "ERROR";
	}

	while (1) {
			Mat frame;

			cap >> frame;

			if (frame.empty())
				break;

			imshow("MazeGame", frame);

			c = waitKey(1);

			if (c == 27)
				break;
	}

	if ((x == 0 && y == 3) || (x == 1 && y == 6) || (x == -2 && y == 7)) {
		return "game";
	}

	c = waitKey(0);

	stringstream ss;
	ss << c;
	string s = ss.str();

	return s;
}

string Maze::displayImage(int x, int y, string str) {
	Mat image;

	string num1 = to_string(x);
	string num2 = to_string(y);
	string all = num1 + num2 + str;
	cout << "all: " << all << endl;

	image = imread("C:\\Users\\tyler\\Downloads\\MazeGameImages\\" + all + ".jpg");

	if (image.empty()) {
		cout << "Image was not successfully loaded!" << endl;
		return "ERROR";
	}

	namedWindow("MazeGame", WINDOW_AUTOSIZE);
	imshow("MazeGame", image);

	char input = waitKey(0);

	stringstream ss;
	ss << input;
	string s = ss.str();

	return s;
}

string Maze::displayEasterEgg(int x, int y, string str) {
	Mat image;

	string num1 = to_string(x);
	string num2 = to_string(y);
	string all = num1 + num2 + str;
	cout << "all: " << all << endl;

	image = imread("C:\\Users\\tyler\\Downloads\\MazeGameStartScreenPractice\\controlDWN.png");

	if (image.empty()) {
		cout << "Image was not successfully loaded!" << endl;
		return "ERROR";
	}

	resize(image, image, Size(), 0.8, 0.8);
	namedWindow("MazeGame", WINDOW_AUTOSIZE);
	imshow("MazeGame", image);

	char input = waitKey(0);

	stringstream ss;
	ss << input;
	string s = ss.str();

	return s;
}
