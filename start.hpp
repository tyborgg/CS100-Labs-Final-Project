#ifndef START_HPP
#define START_HPP

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

using namespace std;
using namespace cv;

class Start : public Interface {
private:
	string fwd;
	string lt;
	string rt;
	string dwn;
public:
	virtual int userControl();
	string screen(int);
	string controlsMenu(string);
	string showMSG(int);
}; 
#endif

