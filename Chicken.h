#pragma once
#include "Animal.h"

class CChicken : public CAnimal 
{

public:
    CChicken();
    virtual ~CChicken();
    int NumberOfLegs() { return 2; }
    bool IsChicken() { return true; }
    bool CanFly() { return false; }
};

