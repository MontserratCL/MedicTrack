#ifndef DOCTOR_H
#define DOCTOR_H

#include "Person.h"
#include "Patient.h"
#include <string>
#include <vector>
using namespace std;

//Doctor class that inherits from Person and contains additional information such as specialization, experience and patients.
class Doctor : public Person {
private:
    string specialization;
    int experience;
    vector<Patient*> patients;

public:
    // Constructors (that has the method overloading)
    Doctor(string name, string id, string phone, string specialization);
    Doctor(string name, string id, string phone, string specialization, int experience);
    
    // Getters
    string getSpecialization();
    
    // Methods (with method overloading)
    void addPatient(Patient* patient);
    void addPatient(string name, string id, string phone);
    
    // Other methods 
    int getPatientCount();
    
    // Pure virtual function from Person (method overriding)
    string getInfo() override;
    
    // Operator overloading
    bool operator==(Doctor& other);
};

#endif
