#include "Hospital.h"

//Constructor for hospital class that initializes the name and sets a default address.
Hospital::Hospital(string name) {
    this->name = name;
    this->address = "Address not specified"; // Default address
}

//Overloaded constructor for Hospital class that has the adress and name
Hospital::Hospital(string name, string address) {
    this->name = name;
    this->address = address;
}

//Getter for hospital name that returns a string with the hospital name.
string Hospital::getName() {
    return name;
}

//Getter for hospital adress that returns a string with the hospital address.
string Hospital::getAddress() {
    return address;
}

// This method adds a department to the hospital's list of departments.
void Hospital::addDepartment(Department* department) {
    departments.push_back(department);
}

// This method adds a patient to the hospital's list of patients.
void Hospital::addPatient(Patient* patient) {
    patients.push_back(patient);
}

// This method searches for a patient by their ID in the hospital's list of patients.
Patient* Hospital::findPatient(string id) {
    for (Patient* patient : patients) {
        if (patient->getId() == id) {
            return patient;
        }
    }
    return nullptr; // Patient not found
}

// This method returns the total number of patients in the hospital.
int Hospital::getTotalPatients() {
    return patients.size();
}


// This method compiles all relevant information about the hospital, including its name, address, number of departments, total patients, and detailed information about each department and patient.
string Hospital::getAllHospitalInfo() {
    string info = "=== " + name + " ===\n";
    info += "Address: " + address + "\n";
    info += "Number of Departments: " + to_string(departments.size()) + "\n";
    info += "Total Patients: " + to_string(patients.size()) + "\n\n";
    
    // Department information
    info += "DEPARTMENTS:\n";
    for (size_t i = 0; i < departments.size(); i++) {
        info += "\n" + to_string(i + 1) + ". " + departments[i]->getAllStaffInfo();
    }
    
    // Patient information
    info += "\nPATIENTS:\n";
    for (size_t i = 0; i < patients.size(); i++) {
        info += to_string(i + 1) + ". " + patients[i]->getInfo() + "\n";
    }
    
    return info;
}
