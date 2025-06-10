#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Person.h"
#include <string>
#include <vector>
using namespace std;


//Departemnt class that's going to manage the hospital department using polymorphism with a single vector of Person pointers
class Department {
private:
    string name;
    string location;
    vector<Person*> staff; // Polymorphic vector this can hold Doctor*, Nurse*, etc.

public:
    // Constructors (with the method overloading)
    Department(string name);
    Department(string name, string location);
    
    // Getters
    string getName();
    string getLocation();
    
    // Methods
    void addStaff(Person* person); // Polymorphic method
    int getStaffCount();
    int getStaffCount(string type); // Overloaded method
    string getAllStaffInfo(); // Method to display all staff information
    
    // Operator overloading
    int operator+(Department& other);
};

#endif
