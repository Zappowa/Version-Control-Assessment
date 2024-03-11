#include <iostream>
#include "GameController.h"
using namespace std;

GameController::GameController()
{
	command = new String("");

	std::cout << "Howdy Adventurer!! Would you like to play a game? ";
	command->ReadFromConsole();
	command->ToLower();

	for (int col = 0; col < MAPSIZE; col++)
	{
		for (int row = 0; row < MAPSIZE; row++)
		{
			if (col == 0 || col == MAPSIZE-1)
				map[col][row] = '-';
			else if (row == 0 || row == MAPSIZE-1)
				map[col][row] = '|';
			else
				map[col][row] = '.';
		}
	}

	if (command->EqualTo("yes") || command->EqualTo("y")) { gameOver = true; std::cout << "\n"; }
}

GameController::~GameController()
{
	delete command;
	command = nullptr;
}

void GameController::userInput()
{
	std::cout << "\nAdventurer: ";
	command->ReadFromConsole();
	command->ToLower();

	if (command->EqualTo("run")) { gameOver = false; }

	if (command->EqualTo("w")) { PlayerPosY--; }
	if (command->EqualTo("a")) { PlayerPosX--; }
	if (command->EqualTo("s")) { PlayerPosY++; }
	if (command->EqualTo("d")) { PlayerPosX++; }
}

void GameController::buildMap()
{
	for (int col = 0; col < MAPSIZE; col++)
	{
		for (int row = 0; row < MAPSIZE; row++)
		{
			if (col == PlayerPosY && row == PlayerPosX)
				map[col][row] = '$';

			cout << map[col][row];
		}
		cout << endl;
	}
}

