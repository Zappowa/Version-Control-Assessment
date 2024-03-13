// Includes
#include "Room.h" // Link to header
#include <iostream> // Send and Recieve streams
#include <string> // Allows to use string

// Constructor
Room::Room()
{
	// Sets description to Empty if nothing is passed through
	description = "\nYou Reach a Dark.. Empty.. Room...\n";
}

// Overloaded Constructor
Room::Room(std::string object, Items* roomItem)
{
	// Print out the object that has been found
	description = "\nYou seem to have stumbled upon a " + object + "\n";
	// Pass Item through to the Class Variable
	item = roomItem;
}

// Destructor
Room::~Room()
{
	// Memory Cleanup (Only if there is something to delete)
	if (item != nullptr)
		item = nullptr;
}

// Variable Check before running functions
void Room::InfoItem() const
{
	// Does room contain an item
	if (item != nullptr)
	{
		// Use item thats in the room
		item->Description();
	}
	else
	{
		// Printing the Room is empty if there is no item
		std::cout << "\nThis room contains no items!\n";
	}
}

// Variable Check before running functions
void Room::UseItem() const
{
	// Does room contain an item
	if (item != nullptr)
	{
		// Use item thats in the room
		item->UseItem();
	}
	else
	{
		// Printing the Room is empty if there is no item
		std::cout << "\nThis room contains no items!\n";
	}
}

// Used to Print the Rooms Description
void Room::Description() const
{
	// Printing to Console if called
	std::cout << description;
}
