// Prevents Multiple File Includes
#pragma once

// Header Includes
#include "Room.h"
#include "Items.h"
#include "StringClass.h"

class GameController
{
public:	
	
	// Public Functions

	GameController(); // Constructor
	~GameController(); // Destructor

	// Game Functions
	bool gameStatus() { return gameOver; };
	void buildMap();
	
	// User Based Functions
	void userInput();
	void userMove(int PosX, int PosY);

private:

	//Private Variables

	// "StringClass" Pointer Variable
	String* command = nullptr;

	// Specifications for Game
	const int GAMESIZE = 13;
	const int MAPSIZE = 12;
	char map[13][13] = {};

	// Initialiser List (Without this you get errors)
	Items* item[4] = {new itemCat(), new itemLamp(), new itemBoxofDonuts(), new itemDoor()};
	
	// Room Variable of Map
	Room rooms[13][13] = {};

	// Interger Player Position
	int PlayerPosX = 1; 
	int PlayerPosY = 1;

	// Exit Door Position
	int exitX = 0;
	int exitY = 0;

	// Game Status
	bool gameOver = false;
	
};

