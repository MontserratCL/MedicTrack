#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    string name;
    string id;
    string phone;

public:
    // Constructor
    Person(string name, string id, string phone);
    
    // Getters
    string getName();
    string getId();
    string getPhone();
    
    // Pure virtual function(for this to be abstract)
    virtual string getInfo() = 0;
    
    // Virual destructor
    virtual ~Person() = default;
};

#endif
