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

// -- Console Commands -- \\

- ("y/n" or "yes/no") To Answer Game Master

Movement:
- ("w", "move north") To move Up
- ("d", "move east") To move Right
- ("s", "move south") To move Down
- ("a", "move west") To move Left

Abilities:
- ("spells") See list of spells
- ("cast") To cast a spell

Game Commands:
- ("use") To use an item in a room
- ("info") To learn more about the item
- ("run") To exit the game

--

)";

	// ---- Game Code ---- \\

	// Class Variable to Access Functions
	GameController* gameMaster = new GameController();

	// Game Loop
	while (gameMaster->gameStatus())
	{
		gameMaster->buildMap(); // Map Construction
		gameMaster->userInput(); // Control Inputs
	}

	// Exit Message
	cout << "\n(Game Master) May we cross paths again!\n";

	// -- Memory Cleanup -- \\

	delete gameMaster;
	gameMaster = nullptr;
}
