#include "ball.hpp"
#include "paddle.hpp"
#include "gameManager.hpp"


int main(int argc, char** argv)
{
	/* NCURSES BEGIN */

	initscr();

  cbreak();	

	// Window
	
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);
	WINDOW * main_wnd = initscr();
	nodelay(main_wnd, true);
	
	// Run game

	gameManager c(xMax, yMax);
	c.Run();

	endwin();

	/* NCURSES END */

	return 0;
}

