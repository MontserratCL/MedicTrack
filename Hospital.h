#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "Department.h"
#include "Patient.h"
#include <string>
#include <vector>
using namespace std;

class Hospital {
private:
    string name;
    string address;
    vector<Department*> departments;
    vector<Patient*> patients;

public:
    // Cnstructors
    Hospital(string name);
    Hospital(string name, string address);
    
    // Getter
    string getName();
    
    // Methods
    void addDepartment(Department* department);
    void addPatient(Patient* patient);
    Patient* findPatient(string id);
    int getTotalPatients();
};

#endif
