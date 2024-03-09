// Main Funcion Includes
#include <iostream>
#include "GameController.h"

#include <conio.h> // Used for getch() - Grabs Input without pressing enter
using namespace std;

int main()
{
	// -- ASCII TITLE -- \\

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
- (W) To move North
- (D) To move East
- (S) To move South
- (A) To move West


For ME

Show Title & Controls

We give two options, (Play, leave)

Build Map and Borders
Asks for input which the player can now do anything they want


)";

	// ---- Game Code ---- \\

	GameController* game = new GameController();

	




	/*
	char input;
	Map play;

	while (true)
	{
		input = _getch();
		cout << "\nInput: " << input;
		if (input == 's') { play.buildMap(); }
	}
	*/


	// -- Memory Cleanup -- \\

	delete game;
	game = nullptr;
}
