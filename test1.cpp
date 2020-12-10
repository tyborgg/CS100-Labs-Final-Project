#include <iostream>		
#include <string>
#include <sstream>
#include "start.h"
#include "maze.h"

using namespace std;
using namespace cv;

int main (){	//unit test 1
	Start start;
	int x;
	string value = "";
	//Test wrong input up		wrong input = p
	x = start.userControl();
	if (x == -1) {
		value = "Error";
		if (value == "Error") {
			cout << "TEST 1 PASSED" << endl;
		}
	}
	
	value = "";
	//Test wrong input right	wrong input = p or fwd
	x = start.userControl();
	if (x == -1) {
		value = "Error";
		if (value == "Error") {
			cout << "TEST 2 PASSED" << endl;
		}
	}
	else {
		cout << "TEST 2 PASSED" << endl;
	}

	value = "";
	//Test wrong input left		wrong input = p or fwd or rt
	x = start.userControl();
	if (x == -1) {
		value = "Error";
		if (value == "Error") {
			cout << "TEST 3 PASSED" << endl;
		}
	}
	else {
		cout << "TEST 3 PASSED" << endl;
	}

	value = "";
	//Test wrong input down		wrong input = p or fwd or rt or lt
	x = start.userControl();
	if (x == -1) {
		value = "Error";
		if (value == "Error") {
			cout << "TEST 4 PASSED" << endl;
		}
	}
	else {
		cout << "TEST 4 PASSED" << endl;
	}

	return 0;
}
