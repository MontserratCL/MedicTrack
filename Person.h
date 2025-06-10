#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

// Use of abstract class to define a common interface for all people in the hospital system
class Person {
protected:
    string name;
    string id;
    string phone;

public:
    // Create a constructor for Person class
    Person(string name, string id, string phone);
    
    // Getters
    string getName();
    string getId();
    string getPhone();
    
    // Pure virtual function with return 0 that makes this class abstract
    virtual string getInfo() = 0;
    
    // Virtual destructor for a more proper cleanup in the inheritance
    virtual ~Person() = default;
};

#endif
