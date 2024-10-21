#ifndef inventory_h
#define inventory_h

#include <vector>
#include <algorithm>

#include "Item.h"

class Inventory
{
protected:
	int weightLimit;

public:
	//Inventory(int inventoryWeightLimit);
	void DetailledShowInventory();
	void ShowInventory();
	void ShowItem();
	void Add(Item item);
	void CreateItem();
	void Delete();
	void SortingInventory();
	void SortingItem();
	void Menu();

	std::vector<Item> itemList = {};
};

#endif 





