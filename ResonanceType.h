#pragma once
#include "ParticleType.h"
#include <iostream>

class ResonanceType : public ParticleType {
    const double fWidth;
public:
    double getFWidth() const;
    void Print() const;
    ResonanceType(char* fNameC, double fMassC, int fChargeC, double fWidthC);
};