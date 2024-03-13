// Prevents Multiple File Includes
#pragma once
class Items
{
public:
	Items();

	~Items();

	virtual void UseItem() = 0;
	virtual void Description() const = 0;
};

class itemCat : public Items
{
	void UseItem();
	void Description();

};

class itemLamp : public Items
{
	void UseItem();
	void Description() const;
};

class itemBoxofDonuts : public Items
{
	void UseItem();
	void Description() const;
};


