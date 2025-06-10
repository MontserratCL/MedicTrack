#ifndef PATIENT_H
#define PATIENT_H

#include "Person.h"
#include <string>
using namespace std;

//Patient class inherits from Person and contains additional medical information such as blood type and allergies.
class Patient : public Person {
private:
    string bloodType;
    string allergies;

public:
    // Constructors (shows the method overloading)
    Patient(string name, string id, string phone, string bloodType);
    Patient(string name, string id, string phone, string bloodType, string allergies);
    
    // Getters
    string getBloodType();
    string getAllergies();
    
    // Setter
    void setAllergies(string allergies);
    
    // Methods (method overloading)
    void updateInfo(string bloodType);
    void updateInfo(string bloodType, string allergies);
    
    // Pure virtual function from Person (that is the method overriding)
    string getInfo() override;
    
    // Operator overloading
    string operator+(Patient& other);
};

#endif
