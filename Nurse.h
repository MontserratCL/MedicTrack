#ifndef NURSE_H
#define NURSE_H

#include "Person.h"
#include <string>
using namespace std;

class Nurse : public Person {
private:
    string shift;
    string department;

public:
    // Constructors
    Nurse(string name, string id, string phone, string shift);
    Nurse(string name, string id, string phone, string shift, string department);
    
    // Getters
    string getShift();
    string getDepartment();
    
    // virtual function from Person
    string getInfo() override;
};

#endif
