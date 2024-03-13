#include "GameController.h" // Link to the header
#include <iostream>
#include <random> // Creating Random Numbers

using namespace std;

// Constructor 
GameController::GameController()
{
	// Initialising the String Variable
	command = new String("");
	player = new Player();

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

	// Randomly Generating Number in Range of Map
	random_device rng;
	uniform_int_distribution<int> dist(2, 11);

	// While Loop Condition
	bool run = true;
	
	// Assigning the Random Number to Variables for use
	exitX = dist(rng);
	exitY = dist(rng);

	// Making sure our random numbers aren't the same as an already used room
	while (run)
	{
		if (exitY == 2 && exitX == 3 || exitY == 8 && exitX == 5 || exitY == 3 && exitX == 10)
		{
			exitX = dist(rng);
			exitY = dist(rng);
		}
		else { run = false; }
	}

	// Assigning Rooms with Descriptions of whats in it
	rooms[2][3] = Room("Cat", item[0]);
	rooms[3][10] = Room("Lamp", item[1]);
	rooms[8][5] = Room("BoxOfDonuts", item[2]);
	rooms[exitY][exitX] = Room("Door", item[3]);

	// The Game Status will be decided based on user input
	if (command->EqualTo("yes") || command->EqualTo("y")) { gameOver = true; cout << "\n"; }
}

// Destructor
GameController::~GameController()
{
	// Memory Clean Up
	delete command;
	command = nullptr;

	for (int i = 0; i < 3; i++)
		delete item[i];
}

// Checks User Input
void GameController::userInput()
{
	cout << "\nAdventurer: "; 
	// Reads User Input and Converts to Lower
	command->ReadFromConsole().ToLower();

	// Game Ends if User Inputs "run"
	if (command->EqualTo("run")) { gameOver = false; }
	
	// User Commands
	if (command->EqualTo("use")) { rooms[PlayerPosY][PlayerPosX].UseItem(); } 
	if (command->EqualTo("info")) { rooms[PlayerPosY][PlayerPosX].InfoItem(); }

	// Player Movement
	if (command->EqualTo("w") || command->EqualTo("move north")) { userMove(0, -1); }
	if (command->EqualTo("a") || command->EqualTo("move west")) { userMove(-1, 0); }
	if (command->EqualTo("s") || command->EqualTo("move south")) { userMove(0, 1); }
	if (command->EqualTo("d") || command->EqualTo("move east")) { userMove(1, 0); }

	// Player Abilities

	if (command->EqualTo("spells")) { player->SpellList(); }
	
	if (command->Find(0, "cast ") == 0)
	{
		// Create a new String with the extracted spell name
		size_t castIndex = 5;
		String spellName = *command;

		// Check if the player knows the spell
		if (player->FindSpell(spellName.CStr()) + castIndex) { cout << "You cast the spell: " << spellName.CStr() << "\n"; }
		else { cout << "You don't know the spell: " << spellName.CStr() << endl; }

		// Implementation for Spells
		if (strcmp(spellName.CStr() + castIndex, "levitate") == 0) { cout << "\n(Game Master) You levitate off the ground!\n"; }
		if (strcmp(spellName.CStr() + castIndex, "invisibility") == 0) { cout << "\n(Game Master) You turn invisible!\n"; }
		if ((strcmp(spellName.CStr() + castIndex, "teleport") == 0) && PlayerPosY == exitY && PlayerPosX == exitX)
		{ 
				cout << "\n(Game Master) You've teleported through the locked door!\n";
				cout << "\n(Game Master) You find yourself in a dark room... The floor drops and you plummet to your Deathh!\n";
				gameOver = false;
		}
	}

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

		// Printing the Description of the room after moving 
		rooms[PlayerPosY][PlayerPosX].Description();
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

	// Temporary Locations to Spot Rooms
	
	map[2][3]  = 'c';
	map[8][5]  = 'b';
	map[3][10] = 'l';
	map[exitY][exitX] = 'X';

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

