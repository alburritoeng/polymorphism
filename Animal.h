#pragma once
class CAnimal
{
public:
    CAnimal();
    virtual ~CAnimal();
    virtual int NumberOfLegs();
    virtual bool IsFox() { return false; }
    virtual bool IsChicken() { return false; }
    virtual bool IsMammal() { return false; }
    virtual bool CanFly() { return false; }
};

