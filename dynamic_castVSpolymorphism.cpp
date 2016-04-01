#include "stdafx.h"
#include "Animal.h"
#include "Chicken.h"
#include "Fox.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>

std::vector<CAnimal*> animals;
void InitializeAnimals();
void TestIteration(std::clock_t &startDynamicCast, std::clock_t &endDynamicCast, std::clock_t &startPoly, std::clock_t &endPoly);
void NOOP()
{
   //NOOP 
}

void TestIterationValues(int iter)
{
    for (int i = 0; i < iter; i++)
    {
        std::clock_t startD, endD, startP, endP;
        TestIteration(startD, endD, startP, endP);
        std::cout << "Time Dynamic_Cast: " << (endD - startD) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
        std::cout << "Time Polymorphism: " << (endP - startP) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
    }

}

int _tmain(int argc, _TCHAR* argv[])
{
    InitializeAnimals();
    TestIterationValues(10);

    char p;
    std::cin >> p;

	return 0;
}

void InitializeAnimals()
{
    int c = 0;
    //randomly picked 8.5 million entiries 
    for (int i = 0; i < 8500000; i++)
    {       
        CAnimal* animal = __nullptr;
        if (i%5==0)
            animal = new CFox();
        else
            animal = new CChicken();

        animals.push_back(animal);        
    }
}

void TestIteration(std::clock_t &startDynamicCast, std::clock_t &endDynamicCast, std::clock_t &startPoly, std::clock_t &endPoly)
{
    startDynamicCast = std::clock();
    int i = 0;
    for each(CAnimal* animal in animals)
    {
            if (dynamic_cast<CFox*>(animal))
            NOOP();
        else if (dynamic_cast<CChicken*>(animal))
            NOOP();
    }

    endDynamicCast = std::clock();

    //polymorphism
    startPoly = std::clock();

    for each(CAnimal* animal in animals)
    {
        if (animal->IsFox())
            NOOP();
        else if (animal->IsChicken())
            NOOP();
    }
    endPoly = std::clock();
    
}

