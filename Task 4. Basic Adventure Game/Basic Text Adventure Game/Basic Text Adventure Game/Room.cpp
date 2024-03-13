// Includes
#include "Room.h" // Link to header
#include <iostream> // Send and Recieve streams
#include <string> // Allows to use string

// Constructor
Room::Room()
{
	description = "\nYou Reach a Dark.. Empty.. Room...\n";
	item = nullptr;
}

// Overloaded Constructor
Room::Room(std::string object, Items* item)
{
	description = "\nYou seem to have stumbled upon a " + object + "\n";
	item = nullptr;
}

// Destructor
Room::~Room()
{
	// Memory Cleanup
	delete item;
	item = nullptr;
}

// Used to Print the Rooms Description
void Room::Description() const
{
	std::cout << description;
}
