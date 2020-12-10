#include "Minigame_Strategy.hpp"
#include "mockPlayer.hpp"
#include "GameStrategy.hpp"
#include "SkipStrategy.hpp"
#include "Minigame_Compositor.hpp"
#include "minigameOptions.hpp"
int main()
{
	//Test Case 1 (Plays three rounds (amount of minigames in game))
	Player* p1 = new Player();
	GameStrategy* game1 = new GameStrategy("play", p1);
	game1->display();
	game1->display();
	game1->display();

	if (p1->getPoints() != 0 || p1->getHealth() != 100)
	{
		cout << "TEST 1 PASSED!" << endl << endl << endl;
	}


	//Test Case 2 (Dies)

	Player* p2 = new Player();
	cout << "NEW PLAYER" << endl;
	cout << "Test Case: Lose until game over." << endl;
	GameStrategy* game2 = new GameStrategy("play", p2);
	game2->healthPenalty();
	game2->healthPenalty();
	game2->healthPenalty();
	game2->healthPenalty();
	game2->healthPenalty();

	if (p2->getHealth() == 0)
	{
		cout << "TEST 2 PASSED!" << endl << endl << endl;
	}


	return 0;

}i
