#include <vector>
#include <iostream>
#include <list>
#include <set>
#include <algorithm>
#include <chrono>
#include <type_traits>

#include "Inventory.h"
#include "Projectile.h"
#include "Character.h"

//intro
std::vector<int> vectList = { 5, 4, 9, 10, 5, 6 };
std::vector<float> vectListF = { 5.6f, 4.5f, 9.5f, 10.3f, 5.5f, 6.4f };
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
float SearchLowestNumber(T list) 
{
    float minNumber = std::numeric_limits<float>::max();

    for (int i=0; i < list.size(); i++)
    {
        if (minNumber > list[i]) 
        {
            minNumber = list[i];
        }
    }
    return minNumber;
}
template<typename T>
void InsertLast(std::vector<T> vectorList, T element) 
{
    vectorList.push_back(element);
    std::cout << "The list has now " << vectorList.size() << " elements" << std::endl;
}
template<typename T>
T SumTableValue(std::vector<T> vectorList)
{
    T sum = 0;
    for (int i = 0; i < vectorList.size(); i++)
    {
        sum += vectorList[i];
    }
    return sum;
}
template<typename T>
T AveragingTableValue(std::vector<T> vectorList)
{
    float sum = 0;
    float nbElement = vectorList.size();
    for (int i = 0; i < vectorList.size(); i++)
    {
        sum += vectorList[i];
    }
    if (std::is_same<T, int>::value)
    {
        double doubleResult = sum / nbElement;
        return doubleResult;
    }
    else
    {
        T result = sum / nbElement;
        return result;
    }
}

void TestTemplate() 
{
    InsertLast(vectList, 8);
    std::cout << "The lowest num is: " << SearchLowestNumber(vectList) << std::endl;
    std::cout << "The sum of the table is: " << SumTableValue(vectList) << std::endl;
    std::cout << "The average of this table is: " << AveragingTableValue(vectList) << std::endl;
}

//exo 4
void TestProjectile() 
{
    Projectile newProjectileArrow(1.f, 2, 10.f, 10.f, 50.f, 2.f);
    Projectile newProjectileFireBall(1.f,2.f,10.f,10.f,50.f,2.f);
}

//exo 5
template<typename T>
void CharacterStatistique(std::vector<T> tablePerso) 
{
    std::vector<int> lifePointTabl;
    std::vector<int> attackTabl;
    std::vector<int> defenseTabl;

    for(int i = 0; i < tablePerso.size(); i++)
    {
        lifePointTabl.push_back(tablePerso[i].lifePoint);
        std::cout << "HP added" << std::endl;
    }
    for (int i = 0; i < lifePointTabl.size(); i++)
    {
        std::cout << "Character HP" << lifePointTabl[i] << std::endl;
    }
}

template<typename T>
void CalculStatistique(std::vector<T> tableStat)
{

}

void CreateCharacter() 
{
    std::vector<Character> characterTabl;
    Character elf(100, 50, 1);
    Character dwarf(70,30,50);
    characterTabl.push_back(elf);
    characterTabl.push_back(dwarf);

    CharacterStatistique(characterTabl);
}

int main()
{
    CreateCharacter();
    return 0;
}
