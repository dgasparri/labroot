#include <iostream>
#include "ParticleType.h"
#include "ResonanceType.h"
#include "Particle.h"

int main() {
    ParticleType *list[2];
    list[0] = new ParticleType("pippo", 0.74f, 3);
    list[1] = new ResonanceType("res-pippo", 0.74f, 4, 3.14f);
    for(int x=0; x<2; x++) {
        list[x]->Print();
        std::cout<<std::endl;
    }
    Particle::AddParticleType("a1", 0.74f, 3);
    Particle::AddParticleType("a2", 0.74f, 4, 3.14f);
    Particle::AddParticleType("a3", 0.74f, 4, 3.14f);
    Particle::AddParticleType("a4", 0.74f, 3);
    Particle::AddParticleType("a5", 0.74f, 4, 3.14f);
    Particle::AddParticleType("a6", 0.74f, 4, 3.14f);
    Particle::AddParticleType("a7", 0.74f, 3);
    Particle::AddParticleType("a8", 0.74f, 4, 3.14f);
    Particle::AddParticleType("a9", 0.74f, 4, 3.14f);
    Particle::AddParticleType("a10", 0.74f, 3);
    Particle::AddParticleType("a11", 0.74f, 4, 3.14f);
    Particle::AddParticleType("a12", 0.74f, 4, 3.14f);

    Particle::AddParticleType("a6", 0.74f, 4, 3.14f);

    Particle::PrintParticleTypes();
    
    Particle particle("a7", 0.4, 0.6, 0.7);

 
    std::cin.get();
}