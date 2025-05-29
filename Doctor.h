#ifndef DOCTOR_H
#define DOCTOR_H

#include "Person.h"
#include "Patient.h"
#include <string>
#include <vector>
using namespace std;

class Doctor : public Person {
private:
    string specialization;
    int experience;
    vector<Patient*> patients;

public:
    // Constructor
    Doctor(string name, string id, string phone, string specialization);
    Doctor(string name, string id, string phone, string specialization, int experience);
    
    // Getters
    string getSpecialization();
    
    // Methods
    void addPatient(Patient* patient);
    void addPatient(string name, string id, string phone);
   
    // Pure virtual function from person
    string getInfo() override;
};

#endif
