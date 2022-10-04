#ifndef BALL_H
#define BALL_H

#include <cstdlib>
enum Dir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };

class Ball
{
private:
	int x, y;
	int startX, startY;
	Dir direction;
public:
	Ball(int posX, int posY)
	{
		startX = posX;
		startY = posY;
		x = posX, y = posY;
		direction = STOP;
	}
	void Reset()
	{
		x = startX; y = startY;
		direction = STOP;
	}
	void changeDirection(Dir d)
	{
		direction = d;
	}
	void randomDirection()
	{
		direction = (Dir)((rand() % 6) + 1);
	}
	inline int getX() { return x; }
	inline int getY() { return y; }
	inline Dir getDirection() { return direction; }
	void Move()
	{
		switch (direction)
		{
			case STOP:
				break;
			case LEFT:
				x--;
				break;
			case RIGHT:
				x++;
			case UPLEFT:
				x--; y--;
				break;
			case DOWNLEFT:
				x--; y++;
				break;
			case UPRIGHT:
				x++; y--;
				break;
			case DOWNRIGHT:
				x++; y++;
				break;
			default:
				break;
		}
	}

};

#endif
