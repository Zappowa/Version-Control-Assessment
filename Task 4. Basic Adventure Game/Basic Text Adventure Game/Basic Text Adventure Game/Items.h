// Prevents Multiple File Includes
#pragma once


// Base Class (Items)
class Items
{
public:

	// Pure Virtual Functions for Derived Classes
	virtual void UseItem() = 0;
	virtual void Description() const = 0;
};

// Derived Class inheriting (Items)
class itemCat : public Items
{
public:

	// Class Functions
	void UseItem();
	void Description() const;

private:

	// Boolean Item State
	bool purring = false;
};

// Derived Class inheriting (Items)
class itemLamp : public Items
{
public:

	// Class Functions
	void UseItem();
	void Description() const;

private:

	// Boolean Item State
	bool turnedOn = false;
};

// Derived Class inheriting (Items)
class itemBoxofDonuts : public Items
{
public:

	// Class Functions
	void UseItem();
	void Description() const;

private:

	// Int Count Donuts
	int numDonuts = 12;
};

// Derived Class inheriting (Items)
class itemDoor : public Items
{
public:

	// Class Functions
	void UseItem();
	void Description() const;
};
