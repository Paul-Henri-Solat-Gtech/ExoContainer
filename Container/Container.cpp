#include <vector>
#include <iostream>
#include <list>
#include <set>
#include <algorithm>

#include "Inventory.h"

std::vector<int> vectList = { 5, 2, 9, 1, 5, 6 };
std::list<int> listList = { 5, 2, 9, 1, 5, 6 };
std::set<int> setList = { 5, 2, 9, 1, 5, 6 };

void PrintVectorList() 
{
    std::cout << "VectorList: ";
    for (int i = 0; i < vectList.size(); i++)
    {
        std::cout << vectList[i] << " ";
    }
}
void PrintListList()
{
    std::cout << std::endl << "ListList: ";
    for (std::list<int>::iterator i = listList.begin(); i != listList.end(); i++)
    {
        std::cout << *i << " ";
    }
}

void Container() 
{
    int nb;

    vectList.push_back(10);
    listList.push_back(10);
    setList.insert(10);

    vectList.pop_back();
    listList.pop_back();
    setList.erase(10);

    PrintVectorList();
    PrintListList();
    std::cout << std::endl << "SetList: ";
    for (int i = 0; i < setList.size(); i++)
    {
        //std::cout << setList.find(i);
    }

    std::cout << "Add a number to the vector List : ";

    std::cin >> nb;
    vectList.push_back(nb);
    PrintVectorList();

    std::cout << std::endl << "Remove a number to the vector List : ";
    std::cin >> nb;
    vectList.erase(std::remove(vectList.begin(), vectList.end(), nb), vectList.end());
    PrintVectorList();

    std::cout << std::endl << "Re-order the vector List : ";
    std::sort(vectList.begin(), vectList.end());
    PrintVectorList();
}

int main()
{
    Item goldBlade("GoldBlade", 50);
    Item cheese("BigPieceOfCheese", 875);
    Item magicBook("MagicBook", 40);
    Item mindStone("MindStone", 5);

    Inventory newInventory;
    newInventory.Add(goldBlade);
    newInventory.Add(cheese);
    newInventory.Add(magicBook);
    newInventory.Add(mindStone);

    newInventory.Menu();
}
