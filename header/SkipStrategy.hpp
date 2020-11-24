#ifndef __SKIPSTRATEGY_HPP__
#define __SKIPSTRATEGY_HPP__

#include "Minigame_Strategy.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class SkipStrategy : public MinigameStrategy
{
private:
	vector<string> games;
	vector<string> answers;
	Player* playerObj;
public:

	SkipStrategy()
	{

	}

	SkipStrategy(string choice, Player* player1)
	{
		if (choice == "skip")
		{
			playerObj = player1;
		}
	}

	/* Implementation of virtual functions from parent strategy. */
	virtual void pointsReward()
	{
		cout << "You have chosen to skip this minigame. 30 points will be deducted from your score." << endl;
		playerObj->setPoints((playerObj->getPoints() - 30));
		cout << "You now have a total of: " << playerObj->getPoints() << " points." << endl;
	}

	virtual void healthPenalty()
	{
		cout << "ERROR: This is being called from SkipStrategy. No health penalty should be possible." << endl;
	}

	virtual void display()
	{
		pointsReward();
		cout << "You are now allowed to move passed this minigame location." << endl;
	}

};



#endif //__SKIPSTRATEGY_HPP__
