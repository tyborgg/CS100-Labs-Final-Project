#ifndef __MINIGAME_COMPOSITOR_HPP__
#define __MINIGAME_COMPOSITOR_HPP__
#include "Minigame_Strategy.hpp"

class Minigame_Compositor
{
private:
	MinigameStrategy* playGame;
	MinigameStrategy* skipGame;
public:
	Minigame_Compositor()
	{

	}

	Minigame_Compositor(string choice, Player* p1)
	{
		if (choice == "play")
		{
			playGame = new GameStrategy("play",p1);
		}
		else
		{
			skipGame = new SkipStrategy("skip",p1);
		}
	}

	void play(Player* p1)
	{
		if (playGame == NULL)
		{
			playGame = new GameStrategy("play", p1);
			playGame->display();
		}
		else
		{
			playGame->display();
		}
	}

	void skip(Player* p1)
	{
		if (p1->getPoints() >= 30)
		{
			if (skipGame == NULL)
			{
					skipGame = new SkipStrategy("skip", p1);
					skipGame->display();
			}
			else
			{
				skipGame->display();
			}
		}
		else
		{
			cout << "Sorry, you do not have enough points to skip this minigame. You will have to play the minigame instead." << endl;
			play(p1);
		}
		
	}

	
};


#endif //__MINIGAME_COMPOSITOR_HPP__
