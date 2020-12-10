#include "PauseMenu.hpp"

PauseMenu* PauseMenu::instance = nullptr;

PauseMenu* PauseMenu::getInstance() {
    if (instance == nullptr) {
        instance = new PauseMenu();
    }
    return instance;
}

int PauseMenu::userControl() {
    string up;
    string right;
    string left;
    string down;
    string dir = "";
    string temp = "";
    int currX;
    int currY;

    ifstream coord;
  
    coord.open("coordinate.txt");
    coord >> currX;
    coord >> currY;
    coord.close();

    coord.open("direction.txt");
    while (coord >> temp) {
        dir += temp;
    }
    coord.close();

    cout << currX << endl;
    cout << currY << endl;
    cout << dir << endl;

    ifstream input("controls.txt");
    input >> up;
    input >> right;
    input >> left;
    input >> down;
    input.close();

    int count = 5;

    string userInput = outputMenu(count);

    while (userInput != "\r") {
        if (userInput == up) {
            if (count == 7) {
                userInput = outputMenu(6);
                count = 6;
            }
            else if (count == 6) {
                userInput = outputMenu(5);
                count = 5;
            }
            else {
                userInput = outputMenu(5);
                count = 5;
            }
        }
        else if (userInput == down) {
            if (count == 5) {
                userInput = outputMenu(6);
                count = 6;
            }
            else if (count == 6) {
                userInput = outputMenu(7);
                count = 7;
            }
            else {
                userInput = outputMenu(7);
                count = 7;
            }
        }
        else {
            if (count == 5) {
                userInput = outputMenu(5);
                count = 5;
            }
            else if (count == 6) {
                userInput = outputMenu(6);
                count = 6;
            }
            else {
                userInput = outputMenu(7);
                count = 7;
            }
        }
    }

    if (count == 5) {
        resume();
    }
    else if (count == 6) {
        save(currX, currY, dir);
    }

    return count;
}

string PauseMenu::outputMenu(int img) {
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

void PauseMenu::resume() {
    delete instance;
}

void PauseMenu::save(int x, int y, string str) {
    cout << "saving" << "\n" << endl;

    string saveX = to_string(x);
    string saveY = to_string(y);

    ofstream savefile;

    savefile.open("coordinate.txt");
    savefile << x << " " << y;
    savefile.close();

    savefile.open("direction.txt");
    savefile << str;
    savefile.close();
}
