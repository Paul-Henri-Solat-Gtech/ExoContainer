#include "inventory.h"

void Inventory::ShowInventory() 
{
    std::cout << std::endl << "Inventory: ";
    for (int i = 0; i < itemList.size(); i++)
    {
        std::cout << itemList[i].name << "(" << itemList[i].weight << ") ";
    }
    Menu();
}
void Inventory::ShowItem() 
{
    std::cout << std::endl << "Give the item name: ";
    std::string itemName;
    std::cin >> itemName;
    for (int i = 0; i < itemList.size(); i++)
    {
        if (itemList[i].name == itemName)
        {
            std::cout << "The name of the item is "<< itemList[i].name << " and he weight " << itemList[i].weight << "." << std::endl;
        }
    }
    Menu();
}
void Inventory::Add(Item item)
{
    itemList.push_back(item);
}

void Inventory::CreateItem() 
{
    std::cout << std::endl << "Give the item Name : ";
    std::string itemName;
    std::cin >> itemName;
    std::cout << std::endl << "Give the item Weight : ";
    int itemWeight;
    std::cin >> itemWeight;
    Item itemClass;
    Item newItem = itemClass.NewItem(itemName.c_str(), itemWeight);
    std::cout << std::endl << "Would you like to add the '" << newItem.name << "' in your inventory ? (1.Yes/2.No)"<< std::endl;
    int nbChoice;
    std::cin >> nbChoice;
    switch (nbChoice)
    {
    case 1:
        Add(newItem);
        std::cout << "The new item have been added in your inventory !" << std::endl;
        Menu();
        break;
    case 2:
        std::cout << "The new item haven't been added in your inventory !" << std::endl;
        Menu();
        break;
    default:
        break;
    }
}

void Inventory::Delete()
{
    std::cout << std::endl << " Select an item to remove from your inventory : ";
    std::string itemName;
    std::cin >> itemName;

    for (int i = 0; i < itemList.size(); i++)
    {
        if (itemList[i].name == itemName)
        {
            itemList.pop_back();
            std::cout << itemName << " Have been removed from your inventory !" << std::endl;
            ShowInventory();
        }
    }
    Menu();
}

void Inventory::Menu() 
{
    std::cout << std::endl << " - Choose an option - "<<std::endl;
    std::cout << "1. Show all items from your inventory" << std::endl;
    std::cout << "2. Select an item to remove from your inventory" << std::endl;
    std::cout << "3. Create a custom item" << std::endl;
    std::cout << "4. Show the details of an item" << std::endl;
    int optionNb;
    std::cin >> optionNb;
    switch (optionNb)
    {
    case 1:
        ShowInventory();
        break;
    case 2:
        Delete();
        break;
    case 3:
        CreateItem();
        break;
    case 4:
        ShowItem();
        break;
    default:
        break;
    }
}