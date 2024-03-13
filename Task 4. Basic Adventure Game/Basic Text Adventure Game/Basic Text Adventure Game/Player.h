// Prevents Multiple File Includes
#pragma once

// Includes
#include "StringClass.h"
#include <vector>


class Player
{
public:

	Player(); // Constructor
	~Player(); // Destructor

	// Uses a Binary Search to Find the Spell 
	bool FindSpell(const String& spell);

	// Prints Spells in the Vector
	void SpellList() const;

private:

	// Vector of Spells
	std::vector<String> Spells;


};

