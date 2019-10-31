#include "ResonanceType.h"

double ResonanceType::getFWidth() const {
    return fWidth;
}

void ResonanceType::Print() const {
    ParticleType::Print();
    std::cout << "Width: " << fWidth << std::endl;
}
ResonanceType::ResonanceType(char* fNameC, double fMassC, int fChargeC, double fWidthC): 
    ParticleType(fNameC, fMassC, fChargeC), fWidth(fWidthC) {
        
}
