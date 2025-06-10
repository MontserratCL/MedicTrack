#include "Doctor.h"

//Cosntructor for Doctor class that initializes the name, id, phone, specialization and sets a default experience.
Doctor::Doctor(string name, string id, string phone, string specialization) 
    : Person(name, id, phone) {
    this->specialization = specialization;
    this->experience = 0; // Default experience
}

//Overloaded constructor for Doctor class that initializes the name, id, phone, specialization and experience.
Doctor::Doctor(string name, string id, string phone, string specialization, int experience) 
    : Person(name, id, phone) {
    this->specialization = specialization;
    this->experience = experience;
}

//Getter for doctor's specialization that returns a string with the specialization.
string Doctor::getSpecialization() {
    return specialization;
}

// This method adds a patient to the doctor's list of patients.
void Doctor::addPatient(Patient* patient) {
    patients.push_back(patient);
}

//Overloded method that adds a patient by creating a new Patient object 
void Doctor::addPatient(string name, string id, string phone) {
    Patient* newPatient = new Patient(name, id, phone, "Unknown");
    patients.push_back(newPatient);
}

//This gets the number of patients assigned to the doctor. and returns it as an integer.
int Doctor::getPatientCount() {
    return patients.size();
}

//Override of the pure virtual function from Person class that returns a string with the doctor's information.
string Doctor::getInfo() {
    return "Doctor: " + name + " (ID: " + id + ") - Specialization: " + 
           specialization + ", Experience: " + to_string(experience) + 
           " years, Patients: " + to_string(patients.size());
}

//Operator overloading for the comparision receives as the parameter another Doctor object and compares the IDs of both doctors.
bool Doctor::operator==(Doctor& other) {
    return this->id == other.id;
}
