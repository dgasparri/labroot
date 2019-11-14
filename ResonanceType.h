#pragma once
#include "ParticleType.h"
#include <iostream>

class ResonanceType : public ParticleType {
    const double fWidth;
public:
    double getWidth() const;
    void Print() const;
    ResonanceType(const char* fName, double fMass, int fCharge, double fWidth);
};