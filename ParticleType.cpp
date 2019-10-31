#include "ParticleType.h"

const char* const ParticleType::getFName() const {
    return fName;
}
double ParticleType::getFMass() const {
    return fMass;
}
double ParticleType::getFCharge() const {
    return fCharge;
}
void ParticleType::Print() const {
    std::cout << "Particle Name: " << fName << std::endl
                << "Mass: " << fMass << std::endl
                << "Charge: " << fCharge << std::endl;
}

ParticleType::ParticleType(char* fName, double fMass, int fCharge): 
    fName(fName), fMass(fMass), fCharge(fCharge) {

}
