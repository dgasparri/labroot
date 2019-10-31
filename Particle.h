#include <iostream>
#include <math.h>
#include "ParticleType.h"
#include "ResonanceType.h"

class Particle {
public:
    Particle(char* fName, double fPx, double fPy, double fPz);
    int getParticleIndex();
    int setParticleType(int fIndex);
    int setParticleType(char *fNameC);
    void Print() const;
    double getPx() const;
    double getPy() const;
    double getPz() const;
    double getMass() const;
    void setP(double px, double py, double pz);
    double E() const;
    double InvMass(Particle& p) const;

    static void InitializeParticleType();
    static int AddParticleType(char* fNameC, double fMassC, int fChargeC, double fWidthC = 0);

    static void PrintParticleTypes();

private:
    static const int fMaxNumParticleTypes; // = 10;
    static int fNumParticleTypes;
    static ParticleType *fParticleTypes[10];
    int fIParticle; //-1 if not set
    double fPx, fPy, fPz;
    char* fName; //costante? Non lo specifica

    static int FindParticle(char *pName);

};