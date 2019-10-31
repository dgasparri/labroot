#pragma once
#include <iostream>

class ParticleType {
    const char* const fName;
    const double fMass;
    const int fCharge;
public:
    ParticleType(char* fNameC, double fMassC, int fChargeC);
    const char* const getFName() const;
    double getFMass() const;
    double getFCharge() const;
    virtual void Print() const;
};