// Includes
#include <iostream>
#include "GameController.h" 
using namespace std;

// Constructor 
GameController::GameController()
{
	// Initialising the String Variable
	command = new String("");

	// Start Game Text
	cout << "(Game Master) Howdy Adventurer!! Would you like to play a game? ";
	
	// Read the Input and Convert to Lower
	command->ReadFromConsole().ToLower();

	// Setting the Map Char for all rooms
	for (int row = 0; row < GAMESIZE; row++)
	{
		for (int col = 0; col < GAMESIZE; col++)
		{
			map[row][col] = '.';
			rooms[row][col] = Room();
		}
	}

	// The Game Status will be decided based on user input
	if (command->EqualTo("yes") || command->EqualTo("y")) { gameOver = true; cout << "\n"; }
}


// Destructor
GameController::~GameController()
{
	// Memory Clean Up
	delete command;
	command = nullptr;
}


// Checks User Input
void GameController::userInput()
{
	cout << "\nAdventurer: "; 
	// Reads User Input and Converts to Lower
	command->ReadFromConsole().ToLower();

	// Game Ends if User Inputs "run"
	if (command->EqualTo("run")) { gameOver = false; }

	// Player Movement
	if (command->EqualTo("w") || command->EqualTo("move north")) { userMove(0, -1); }
	if (command->EqualTo("a") || command->EqualTo("move west")) { userMove(-1, 0); }
	if (command->EqualTo("s") || command->EqualTo("move south")) { userMove(0, 1); }
	if (command->EqualTo("d") || command->EqualTo("move east")) { userMove(1, 0); }

}

// Controls Player Movement (Takes 2 Intergers)
void GameController::userMove(int PosX, int PosY) 
{
	// Placing new Location to Temporary Variables
	int tempX = PlayerPosX + PosX;
	int tempY = PlayerPosY + PosY;

	// Checking if they are within the Map Range
	if (tempX < 1 || tempX > 11 || tempY < 1 || tempY > 11)
	{
		// Just gives this back if it's outside of range
		cout << "\nThat's a wall dumby\n";
	}
	else
	{
		// Confirms the location if it's inside the range
		PlayerPosX = tempX;
		PlayerPosY = tempY;
	}
}

// Map Generation Function
void GameController::buildMap()
{
	// Assigning all Chars for the Map based on location
	for (int row = 0; row < GAMESIZE; row++)
	{
		for (int col = 0; col < GAMESIZE; col++)
		{
			if (row == 0 || row == MAPSIZE)
				map[row][col] = '-';
			else if (col == 0 || col == MAPSIZE)
				map[row][col] = '|';
			else
				map[row][col] = '.';
		}
	}

	// Setting Players Position on Map
	
	map[PlayerPosY][PlayerPosX] = '$';

	// Printing the Map out to Console
	for (int row = 0; row < GAMESIZE; row++)
	{
		for (int col = 0; col < GAMESIZE; col++)
		{
			// Prints a Char at this Location
			cout << map[row][col];	

			// Enlargens the Board for Visibility
			if (row == 0 && col < MAPSIZE || row == MAPSIZE && col < MAPSIZE)
			{
				cout << '-';
			}
			else if (col > 1 || col < 12)
			{
				cout << ' ';
			}
		}
		// New Line for Map
		cout << endl;
	}
}

