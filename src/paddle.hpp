#ifndef PADDLE_H
#define PADDLE_H

class Paddle
{
private:
	int x, y;
	int startX, startY;
public:
	Paddle()
	{
		x = y = 0;
	}
	Paddle(int posX, int posY) : Paddle()
	{
		startX = posX;
		startY = posY;
		x = posX;
		y = posY;
	}
	inline void Reset() { x = startX; y = startY; }
	inline int getX() { return x; }
	inline int getY() { return y; }
	inline void moveUp() { y--; }
	inline void moveDown() { y++; }
};

#endif
