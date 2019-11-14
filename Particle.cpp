#include <cmath>  // for M_PI
#include <cstdlib> //for RAND_MAX
#include "Particle.h"


const int Particle::fMaxNumParticleTypes = 10;
int Particle::fNumParticleTypes = 0;
ParticleType* Particle::fParticleTypes[10];



Particle::Particle(const char* fName, double fPx, double fPy, double fPz):
    fPx(fPx), fPy(fPy), fPz(fPz) {
        setType(fName);
        
    }

Particle::Particle() {
    
}


int Particle::getParticleIndex() {
    return fIParticle;
}

int Particle::setType(int fIndex) {
    if (fIndex >= fNumParticleTypes) {
        std::cout << "Particle Type with index " << fIndex << " not in list"<<std::endl;
        fIndex = -1;
    }
    fIParticle = fIndex;
    return fIndex;
}

int Particle::setType(const char *fNameC) {
    //std::cout<<"Particle type "<<fNameC<<std::endl;
    fIParticle = FindParticle(fNameC);
    if (-1 == fIParticle) {
        std::cout << "Particle Type with name " << fNameC << " not in list"<<std::endl;
    }
    //fName = fNameC;
    return fIParticle;
}

void Particle::Print() const {
    std::cout<<"Particle Type index: " << fIParticle << std::endl
            <<"Particle Name: " << getName() << std::endl
            <<"Impulse (x, y, z): (" << fPx << "," << fPy << "," <<fPz << ")" << std::endl; 

}

const char * Particle::getName() const {
    return fParticleTypes[fIParticle]->getName();
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
    if(fIParticle != -1) 
        return fParticleTypes[fIParticle]->getMass();
    else
        return 0;
}

void Particle::setCartesian(double px, double py, double pz) {
    fPx = px;
    fPy = py;
    fPz = pz;
    fMomentum = std::sqrt(std::pow(fPx, 2.0) + std::pow(fPy, 2.0) + std::pow(fPz, 2.0));    
    fTheta = 0;
    fPhi = 0;
    if (fMomentum == 0) return; 
    
    if (px == 0 && py >0) {
        fPhi = M_PI / 2.0;
    } else if (px == 0 && py <0) {
        fPhi = 3.0 * M_PI / 2.0;
    } else if (px > 0 && py >=0) {
        fPhi = atan(py/px);
    } else if ((px > 0 && py <0) 
                || (px < 0 && py >0)) {
        fPhi = atan(py/px) + 2.0 * M_PI;
    } else if (px < 0 && py <=0) {
        fPhi = atan(py/px) + M_PI; 
    } 

}

/*
            randPhi = rng->Uniform(0, 2.0 * M_PI );
            randTheta = rng->Uniform(0, M_PI );
            randInpulse = rng->Exp(expT);
*/
void Particle::setPolar(double phi, double theta, double momentum) {
    fPhi = phi;
    fTheta = theta;
    fMomentum = momentum;
    fPx = momentum * sin(theta) * cos(phi);
    fPy = momentum * sin(theta) * sin(phi);
    fPz = momentum * cos(theta);
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
int Particle::AddParticleType(const char* fNameC, double fMassC, int fChargeC, double fWidthC) {
    
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
int Particle::FindParticle(const char *pName) {
    int x;
    for(x=0; x<fNumParticleTypes; x++) {
        const char* const itemName = fParticleTypes[x]->getName();
        if (0 == strcmp(pName, itemName)) {
            //std::cout<<"Found particle: "<<itemName << " (index "<<x<<")"<<std::endl;
            return x;
        }
    }
    //If not found, returns -1
    return -1;
}



// ----- Codice da file codice extra

int Particle::decay2Body(Particle &dau1,Particle &dau2) const {
    double massMot = getMass();
    // std::cout<<"Mass: "<<massMot<<std::endl;

    if(massMot == 0.0){
        printf("Decayment cannot be preformed if mass is zero\n");
        return 1;
    }

    double massDau1 = dau1.getMass();
    double massDau2 = dau2.getMass();
    //std::cout<<"Masses: "<<massDau1<<", "<<massDau2<<std::endl;
    //std::cout<<"Particle fIparticle: "<<fIParticle<<std::endl;
    if(-1 < fIParticle){ // add width effect

        // gaussian random numbers

        float x1, x2, w, y1, y2;

        double invnum = 1./RAND_MAX;
        do {
            x1 = 2.0 * rand()*invnum - 1.0;
            x2 = 2.0 * rand()*invnum - 1.0;
            w = x1 * x1 + x2 * x2;
        } while ( w >= 1.0 );

        w = sqrt( (-2.0 * log( w ) ) / w );
        y1 = x1 * w;
        y2 = x2 * w;

        massMot += fParticleTypes[fIParticle]->getWidth() * y1;

    }

    if(massMot < massDau1 + massDau2){
        printf("Decayment cannot be preformed because mass is too low in this channel\n");
        return 2;
    }

    double pout = sqrt((massMot*massMot - (massDau1+massDau2)*(massDau1+massDau2))*(massMot*massMot - (massDau1-massDau2)*(massDau1-massDau2)))/massMot*0.5;

    double norm = 2* M_PI / RAND_MAX;

    double phi = rand()*norm;
    double theta = rand()*norm*0.5 - M_PI/2.;
    dau1.setCartesian(pout*sin(theta)*cos(phi),pout*sin(theta)*sin(phi),pout*cos(theta));
    dau2.setCartesian(-pout*sin(theta)*cos(phi),-pout*sin(theta)*sin(phi),-pout*cos(theta));

    double energy = sqrt(fPx*fPx + fPy*fPy + fPz*fPz + massMot*massMot);

    double bx = fPx/energy;
    double by = fPy/energy;
    double bz = fPz/energy;

    dau1.boost(bx,by,bz);
    dau2.boost(bx,by,bz);

    return 0;
}
void Particle::boost(double bx, double by, double bz)
{

    double energy = E();

    //Boost this Lorentz vector
    double b2 = bx*bx + by*by + bz*bz;
    double gamma = 1.0 / sqrt(1.0 - b2);
    double bp = bx*fPx + by*fPy + bz*fPz;
    double gamma2 = b2 > 0 ? (gamma - 1.0)/b2 : 0.0;

    fPx += gamma2*bp*bx + gamma*bx*energy;
    fPy += gamma2*bp*by + gamma*by*energy;
    fPz += gamma2*bp*bz + gamma*bz*energy;
}