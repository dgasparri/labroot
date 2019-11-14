#include "ParticleType.h"

const char* const ParticleType::getName() const {
    return fName;
}
double ParticleType::getMass() const {
    return fMass;
}
double ParticleType::getCharge() const {
    return fCharge;
}

double ParticleType::getWidth() const {
    return 0.0;
};

void ParticleType::Print() const {
    std::cout << "Particle Name: " << fName << std::endl
                << "Mass: " << fMass << std::endl
                << "Charge: " << fCharge << std::endl;
}

ParticleType::ParticleType(const char* fName, double fMass, int fCharge): 
    fName(fName), fMass(fMass), fCharge(fCharge) {

}
