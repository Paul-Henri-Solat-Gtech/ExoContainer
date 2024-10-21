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