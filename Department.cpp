#include "Department.h"
#include "Doctor.h"
#include "Nurse.h"

//Construtor dor Department class that receives the name of the department
Department::Department(string name) {
    this->name = name;
    this->location = "Not specified"; // Default location
}

//Overloaded constructor for Department class that initializes the name and location attributes.
Department::Department(string name, string location) {
    this->name = name;
    this->location = location;
}

//Getter for department name that returns a string with the department name.
string Department::getName() {
    return name;
}

//Getter for department location that returns a string with the department location.
string Department::getLocation() {
    return location;
}

// This method adds a staff member to the department's staff vector.
void Department::addStaff(Person* person) {
    staff.push_back(person);
}

// This method returns the total number of staff members in the department.
int Department::getStaffCount() {
    return staff.size();
}

// This method counts the number of staff members of a specific type (Doctor or Nurse).
int Department::getStaffCount(string type) {
    int count = 0;
    for (Person* person : staff) {
        // Check if the person is a Doctor or Nurse based on the type parameter with dynamic_cast
        if (type == "Doctor" && dynamic_cast<Doctor*>(person)) {
            count++;
        } else if (type == "Nurse" && dynamic_cast<Nurse*>(person)) {
            count++;
        }
    }
    return count;
}

// This method compiles all relevant information about the department, including its name, location, total staff count, and detailed information about each staff member.
string Department::getAllStaffInfo() {
    string info = "Department: " + name + " (" + location + ")\n";
    info += "Total Staff: " + to_string(staff.size()) + "\n";
    info += "Staff Members:\n";
    
    for (size_t i = 0; i < staff.size(); i++) {
        info += to_string(i + 1) + ". " + staff[i]->getInfo() + "\n";
    }
    
    return info;
}

//Operator overloading that combines the staff count of two departments.
int Department::operator+(Department& other) {
    return this->getStaffCount() + other.getStaffCount();
}
