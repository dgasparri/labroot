#include "Particle.h"

const int Particle::fMaxNumParticleTypes = 10;
int Particle::fNumParticleTypes = 0;
ParticleType* Particle::fParticleTypes[10];



Particle::Particle(char* fName, double fPx, double fPy, double fPz):
    fName(fName), fPx(fPx), fPy(fPy), fPz(fPz) {

        setParticleType(fName);
        /*
        fIParticle = Particle::FindParticle(fName);
        if(-1 == fIParticle) {
            std::cout << "Particle " << fName << " not found" << std::endl;
        }
        */
    }

int Particle::getParticleIndex() {
    return fIParticle;
}

int Particle::setParticleType(int fIndex) {
    if (fIndex >= fNumParticleTypes) {
        std::cout << "Particle Type with index " << fIndex << " not in list"<<std::endl;
        fIndex = -1;
    }
    fIParticle = fIndex;
    return fIndex;
}

int Particle::setParticleType(char *fNameC) {
    int fIParticle = FindParticle(fNameC);
    if (-1 == fIParticle) {
        std::cout << "Particle Type " << fNameC << " not in list"<<std::endl;
    }
    return fIParticle;
}

void Particle::Print() const {
    std::cout<<"Particle Type index: " << fIParticle << std::endl
            <<"Particle Name: " << fName << std::endl
            <<"Impulse (x, y, z): (" << fPx << "," << fPy << "," <<fPz << ")" << std::endl; 

}

double Particle::getPx() const {
    return fPx;
}

double Particle::getPy() const {
    return fPy;
}

double Particle::getPz() const {
    return fPz;
}

double Particle::getMass() const {
    return fParticleTypes[fIParticle]->getFMass();
}

void Particle::setP(double px, double py, double pz) {
    fPx = px;
    fPy = py;
    fPz = pz;
}

double Particle::E() const {
    double mass_sqr = pow(getMass(),2);
    double p = pow(fPx,2) + pow(fPy, 2) + pow(fPx, 2);
    return sqrt(mass_sqr + p);
}



double Particle::InvMass(Particle& p) const {
    double E1 = E();
    double E2 = p.E();
    double E_sqr = pow(E1+E2,2);

    double p_sqr = pow(fPx + p.getPx(),2) 
            + pow(fPy + p.getPy(), 2) 
            + pow(fPz + p.getPz(), 2);
    return sqrt(E_sqr - p_sqr);

}


//static
void Particle::InitializeParticleType() {
    fNumParticleTypes = 0;

}


//static
int Particle::AddParticleType(char* fNameC, double fMassC, int fChargeC, double fWidthC) {
    
    if(fNumParticleTypes >= fMaxNumParticleTypes) {
        std::cout<<"Max number of possible particle types reached"<<std::endl;
        return -1;
    }

    int pIndex = FindParticle(fNameC);
    if (-1 == pIndex) {
        if (fWidthC) {
            fParticleTypes[fNumParticleTypes] = 
                new ResonanceType(fNameC, fMassC, fChargeC, fWidthC);
        } else {
            fParticleTypes[fNumParticleTypes] = 
                new ParticleType(fNameC, fMassC, fChargeC);
        }
        return fNumParticleTypes++;
    } else {
        std::cout<<"Particle " << fNameC << " already in list"<<std::endl;
        return pIndex;
    }
}


//static
void Particle::PrintParticleTypes() {
    std::cout<<"Printng " << fNumParticleTypes << " particle types:"<<std::endl;
    for(int x = 0; x<fNumParticleTypes; x++) {
        fParticleTypes[x]->Print();
        std::cout<<std::endl;
    }
}

//static
int Particle::FindParticle(char *pName) {
    int x;
    for(x=0; x<fNumParticleTypes; x++) {
        const char* const itemName = fParticleTypes[x]->getFName();
        if (0 == strcmp(pName, itemName)) {
            std::cout<<"Found particle: "<<itemName << " (index "<<x<<")"<<std::endl;
            return x;
        }
    }
    //If not found, returns NULL
    return NULL;
}
