// Includes
#include "Items.h"
#include <iostream>

// Items Class
void Items::UseItem() {}

void Items::Description() const {}

// Cat Class
void itemCat::UseItem()
{
	if (purring == false)
	{
		std::cout << "\nYou pat the Cat.\n";
		purring = true;
	}
	else
	{
		std::cout << "\n(Game Master) I don't think he wants any more!\n";
	}
}

void itemCat::Description() const
{
	std::cout << "\n(Game Master) He's a plump orange tabby with white socks on his two front paws and a bushy tail.\n";
}

// Lamp Class

void itemLamp::UseItem()
{
	if (turnedOn == false)
	{
		std::cout << "\nA bright light shines into your eyes as you turn on the lamp.\n";
		turnedOn = true;
	}
	else
	{
		std::cout << "\n(Game Master) The light is already on!\n";
	}
}

void itemLamp::Description() const
{
	std::cout << "\n(Game Master) A charming antique lamp that casts a warm, golden glow.\n";
}

// Donuts Class
void itemBoxofDonuts::UseItem()
{
	numDonuts -= 1;

	if (numDonuts + 1 == 12)
	{
		std::cout << "\n(Game Master) Well you've just ruined the Dozen Donuts!";
		std::cout << "\nNumber of Donuts Left: " << numDonuts << "\n";
	}
	else if (numDonuts > 0)
	{
		std::cout << "\nYou've eaten anoter Delicous Donuts :<";
		std::cout << "\nNumber of Donuts Left: " << numDonuts << "\n";
	}
	else
	{
		std::cout << "\nYummyyyy! All Gonee\n";
		numDonuts = 0;
	}
}

void itemBoxofDonuts::Description() const
{
	std::cout << "\n(Game Master) A dozen strawberry and chocolate donuts, packaged in a compact box.\n";
}

// Door Class
void itemDoor::UseItem()
{

}

void itemDoor::Description() const
{
	std::cout << "\nA bold red door that's trimmed with white accents, and a circular paned window towards the top.\n";
}
