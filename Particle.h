#pragma once

#include <iostream>
#include <math.h>
#include "ParticleType.h"
#include "ResonanceType.h"

class Particle {
public:
    Particle();
    Particle(const char* fName, double fPx, double fPy, double fPz);
    int getParticleIndex();
    int setType(int fIndex);
    int setType(const char *fNameC);
    void Print() const;
    double getPx() const;
    double getPy() const;
    double getPz() const;
    double getMass() const;
    const char * getName() const;
    void setCartesian(double px, double py, double pz);
    void setPolar(double angle, double azimuth, double momentum);
    double E() const;
    double InvMass(Particle& p) const;
    int decay2Body(Particle &dau1,Particle &dau2) const;

    static int AddParticleType(const char* fNameC, double fMassC, int fChargeC, double fWidthC = 0);
    static void PrintParticleTypes();

private:
    static const int fMaxNumParticleTypes; // = 10;
    static int fNumParticleTypes;
    static ParticleType *fParticleTypes[10];
    int fIParticle; //-1 if not set
    double fPhi, fTheta, fMomentum;
    double fPx, fPy, fPz;
    //char* fName; 

    static int FindParticle(const char *pName);
    void boost(double bx, double by, double bz);


};