#include "start.h"

int Start::userControl(){
	string check = "";
	string choice = "";
	string userInput = "";
	string control = "";
	int count = 0;
	ifstream newPlayer;
	newPlayer.open("firstTime.txt");

	if (!newPlayer.is_open()) {
		cout << "Error: could not open firstTime.txt file" << endl;
		return -1;
	}

	newPlayer >> check;
	cout << check << endl;
	newPlayer.close();

	ifstream show;
	show.open("neverShow.txt");

	if (!show.is_open()) {
		cout << "Error: could not open neverShow.txt file" << endl;
		return -1;
	}

	show >> choice;
	cout << choice << endl;
	show.close();

	if (check == "Yes") {
		ofstream setNo;
		setNo.open("firstTime.txt");
		setNo << "No";

		Mat image;
		image = imread("C:\\Users\\tyler\\Downloads\\MazeGameImages\\welcome.png");

		if (image.empty()) {
			cout << "Image was not successfully loaded!" << endl;
		}

		resize(image, image, Size(), 0.8, 0.8);
		namedWindow("MazeGame", WINDOW_AUTOSIZE);
		imshow("MazeGame", image);
		waitKey(0);

		check = "No";
		cout << check << endl;
		cout << choice << endl;
	}
	
	if (check == "No" && choice == "Show") {		
		ofstream out;
		out.open("controls.txt");
		
		control = "p";

		while (control == "p" || control == "\t") {
			control = controlsMenu("FWD");
		}
		this->fwd = control;
		cout << fwd << endl;
		out << fwd << endl;
		control = "p";

		while (control == "p" || control == "\t") {
			control = controlsMenu("RT");
		}
		this->rt = control;
		cout << rt << endl;
		out << rt << endl;
		control = "p";

		while (control == "p" || control == "\t") {
			control = controlsMenu("LT");
		}
		this->lt = control;
		cout << lt << endl;
		out << lt << endl;
		control = "p";

		while (control == "p" || control == "\t") {
			control = controlsMenu("DWN");
		}
		this->dwn = control;
		cout << dwn << endl;
		out << dwn << endl;

		out.close();

		userInput = showMSG(0);

		while (userInput != "\r") {
			if (userInput == fwd) {
				if (count == 1) {
					userInput = showMSG(0);
					count = 0;
				}
				else {
					userInput = showMSG(0);
					count = 0;
				}
			}
			else if (userInput == dwn) {
				if (count == 0) {
					userInput = showMSG(1);
					count = 1;
				}
				else {
					userInput = showMSG(1);
					count = 1;
				}
			}
			else {
				if (count == 0) {
					userInput = showMSG(0);
					count = 0;
				}
				else {
					userInput = showMSG(1);
					count = 1;
				}
			}
		}

		if (count == 1) {
			out.open("neverShow.txt");
			out << "Skip" << endl;
			out.close();
		}
	}
	else {											
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
	}
	
	count = 0;
	userInput = screen(count);

	while (userInput != "\r") {

		if (userInput == fwd) {
			if (count == 1) {
				userInput = screen(0);
				count = 0;
			}
			else {
				userInput = screen(0);
				count = 0;
			}
		}
		else if (userInput == dwn) {
			if (count == 0) {
				userInput = screen(1);
				count = 1;
			}
			else {
				userInput = screen(1);
				count = 1;
			}
		}
		else {
			if (count == 0) {
				userInput = screen(0);
				count = 0;
			}
			else {
				userInput = screen(1);
				count = 1;
			}
		}
	}

	return count;
}

string Start::screen(int img) {
	Mat image;

	string num = to_string(img);

	image = imread("C:\\Users\\tyler\\Downloads\\MazeGameImages\\" + num + ".png");

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

string Start::controlsMenu(string control) {
	char input;
	Mat image;
	image = imread("C:\\Users\\tyler\\Downloads\\MazeGameImages\\control" + control  + ".png");

	if (image.empty()) {
		cout << "Image was not successfully loaded!" << endl;
		return "ERROR";
	}

	resize(image, image, Size(), 2.2, 2.2);
	namedWindow("MazeGame", WINDOW_AUTOSIZE);
	imshow("MazeGame", image);

	input = waitKey(0);

	stringstream ss;
	ss << input;
	string s = ss.str(); 

	return s;
}

string Start::showMSG(int img) {
	Mat image;

	string num = to_string(img);

	image = imread("C:\\Users\\tyler\\Downloads\\MazeGameImages\\controlMsg" + num + ".png");

	if (image.empty()) {
		cout << "Image was not successfully loaded!" << endl;
		return "ERROR";
	}

	resize(image, image, Size(), 1.2, 1.2);
	namedWindow("MazeGame", WINDOW_AUTOSIZE);
	imshow("MazeGame", image);

	char input = waitKey(0);

	stringstream ss;
	ss << input;
	string s = ss.str();

	return s;
}
