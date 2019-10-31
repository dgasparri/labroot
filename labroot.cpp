#include <iostream>
#include "ParticleType.h"
#include "ResonanceType.h"
#include "Particle.h"

int main() {
    /*
    ResonanceType rp("res-p1", 0.74f, 4, 3.14f);
    rp.Print();
    
    ParticleType *list[3];
    list[0] = new ParticleType("p2", 0.74f, 3);
    list[1] = new ResonanceType("res-p3", 0.74f, 4, 3.14f);
    list[2] = &rp;
    for(int x=0; x<3; x++) {
        list[x]->Print();
        std::cout<<std::endl;
    }
/*
    Particle::AddParticleType("a3", 0.74f, 4, 3.14f);
    Particle::AddParticleType("a4", 0.74f, 3);
    Particle::AddParticleType("a5", 0.74f, 4, 3.14f);
    Particle::AddParticleType("a6", 0.74f, 4, 3.14f);
    Particle::AddParticleType("a7", 0.74f, 3);
    Particle::AddParticleType("a8", 0.74f, 4, 3.14f);
    Particle::AddParticleType("a9", 0.74f, 4, 3.14f);
    Particle::AddParticleType("a6", 0.74f, 4, 3.14f);
    Particle::AddParticleType("a10", 0.74f, 3);
    Particle::AddParticleType("a11", 0.74f, 4, 3.14f);
    Particle::AddParticleType("a12", 0.74f, 4, 3.14f);

    Particle::AddParticleType("a6", 0.74f, 4, 3.14f);
    */
    

    Particle::AddParticleType("muon", 0.74f, 3);
    Particle::AddParticleType("electron", 0.15f, 8, 12.0f);
    Particle::PrintParticleTypes();

    // p1
    Particle particle1("muon", 0.4, 0.6, 0.8);
    
    // p2
    Particle particle2("electron", 0.3, 0.5, 0.7);


    std::cout<<std::endl<< "Printng particle 1 (muon):"<<std::endl;
    particle1.Print();
    std::cout<<std::endl<< "Printng particle 2 (muon):"<<std::endl;
    particle2.Print();
    std::cout <<std::endl<<  "E muon (p1) : " << particle1.E() << std::endl
                << "E electron (p2): " << particle2.E() << std::endl
                << "InvMass p1 e p2 : " << particle1.InvMass(particle2) << std::endl;

 
    //std::cin.get();
}