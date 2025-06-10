#include "Patient.h"

//Constructor for patient class that initializes the name, id, phone and blood type.
Patient::Patient(string name, string id, string phone, string bloodType) 
    : Person(name, id, phone) {
    this->bloodType = bloodType;
    this->allergies = "None"; // Default allergies
}

//Overloaded constructor for Patient class that initializes the name, id, phone, blood type and allergies.
Patient::Patient(string name, string id, string phone, string bloodType, string allergies) 
    : Person(name, id, phone) {
    this->bloodType = bloodType;
    this->allergies = allergies;
}

// Getter, this function returns the blood type of the patient. 
string Patient::getBloodType() {
    return bloodType;
}

//Getter for patient's allergies that returns a string with the allergies.
string Patient::getAllergies() {
    return allergies;
}

//Setter for patients allergies that sets the allergies attribute to the new allergies.
void Patient::setAllergies(string allergies) {
    this->allergies = allergies;
}

//Update patients blood type only 
void Patient::updateInfo(string bloodType) {
    this->bloodType = bloodType;
}

//Overloaded methos to update both blood type and allergies
void Patient::updateInfo(string bloodType, string allergies) {
    this->bloodType = bloodType;
    this->allergies = allergies;
}

//Override of the pure virtual function from person that returns an string with the patients information
string Patient::getInfo() {
    return "Patient: " + name + " (ID: " + id + ") - Blood Type: " + 
           bloodType + ", Allergies: " + allergies + ", Phone: " + phone;
}

//Operator overloading that combines patient information receives as a parameter another Patient object and returns a string with the combined information.
string Patient::operator+(Patient& other) {
    return "Combined Patient Info: " + this->name + " & " + other.name + 
           " - Blood Types: " + this->bloodType + " & " + other.bloodType;
}
