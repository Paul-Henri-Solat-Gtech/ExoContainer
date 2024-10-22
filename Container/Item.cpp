#include "Item.h"

Item::Item(const char* itemName, int itemWeight) : name(itemName), weight(itemWeight)
{
	std::cout << "Created Item : " << name << "(" << weight << ") !" << std::endl;
}
Item::Item()
{

}

Item Item::NewItem(const char* itemName, int itemWeight) 
{
	Item newItem(itemName, itemWeight);
	return newItem;
}

bool Item::SortByName(const Item& itemA, const Item& itemB)
{
	return strcmp(itemA.name, itemB.name) < 0;
}
bool Item::SortByWeightAsc(const Item& itemA, const Item& itemB)
{
	return itemA.name < itemB.name;
}
bool Item::SortByWeightDesc(const Item& itemA, const Item& itemB)
{
	return itemA.name > itemB.name;
}
