#pragma once
#include <iostream>

class ParticleType {
    const char* const fName;
    const double fMass;
    const int fCharge;
public:
    ParticleType(const char* fName, double fMass, int fCharge);
    const char* const getName() const;
    double getMass() const;
    double getCharge() const;
    virtual double getWidth() const;
    virtual void Print() const;
};