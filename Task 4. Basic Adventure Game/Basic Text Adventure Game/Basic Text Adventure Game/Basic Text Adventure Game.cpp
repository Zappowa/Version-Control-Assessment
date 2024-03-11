#include <iostream> // Reading/Writing to streams
#include "GameController.h" // Accessing Game Functins
using namespace std; // No need for std::

int main()
{
	// -- ASCII Title & Controls -- \\

	cout << R"( 
 _____ _            _               _    ______           _           
|_   _| |          | |             | |   | ___ \         | |          
  | | | |__   ___  | |     ___  ___| |_  | |_/ /___  __ _| |_ __ ___  
  | | | '_ \ / _ \ | |    / _ \/ __| __| |    // _ \/ _` | | '_ ` _ \ 
  | | | | | |  __/ | |___| (_) \__ \ |_  | |\ \  __/ (_| | | | | | | |
  \_/ |_| |_|\___| \_____/\___/|___/\__| \_| \_\___|\__,_|_|_| |_| |_|

---------------------------------------------------------------------------------------

// -- Controls - \\

Movement:
- ("move north") To move Up
- ("move east") To move Right
- ("move south") To move Down
- ("move west") To move Left

// Personal Todo

Show Title & Controls - Done
We give two options, (Play, leave) - Done
Looped Player Input - Done

Build Map and Borders - 
 

--

)";

	// ---- Game Code ---- \\

	GameController* game = new GameController();
	Map* map = new Map();

	while (game->gameStatus())
	{
		game->buildMap();
		game->userInput();
	}

	cout << "\nMaybe we will cross paths again!\n";

	// -- Memory Cleanup -- \\

	delete game;
	delete map;

	game = nullptr;
	map = nullptr;
}
