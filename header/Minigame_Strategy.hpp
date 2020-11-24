#ifndef __MINIGAME_STRATEGY_HPP__
#define __MINIGAME_STRATEGY_HPP__
#include <string>
#include <vector>
#include "mockPlayer.hpp"
using namespace std;
class MinigameStrategy
{
private:
	vector <string> games;
	vector <string> answers;
	Player* playerObj;

public:
	
	MinigameStrategy()
	{
		// need to still fill the games and answers vector.
	}
		 		
	MinigameStrategy(string choice, Player* player1)
	{
		 						
	}
	/* Virtual Functions to be implemented by strategies. */
		
	virtual void pointsReward() = 0;
	virtual void healthPenalty() = 0;
	virtual void display() = 0;
};

#endif //__MINIGAME_STRATEGY_HPP__
