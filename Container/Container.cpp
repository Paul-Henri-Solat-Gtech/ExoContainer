#include <vector>
#include <iostream>
#include <list>
#include <set>
#include <algorithm>
#include <chrono>

#include "Inventory.h"

//intro
std::vector<int> vectList = { 5, 4, 9, 10, 5, 6 };
std::list<int> listList = { 5, 4, 9, 10, 5, 6 };
std::set<int> setList = { 5, 4, 9, 10, 5, 6 };
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

//exo 1
void CreateItemAndInventory() 
{
    Item goldBlade("GoldBlade", 50);
    Item cheese("BigPieceOfCheese", 95);
    Item magicBook("MagicBook", 40);
    Item mindStone("MindStone", 5);

    //Inventory newInventory(200);
    Inventory newInventory;
    newInventory.Add(goldBlade);
    newInventory.Add(cheese);
    newInventory.Add(magicBook);
    newInventory.Add(mindStone);
    newInventory.Menu();
}

//exo 2
void RandomVector() 
{
    std::srand(std::time(0));
    std::vector<int> vectRandom;
    int oneMillion = 1000000;
    auto startChrono = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < oneMillion; i++)
    {
        vectRandom.push_back(rand());
    }
    auto endChrono = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = endChrono - startChrono;
    std::cout << "Vector Taked:" << duration.count() << " s" << std::endl;

    startChrono = std::chrono::high_resolution_clock::now();
    vectRandom.pop_back();
    endChrono = std::chrono::high_resolution_clock::now();
    duration = endChrono - startChrono;
    std::cout << "Vector remove Taked:" << duration.count() << " s" << std::endl;

    startChrono = std::chrono::high_resolution_clock::now();
    int nbtofind = 2;
    for(int i = 0; i< vectRandom.size() ; i++)
    {
        if (vectRandom[i] == nbtofind) 
        {
            endChrono = std::chrono::high_resolution_clock::now();
            duration = endChrono - startChrono;
            std::cout << "Vector found nb Taked:" << duration.count() << " s" << std::endl;

        }
    }
}
void RandomList()
{
    std::srand(std::time(0));
    std::list<int> listRandom;
    int oneMillion = 1000000;
    auto startChrono = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < oneMillion; i++)
    {
        listRandom.push_back(rand());
    }
    auto endChrono = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = endChrono - startChrono;
    std::cout << "List Taked:" << duration.count() << " s" << std::endl;

    startChrono = std::chrono::high_resolution_clock::now();
    listRandom.pop_back();
    endChrono = std::chrono::high_resolution_clock::now();
    duration = endChrono - startChrono;
    std::cout << "List remove Taked:" << duration.count() << " s" << std::endl;

}
void RandomSet()
{
    std::srand(std::time(0));
    std::set<int> setRandom;
    int oneMillion = 1000000;
    auto startChrono = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < oneMillion; i++)
    {
        setRandom.insert(rand());
    }
    auto endChrono = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = endChrono - startChrono;
    std::cout << "Set Taked:" << duration.count() << " s" << std::endl;
    
    startChrono = std::chrono::high_resolution_clock::now();
    setRandom.erase(10);
    endChrono = std::chrono::high_resolution_clock::now();
    duration = endChrono - startChrono;
    std::cout << "List remove Taked:" << duration.count() << " s" << std::endl;
}
void ChronoTest() 
{
    RandomVector();
    RandomList();
    RandomSet();
}

//exo 3
template<typename T>
void SearchLowestNumber(T list) 
{
    // Initialiser le plus petit chiffre avec la plus grande valeur possible
    int minNumber = std::numeric_limits<int>::max();

    for (int i=0; i < list.size(); i++)
    {
        if (minNumber > list[i]) 
        {
            minNumber = list[i];
        }
    }
    std::cout << "The lowest num is: " << minNumber << std::endl;
}

template<typename T>
void insertLast(std::vector<T> vectorList, T element) 
{
    vectorList.push_back(element);
    std::cout << "The list has now " << vectorList.size() << " elements" << std::endl;
}
int main()
{
    SearchLowestNumber(vectList);
    insertLast(vectList, 8);
}
