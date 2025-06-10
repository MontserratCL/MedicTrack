#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "Department.h"
#include "Patient.h"
#include <string>
#include <vector>
using namespace std;

//Hospital class that manages the entire hospital system
//This contains the departments and patients
class Hospital {
private:
    string name;
    string address;
    vector<Department*> departments;
    vector<Patient*> patients;

public:

    // Constructors (method overloading)
    Hospital(string name);
    Hospital(string name, string address);
    
    // Getters
    string getName();
    string getAddress();
    
    // Methods
    void addDepartment(Department* department);
    void addPatient(Patient* patient);
    Patient* findPatient(string id);
    int getTotalPatients();
    string getAllHospitalInfo(); // Method to display complete hospital information
};

#endif
