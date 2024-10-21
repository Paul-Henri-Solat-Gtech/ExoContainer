#include "inventory.h"

//Inventory::Inventory(int inventoryWeightLimit):weightLimit(inventoryWeightLimit)
//{
//    std::cout << "Your bag limit weight is : " << weightLimit << std::endl;
//    Menu();
//}

void Inventory::DetailledShowInventory() 
{
    std::cout << "Your bag contain : "<< std::endl;
    int bagTotalWeight = 0;
    int nbItem = 0;
    for (int i = 0; i < itemList.size(); i++)
    {
        std::cout << itemList[i].name << std::endl;
        bagTotalWeight += itemList[i].weight;
        nbItem++;
    }
    std::cout << "And your bag total weight is : " << bagTotalWeight << std::endl;
    std::cout << "The weight of the items in your bag are around : " << bagTotalWeight/nbItem << std::endl;
    Menu();
}

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

void Inventory::SortingInventory() 
{
    for (int i = 0; i < itemList.size(); i++)
    {
        
    }
}
void Inventory::SortingItem()
{
    std::cout << std::endl << "Search all item with (1.UpperWeight, 2.lowerWeight) : ";
    int choice;
    std::cin >> choice;
    std::cout << std::endl << " Select a weight : ";
    int weight;
    std::cin >> weight;
    int nbItem = 0;
    switch (choice)
    {
    case 1:
        for (int i = 0; i < itemList.size(); i++)
        {
            if (itemList[i].weight > weight)
            {
                nbItem++;
                std::cout << itemList[i].name << "(" << itemList[i].weight << ") ";
            }
        }
        std::cout << "There is " << nbItem << " items with a weight supperior to " << weight;
        Menu();
    case 2:
        for (int i = 0; i < itemList.size(); i++)
        {
            if (itemList[i].weight < weight)
            {
                nbItem++;
                std::cout << itemList[i].name << "(" << itemList[i].weight << ") ";
            }
        }
        std::cout << "There is " << nbItem << " items with a weight inferior to " << weight;
        Menu();
    default:
        break;
    }

}

void Inventory::Menu() 
{
    std::cout << std::endl << " - Choose an option - "<<std::endl;
    std::cout << "1. Show all items from your inventory" << std::endl;
    std::cout << "2. Select an item to remove from your inventory" << std::endl;
    std::cout << "3. Create a custom item" << std::endl;
    std::cout << "4. Show the details of an item" << std::endl;
    std::cout << "5. Show the details of your inventory" << std::endl;
    std::cout << "6. Show the number of item based on his weight" << std::endl;
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
    case 5:
        DetailledShowInventory();
        break;
    case 6:
        SortingItem();
        break;
    default:
        break;
    }
}