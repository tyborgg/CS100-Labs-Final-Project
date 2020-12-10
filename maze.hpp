#ifndef MAZE_HPP
#define MAZE_HPP

#include "Interface.h"
#include <iostream>		
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include "opencv2\imgproc.hpp"
#include <string>
#include <sstream>
#include <fstream>
#include <ostream>
#include <vector>

using namespace std;
using namespace cv;

class Maze : public Interface {
private:
	string fwd;
	string rt;
	string lt;
	string dwn;
	vector<int> coordX;
	vector<int> coordY;
	static Maze* instance;
public:
	Maze();
	virtual int userControl();
	static Maze* getInstance();
	bool search(int, int);
	string display(int, int, string);
	string displayImage(int, int, string);
	string displayEasterEgg(int, int, string);
};
#endif
