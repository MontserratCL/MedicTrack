#ifndef PATIENT_H
#define PATIENT_H

#include "Person.h"
#include <string>
using namespace std;

class Patient : public Person {
private:
    string bloodType;
    string allergies;

public:
    // Constructors
    Patient(string name, string id, string phone, string bloodType);
    Patient(string name, string id, string phone, string bloodType, string allergies);
    
    // Getters
    string getBloodType();
    string getAllergies();
    
    // Methods
    void updateInfo(string bloodType);
    void updateInfo(string bloodType, string allergies);
    
    // Pure virtual funct from person
    string getInfo() override;
};

#endif
