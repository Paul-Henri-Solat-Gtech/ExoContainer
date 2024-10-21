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

	const char* name;
	int weight;
};

#endif
