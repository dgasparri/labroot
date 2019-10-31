#include "ResonanceType.h"

double ResonanceType::getWidth() const {
    return fWidth;
}

void ResonanceType::Print() const {
    ParticleType::Print();
    std::cout << "Width: " << fWidth << std::endl;
}
ResonanceType::ResonanceType(char* fName, double fMass, int fCharge, double fWidth): 
    ParticleType(fName, fMass, fCharge), fWidth(fWidth) {
        
}
