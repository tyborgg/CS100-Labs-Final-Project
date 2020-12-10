#include "PauseMenu.hpp"

PauseMenu* PauseMenu::instance = nullptr;
/*
PauseMenu::~PauseMenu(){
    delete instance;
}*/

PauseMenu* PauseMenu::getInstance(){
    if (instance == nullptr){
        instance = new PauseMenu();
    }
    return instance;
}

int PauseMenu::userControl(){
    ifstream input("controls.txt");
    string up;
    string down;

    input >> up;
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
            else{
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
        save(1, 4);
    }


    return count;
}

string PauseMenu::outputMenu(int img){
    Mat image;

    string num = to_string(img);

    image = imread("C:\\Users\\danny_000\\Desktop\\ConsoleApplication1\\ConsoleApplication1\\pm\\" + num + ".png");
    if (image.empty()) {
        cout << "Image not found." << endl;
        exit(0);
        return "Error";
    }
    resize(image, image, Size(), 0.8, 0.8);
    namedWindow("Pause Menu", WINDOW_AUTOSIZE);
    imshow("Pause Menu", image);

    char input = waitKey(0);
    
    stringstream ss;
    ss << input;
    string s = ss.str();

    destroyWindow("C:\\Users\\danny_000\\Desktop\\ConsoleApplication1\\ConsoleApplication1\\pm\\" + num + ".png");
    return s;
}

void PauseMenu::resume(){
    //cout << "resuming" << endl;
    delete instance;
}

void PauseMenu::save(int x, int y){
    cout << "saving" << "\n" << endl;
    
    ofstream savefile;

    savefile.open("save.txt", ios_base::app);
    //cout << x << " " << y << endl;
    savefile << x << " " << y << endl;
    savefile.close();
}

