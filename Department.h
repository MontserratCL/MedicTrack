#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Doctor.h"
#include "Nurse.h"
#include <string>
#include <vector>
using namespace std;

class Department {
private:
    string name;
    vector<Doctor*> doctors;
    vector<Nurse*> nurses;

public:
    // constructors
    Department(string name);
    Department(string name, string location);
    
    // Getter
    string getName();
    
    // methods
    void addStaff(Doctor* doctor);
    void addStaff(Nurse* nurse);

    int getStaffCount();
    int getStaffCount(string type);
};

#endif
