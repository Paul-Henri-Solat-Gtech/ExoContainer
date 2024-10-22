#ifndef item_h
#define item_h

#include <iostream>

class Item
{
protected:

public:
	Item(const char* itemName, int itemWeight);
	Item();
	Item NewItem(const char* itemName, int itemWeight);
	static bool SortByName(const Item& itemA, const Item& itemB);
	static bool SortByWeightAsc(const Item& itemA, const Item& itemB);
	static bool SortByWeightDesc(const Item& itemA, const Item& itemB);
	const char* name;
	int weight;
};

#endif
