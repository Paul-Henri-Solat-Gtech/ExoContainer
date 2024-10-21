#ifndef inventory_h
#define inventory_h

#include <vector>

#include "Item.h"

class Inventory
{
protected:

public:
	void ShowInventory();
	void ShowItem();
	void Add(Item item);
	void CreateItem();
	void Delete();
	void Menu();

	std::vector<Item> itemList = {};
};

#endif 





