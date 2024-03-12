#pragma once
#include "Map.h"
#include "StringClass.h"

class GameController
{
public:

	GameController();
	~GameController();
	
	bool gameStatus() { return gameOver; };
	
	void userInput();
	void userMove(int PosX, int PosY);
	void buildMap();


private:

	const int GAMESIZE = 13;
	const int MAPSIZE = 12;
	char map[13][13] = {};

	int PlayerPosX = 1; 
	int PlayerPosY = 1;

	bool gameOver = false;
	String* command = nullptr;
};

