#include "Nurse.h"

//Cosntructor for Nurse class that recerives the name, id, phone and shift
Nurse::Nurse(string name, string id, string phone, string shift) 
    : Person(name, id, phone) {
    this->shift = shift;
    this->department = "Unassigned"; // Default department
}

//Oveeloaded constructor for Nurse class that initializes the name, id, phone, shift and department.
Nurse::Nurse(string name, string id, string phone, string shift, string department) 
    : Person(name, id, phone) {
    this->shift = shift;
    this->department = department;
}

//Getter for nurse's shift that returns a string with the shift information.
string Nurse::getShift() {
    return shift;
}

//Getter for nurse's department that returns a string with the department name.
string Nurse::getDepartment() {
    return department;
}

//Setter for nurse's department that sets the department attribute to the new department.
void Nurse::setDepartment(string department) {
    this->department = department;
}

//override of the pure virtual function from Person class
string Nurse::getInfo() {
    return "Nurse: " + name + " (ID: " + id + ") - Shift: " + shift + 
           ", Department: " + department + ", Phone: " + phone;
}

//Operator overloading for equality comparison receives as a parameter another Nurse object and compares the IDs of both nurses.
bool Nurse::operator==(Nurse& other) {
    return this->id == other.id;
}
