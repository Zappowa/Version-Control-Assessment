#include "Player.h"
#include <iostream>

Player::Player()
{
	// Adding Spells to the List
	Spells.push_back("levitate");
	Spells.push_back("teleport");
	Spells.push_back("invisibility");
}

Player::~Player()
{

}

// Prints Spells in the Vector
void Player::SpellList() const
{
	// Loop to Print Spells in the Vector
	if (!Spells.empty())
	{
		std::cout << "\nAvailable spells:\n";
		for (const String& spell : Spells)
			std::cout << "- " << spell.CStr() << "\n";
	}
}

// Uses a Binary Search to Find the Spell 
bool Player::FindSpell(const String& spell)
{
	int bottom = 0;
	int top = size(Spells) - 1;

	while (bottom <= top)
	{
		int middle = (bottom + top) / 2;
		
		if (Spells[middle] == spell)
			return true; // Found Spell
		else if (Spells[middle] < spell)
			bottom = middle + 1;
		else
			top = middle - 1;
	}
	// Spell Not Found
	return false;
}
