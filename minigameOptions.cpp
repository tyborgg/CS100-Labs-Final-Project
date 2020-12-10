#include "minigameOptions.hpp"

MinigameOptions* MinigameOptions::instance = nullptr;


MinigameOptions* MinigameOptions::getInstance() {
    if (instance == nullptr) {
        instance = new MinigameOptions();
    }
    return instance;
}

int MinigameOptions::userControl() {
    ifstream input("controls.txt");
    string up;
    string down;

    input >> up;
    input >> down;
    input.close();

    int count = 2;

    string userInput = outputMenu(count);

    while (userInput != "\r") {
        if (userInput == up) {
            if (count == 3) {
                userInput = outputMenu(2);
                count = 2;
            }
            else {
                userInput = outputMenu(2);
                count = 2;
            }
        }
        else if (userInput == down) {
            if (count == 2) {
                userInput = outputMenu(3);
                count = 3;
            }
            else {
                userInput = outputMenu(3);
                count = 3;
            }
        }
        else {
            if (count == 2) {
                userInput = outputMenu(2);
                count = 2;
            }
            else {
                userInput = outputMenu(3);
                count = 3;
            }
        }
    }
    return count;
}

string MinigameOptions::outputMenu(int img) {
    Mat image;

    string num = to_string(img);

    image = imread("C:\\Users\\danny_000\\Desktop\\cs100proj\\" + num + ".png");
    if (image.empty()) {
        cout << "Image not found." << endl;
        exit(0);
        return "Error";
    }
    resize(image, image, Size(), 0.8, 0.8);
    namedWindow("Minigame Options", WINDOW_AUTOSIZE);
    imshow("Minigame Options", image);

    char input = waitKey(0);

    stringstream ss;
    ss << input;
    string s = ss.str();

    destroyWindow("C:\\Users\\danny_000\\Desktop\\cs100proj\\" + num + ".png");
    return s;
}