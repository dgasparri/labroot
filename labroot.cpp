#include <iostream>
#include "TMath.h"
#include "TRandom.h"
#define C_2_FORGeV = 1 // C^2 / 10^9 

#include "ParticleType.h"
#include "ResonanceType.h"
#include "Particle.h"

int labroot() {
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
/ *
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
    * /
    
    / * -------------------------

    Prova per i metodi E() energia e InvMass()

    * /

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

    */


    // ------------- Inizio prova II ---------------


    long int numEvents = 5; //std::pow(10,5);
    const int particleArraySize = 130;
    const int numParticlePerEvent = 100;
    Particle *particleArray[particleArraySize];
    int numParticleInArray = 0;
    int numDecayedParticles = 0;
    const Double_t expT = std::pow(1.0, 9);


    Particle::AddParticleType((const char *)"pionp", 0.13957, 1);
    Particle::AddParticleType((const char *)"pionn", 0.13957, -1);
    Particle::AddParticleType((const char *)"kaonp", 0.49367, 1);
    Particle::AddParticleType((const char *)"kaonn", 0.49367, -1);
    Particle::AddParticleType((const char *)"protonp", 0.93827, 1);
    Particle::AddParticleType((const char *)"protonn", 0.93827, -1);
    Particle::AddParticleType((const char *)"K_star", 0.89166, 0, 0.050 );
    Particle::PrintParticleTypes();


    TRandom *rng = new TRandom2();
    Double_t randPhi;
    Double_t randTheta;
    Double_t randImpulse;
    Double_t randType;

    for(long int event = 0; event <= numEvents; event++) {
        
        //Generate Event Sample
        for(numParticleInArray = 0; numParticleInArray < numParticlePerEvent; numParticleInArray++) {
            randPhi = rng->Uniform(0, 2.0 * M_PI );
            randTheta = rng->Uniform(0, M_PI );
            randImpulse = rng->Exp(expT);

            particleArray[numParticleInArray] = new Particle();
            particleArray[numParticleInArray]->setPolar(randPhi, randTheta, randImpulse);
            randType = rng->Uniform(0, 100);

            /*
            pion[p,n] (+/-) 80% (m=0.13957 GeV/c2, , q=+/-1)
            kaon[p,n] (+/-10% (mK=0.49367 GeV/c2, , qK=+/-1)
            proton[p,n] (+/-) 9% (mp=0.93827 GeV/c2, , qp=+/-1)
            K_star (risonanza) 1% (mk*=0.89166 GeV/c2, , qk*=0,
            */
            if(0 <= randType && randType <40) {
                particleArray[numParticleInArray]->setType("pionp");                
            } else if (40 <= randType && randType <80) {
                particleArray[numParticleInArray]->setType("pionn");
            } else if (80 <= randType && randType <85) {
                particleArray[numParticleInArray]->setType("kaonp");
            } else if (85 <= randType && randType <90) {
                particleArray[numParticleInArray]->setType("kaonp");
            } else if (90 <= randType && randType <94.5) {
                particleArray[numParticleInArray]->setType("protonp");
            } else if (94.5 <= randType && randType <99) {
                particleArray[numParticleInArray]->setType("protonn");
            } else {
                particleArray[numParticleInArray]->setType("K_star");
                Particle *p1 = new Particle();
                Particle *p2 = new Particle();
                if (0 == particleArray[numParticleInArray]->decay2Body(*p1, *p2)) {
                    if(rng->Uniform(0, 1)<0.5) {
                        p1->setType("pionp");
                        p2->setType("kaonn");
                    } else {
                        p1->setType("pionn");
                        p2->setType("kaonp");
                    }
                    if(numParticlePerEvent + numDecayedParticles + 1 >= particleArraySize) {
                        std::cout<<"Unable to insert the decayed particle - array full";
                    }
                    particleArray[ numParticlePerEvent + numDecayedParticles] = p1;
                    numDecayedParticles++;
                    particleArray[ numParticlePerEvent + numDecayedParticles] = p2;
                    numDecayedParticles++;
                }
            }
            



            //myRand = rng->Gaus(sin(i * 3.14 / 180), 0.2);


        }
        //End Generate Event Sample

        numParticleInArray += numDecayedParticles;

        
        //Generate Histograms


        
        // tipi di particelle generati
        // distribuzioni degli angoli azimutali e polari
        // distribuzione dell'impulso, dell'impulso trasverso sqrt(px2+py2) e dell'energia della particella
        // massa invariante fra tutte le particelle generate in ogni evento (per la massa invariante, utilizzare il metodo Particle::InvMass)
        // massa invariante fra tutte le particelle generate in ogni evento, in combinazioni con carica di segno discorde
        // massa invariante fra tutte le particelle generate in ogni evento, in combinazioni con carica di segno concorde
        // massa invariante fra tutte le particelle generate in ogni evento con combinazioni di tipo pione+/Kaone- e pione-/Kaone+
        //massa invariante fra tutte le particelle generate in ogni evento con combinazioni di tipo pione+/Kaone+ e pione-/Kaone-
        // massa invariante fra le particelle generate in ogni evento che derivano dal decadimento della risonanza K* (N.B. considerate solo coppie di particelle figlie che provengono dalla stessa “madre”)



        //Clean memory
        for(int i = 0; i< numParticleInArray; i++) {
            delete particleArray[i];
        }


    }

    return 0;








    


}

/*
int main() {
    int res =  labroot();
    //std::cin.get();
    return res;
}
*/