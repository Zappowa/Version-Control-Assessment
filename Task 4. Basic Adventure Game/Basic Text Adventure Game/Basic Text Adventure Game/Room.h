// Prevents Multiple File Includes
#pragma once

// Includes
#include "Items.h" // Permission to use the header
#include <string> // Permission to use string 

class Room
{
public:
	
	// Public Functions

	Room(); // Constructor

	Room(std::string object, Items* item); // Overloaded Constructor
	
	~Room(); // Destructor

	// Const Function for Description
	void Description() const;

private:

	// Private Variables

	// Used to define whats in our room
	std::string description;
	Items* item;

};

