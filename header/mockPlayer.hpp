#ifndef __MOCKPLAYER_HPP__
#define __MOCKPLAYER_HPP__

class Player
{
private:
	int points;
	int health;

public:

	Player()
	{
		this->points = 30;
		this->health = 100;
	}
	void setHealth(int num)
	{
		this->health = num;
	}

	int getHealth()
	{
		return this->health;
	}

	void setPoints(int num)
	{
		this->points = num;
	}
	
	int getPoints()
	{
		return this->points;
	}

};




#endif //__MOCKPLAYER_HPP__
