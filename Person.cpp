#include "Person.h"

//Cosntructor for person class that initializes the name, id, and phone attributes.
Person::Person(string name, string id, string phone) {
    this->name = name;
    this->id = id;
    this->phone = phone;
}

//Geters for persons name that return a string containing the person's name.
string Person::getName() {
    return name;
}

//getter for the persons ID 
string Person::getId() {
    return id;
}

//Getter for the person phone number that return a string with the phone number
string Person::getPhone() {
    return phone;
}
