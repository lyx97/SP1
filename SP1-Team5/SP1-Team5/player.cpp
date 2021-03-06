#include "header.h"
#include "player.h"
#include "functions.h"
#include "MazeGenerator.h"
#include "clock.h"
#include "game.h"
#include "FOE_Movement.h"

extern count counter;
extern bool g_clear;
extern vector <string> g_size;

bool g_key = false;
bool g_quit = false;
COORD g_player;

void player()
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),g_player);
	setcolor(0x0A);
	cout << (char)1;
}

void movement()
{
	int ch = _getch();
	switch(ch)
	{
	case 72:
		if(g_player.Y-1 >= 0)
		{
			detect(g_player.Y-1,g_player.X); //Top movement
		}
		break;
	case 80:
		if(g_player.Y+1 < 23)
		{
			detect(g_player.Y+1,g_player.X); //Down movement
		}
		break;
	case 77:
		if(g_player.X+1 < 60)
		{
			detect(g_player.Y,g_player.X+1); //Right movement
		}
		break;
	case 75:
		if(g_player.X-1 >= 0)
		{
			detect(g_player.Y,g_player.X-1); //Left movement
		}
		break;
	case 27:
		g_quit = true;
		clock_end();
		break;
	case 'r':
	case 'R':
		reset();
		break;
	default: movement();
		break;
	}
}

void detect(int Y,int X)
{
	switch(g_size[Y][X])
	{
	case '0': 
		g_player.Y = Y;
		g_player.X = X;
		FOEH(counter.H);
		FOEV(counter.V);
		break;
	case 'x': 
		g_size[Y][X] = '3';
		g_player.Y = Y;
		g_player.X = X;
		FOEH(counter.H);
		FOEV(counter.V);
		break; 
	case '!': 
		g_size[Y][X] = '0';
		g_player.Y = Y;
		g_player.X = X;
		FOEH(counter.H);
		FOEV(counter.V);
		g_key = true;
		break;
	case '<':
		g_player.Y = Y;
		g_player.X = X;
		FOEH(counter.H);
		FOEV(counter.V);
		break;
	case '>':
		g_player.Y = Y;
		g_player.X = X;
		FOEH(counter.H);
		FOEV(counter.V);
		break;
	case '^':
		g_player.Y = Y;
		g_player.X = X;
		FOEH(counter.H);
		FOEV(counter.V);
		break;
	case 'v':
		g_player.Y = Y;
		g_player.X = X;
		FOEH(counter.H);
		FOEV(counter.V);
		break;
	case '?':
		g_player.Y = Y;
		g_player.X = X;
		FOEH(counter.H);
		FOEV(counter.V);
		break;
	case '4': 
		g_clear = true;
		g_player.Y = Y;
		g_player.X = X;
		break;
	}
}