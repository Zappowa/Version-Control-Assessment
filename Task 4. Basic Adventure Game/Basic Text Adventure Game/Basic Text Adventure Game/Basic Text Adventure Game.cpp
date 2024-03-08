// Main Funcion Includes
#include <iostream>

#include "StringClass.h" // Accessing String Class
#include "Map.h"

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

The Lost Realm (Guide)

Player Should be able to move (NESW)
Each Room should have Description() and an item or empty. Should print whats in the room when entered
Interact with item Use()
Desctiption of Items
Player Class hold spells 

Map:
ASCII Map w/ Borders
Positions of each space
Player cannot move past borders
Player += / -=
		  
)";

	// ---- Game Code ---- \\

	char input;
	Map play;

	while (true)
	{
		input = _getch();
		cout << "\nInput: " << input;
		if (input == 's')
		{
			play.buildMap();
		}
	}




}
