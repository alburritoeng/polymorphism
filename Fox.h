#pragma once
#include "Animal.h"

class CFox : public CAnimal
{
public:
    CFox();
    virtual ~CFox();
    int NumberOfLegs() { return 4; }
    bool IsFox() { return true; }
};

