#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <unistd.h>
#include <string>
#include <time.h>
#include <ncurses.h>

using namespace std;

class gameManager
{
private:
	int width, height;
	int score1, score2;
	char up1, down1, up2, down2;
	bool quit;
	Ball * ball;
	Paddle * player1;
	Paddle * player2;
public:
	gameManager(int w, int h)
	{
		srand(time(NULL));
		up1 = 'q'; up2 = 'p';
		down1 = 'a'; down2 = ';';
		score1 = score2 = 0;
		width = w; height = h;
		ball = new Ball(w / 2, h / 2);
		player1 = new Paddle(2, h / 2 - 3);
		player2 = new Paddle(w - 3, h / 2 - 3);
	}
	~gameManager()
	{
		delete ball, player1, player2;
	}
	void scoreUp(Paddle * player)
	{
		if (player == player1)
			score1++;
		else if (player == player2)
			score2++;

		ball->Reset();
		player1->Reset();
		player2->Reset();
	}
	void Draw()
	{
		system("clear");
		for (int i = 0; i < width; i++)
			addch('\xDC');
		cout << endl;

		for (int i = 0; i < height-4; i++)
		{
			for (int j = 0; j < width; j++)
			{
				int ballx = ball->getX();
				int bally = ball->getY();
				int player1x = player1->getX();
				int player2x = player2->getX();
				int player1y = player1->getY();
				int player2y = player2->getY();

				if (j == 0)
					addch('\xDC');
				
				// Ball
				else if (ballx == j && bally == i)
					addch('O');
				
        //Player 1
				else if (player1x == j && player1y == i)
					addch('\xB3');
				else if (player1x == j && player1y + 1 == i)
					addch('\xB3');
				else if (player1x == j && player1y + 2 == i)
					addch('\xB3');
				else if (player1x == j && player1y + 3 == i)
					addch('\xB3');
					
        //Player 2
				else if (player2x == j && player2y == i)
					addch('\xB3');
				else if (player2x == j && player2y + 1 == i)
					addch('\xB3');
				else if (player2x == j && player2y + 2 == i)
					addch('\xB3');
				else if (player2x == j && player2y + 3 == i)
					addch('\xB3');
				else if (j == width-1)
					addch('\xDC');
				else 
					addch(' ');

				}
			cout << endl;
		}
		for (int i = 0; i < width; i++)
			addch('\xDC');
		cout << endl;

		printw("Score 1: %d \n", score1);
		printw("Score 2: %d", score2);


	}
	void Input()
	{
		ball->Move();
		int ballx = ball->getX();
		int bally = ball->getY();
		int player1x = player1->getX();
		int player2x = player2->getX();
		int player1y = player1->getY();
		int player2y = player2->getY();

		char current = getch();

		if (current == up1)
			if (player1y > 0)
				player1->moveUp();
		if (current == up2)
			if (player2y > 0)
				player2->moveUp();
		if (current == down1)
			if (player1y + 4 < height)
				player1->moveDown();
		if (current == down2)
			if (player2y + 4 < height)
				player2->moveDown();
		if (ball->getDirection() == STOP)
			ball->randomDirection();

	}
	
	void Logic()
	{
		int ballx = ball->getX();
		int bally = ball->getY();
		int player1x = player1->getX();
		int player2x = player2->getX();
		int player1y = player1->getY();
		int player2y = player2->getY();

		//Left paddle
		for (int i = 0; i < 4; i++)
			if (ballx == player1x + 1 && bally == player1y + i)
				ball->changeDirection((Dir)((rand() % 3) + 4));
		
		// Right paddle
		for (int i = 0; i < 4; i++)
			if (ballx == player2x + 1 && bally == player2y + i)
				ball->changeDirection((Dir)((rand() % 3) + 1));

		// Bottom wall
		if (bally == height - 1)
			ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);

		// Top wall	
		if (bally == 0)
			ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);

		// Right wall
		if (ballx == width - 1)
			scoreUp(player1);

		// Left wall
		if (ballx == 0)
			scoreUp(player2);

	}

	void Run()
	{

		while(1)
		{
			Draw();
			Input();
			Logic();
			clear();
			usleep(10000);
		}
	}
};
	
#endif
