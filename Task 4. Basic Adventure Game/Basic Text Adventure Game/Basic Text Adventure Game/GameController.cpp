#include <iostream>
#include "GameController.h"
using namespace std;

GameController::GameController()
{
	command = new String("");

	std::cout << "(Game Master) Howdy Adventurer!! Would you like to play a game? ";
	command->ReadFromConsole();
	command->ToLower();

	for (int row = 0; row < GAMESIZE; row++)
	{
		for (int col = 0; col < GAMESIZE; col++)
		{
				map[row][col] = '.';
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
	cout << "\nAdventurer: ";
	command->ReadFromConsole();
	command->ToLower();

	if (command->EqualTo("run")) { gameOver = false; }

	if (command->EqualTo("w") || command->EqualTo("move north")) { userMove(0, -1); }
	if (command->EqualTo("a") || command->EqualTo("move west")) { userMove(-1, 0); }
	if (command->EqualTo("s") || command->EqualTo("move south")) { userMove(0, 1); }
	if (command->EqualTo("d") || command->EqualTo("move east")) { userMove(1, 0); }
}

void GameController::userMove(int PosX, int PosY)
{
	int tempX = PlayerPosX + PosX;
	int tempY = PlayerPosY + PosY;

	if (tempX < 1 || tempX > 11 || tempY < 1 || tempY > 11)
	{
		cout << "\nThat's a wall dumby\n";
	}
	else
	{
		PlayerPosX = tempX;
		PlayerPosY = tempY;
	}
}

void GameController::buildMap()
{
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

	map[PlayerPosY][PlayerPosX] = '$';

	for (int row = 0; row < GAMESIZE; row++)
	{
		for (int col = 0; col < GAMESIZE; col++)
		{
			cout << map[row][col];	

			if (row == 0 && col < MAPSIZE || row == MAPSIZE && col < MAPSIZE)
			{
				cout << '-';
			}
			else if (col > 1 || col < 12)
			{
				cout << ' ';
			}
		}
		cout << endl;
	}
	
}

