#ifndef __GAMESTRATEGY_HPP__
#define __GAMESTRATEGY_HPP__

#include "Minigame_Strategy.hpp"
#include "mockPlayer.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <algorithm>

using namespace std;

class GameStrategy : public MinigameStrategy
{
private:
	vector<string> games;
	vector<string> answers;
	Player* playerObj;
	int randSeed;
public:

	GameStrategy()
	{
		string line;
		ifstream input("../resources/GameList.txt");
		if (input.is_open())
		{
			while (getline(input, line))
			{
				games.push_back(line);
			}
		}
		input.close();


		ifstream input2("../resources/GameAnswers.txt");
		if (input2.is_open())
		{
			while (getline(input2, line))
			{
				answers.push_back(line);
			}
		}
		input2.close();
	}

	GameStrategy(string choice, Player* player1)
	{
		if (choice == "play")
		{
			string line;
			ifstream input("../resources/GameList.txt");
			if (input.is_open())
			{
				while (getline(input, line))
				{
					games.push_back(line);
				}
			}
			input.close();

			ifstream input2("../resources/GameAnswers.txt");
			if (input2.is_open())
			{
				while (getline(input2, line))
				{
					answers.push_back(line);
				}
			}
			input2.close();

			this->playerObj = player1;
		}
		else
		{

		}
	}


	/* Implementation of virtual functions from parent strategy. */
	virtual void pointsReward()
	{
		playerObj->setPoints(playerObj->getPoints() + 10);
	}

	virtual void healthPenalty()
	{
		playerObj->setHealth(playerObj->getHealth() - 20);
		if(playerObj->getHealth() <= 0)
		{
			cout << "You have lost all of your health!" << endl;
			cout << "GAME OVER!" << endl;
		}
	}

	virtual void display()
	{
		cout << "You have encountered a minigame! Your game is as follows:" << endl;
		srand(time(NULL));
		randSeed = rand() % games.size();
		string game = games.at(randSeed);
		games.erase(games.begin() + randSeed);

		cout << game << endl;
		cout << "Enter your answer: ";
		string answer;
		cin >> answer;

		transform(answer.begin(), answer.end(), answer.begin(), ::tolower); // makes sure the string input is converted to lowercase to ensure capitalization isn't a factor.

		if (answer == answers.at(randSeed))
		{
			cout << "Congratulations! That is the correct answer!" << endl;
			this->pointsReward();
			cout << "You have been awarded 10 points..." << endl;
			cout << "Your total score is now: " << playerObj->getPoints() << endl;
			answers.erase(answers.begin() + randSeed);
		}
		else
		{
			cout << "Sorry! That answer is incorrect." << endl;
			this->healthPenalty();
			cout << "You have taken a health penalty of 20 hitpoints." << endl;
			cout << "Your health is now: " << playerObj->getHealth() << endl;
			answers.erase(answers.begin() + randSeed);
		}
	}

};




#endif //__GAMESTRATEGY_HPP__
