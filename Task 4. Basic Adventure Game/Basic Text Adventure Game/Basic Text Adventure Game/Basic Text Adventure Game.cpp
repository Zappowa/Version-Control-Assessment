#include <iostream> // Reading/Writing to streams
#include "GameController.h" // Accessing Game Functins
using namespace std; // No need for std::

int main()
{
	// -- ASCII Title & Intructions -- \\

	cout << R"( 
 _____ _            _               _    ______           _           
|_   _| |          | |             | |   | ___ \         | |          
  | | | |__   ___  | |     ___  ___| |_  | |_/ /___  __ _| |_ __ ___  
  | | | '_ \ / _ \ | |    / _ \/ __| __| |    // _ \/ _` | | '_ ` _ \ 
  | | | | | |  __/ | |___| (_) \__ \ |_  | |\ \  __/ (_| | | | | | | |
  \_/ |_| |_|\___| \_____/\___/|___/\__| \_| \_\___|\__,_|_|_| |_| |_|

---------------------------------------------------------------------------------------

// -- Commands -- \\

- ("y/n" or "yes/no") To Answer Game Master
- ("run") To exit the game

Movement:
- ("w", "move north") To move Up
- ("d", "move east") To move Right
- ("s", "move south") To move Down
- ("a", "move west") To move Left

--

)";

	// ---- Game Code ---- \\

	GameController* game = new GameController();
	Map* map = new Map();

	// Game Loop
	while (game->gameStatus())
	{
		game->buildMap();
		game->userInput();
	}

	// Exit Message
	cout << "\n(Game Master) May we cross paths again!\n";

	// -- Memory Cleanup -- \\

	delete game;
	delete map;

	game = nullptr;
	map = nullptr;
}
