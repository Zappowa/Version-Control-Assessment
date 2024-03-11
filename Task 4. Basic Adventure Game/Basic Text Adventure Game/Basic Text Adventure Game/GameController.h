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
	void buildMap();


private:

	const int MAPSIZE = 10;
	char map[10][10] = {};

	int PlayerPosX = 0; 
	int PlayerPosY = 0;

	bool gameOver = false;
	String* command = nullptr;
};

