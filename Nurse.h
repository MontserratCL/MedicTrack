#ifndef NURSE_H
#define NURSE_H

#include "Person.h"
#include <string>
using namespace std;

//Nurse class that inherits from person 
class Nurse : public Person {
private:
    string shift;
    string department;

public:
    // Constructors (method overloading)
    Nurse(string name, string id, string phone, string shift);
    Nurse(string name, string id, string phone, string shift, string department);
    
    // Getters
    string getShift();
    string getDepartment();
    
    // Setter
    void setDepartment(string department);
    
    // Pure virtual function from Person (method overriding)
    string getInfo() override;
    
    // Operator overloading
    bool operator==(Nurse& other);
};

#endif
