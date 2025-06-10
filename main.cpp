#include <iostream>
#include <string>
#include "Hospital.h"
#include "Department.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Patient.h"

using namespace std;

//Display the main menu options
void displayMenu() {
    cout << "\n=== MedicTrack Hospital Management System ===" << endl;
    cout << "1. Add Doctor" << endl;
    cout << "2. Add Nurse" << endl;
    cout << "3. Add Patient" << endl;
    cout << "4. Add Department" << endl;
    cout << "5. Assign Staff to Department" << endl;
    cout << "6. Assign Patient to Doctor" << endl;
    cout << "7. Display Hospital Information" << endl;
    cout << "8. Display Department Information" << endl;
    cout << "9. Find Patient" << endl;
    cout << "10. Test Operator Overloading" << endl;
    cout << "11. Test Polymorphism" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}


//This for checking the polymorphism functionality
void testPolymorphism(Hospital* hospital) {
    cout << "\n=== Testing Polymorphism ===" << endl;
    
    // Create a vector of Person pointers (polymorphic collection)
    vector<Person*> people;
    
    // Add different types of people
    people.push_back(new Doctor("Dr. Smith", "D001", "555-0001", "Cardiology", 15));
    people.push_back(new Nurse("Nurse Johnson", "N001", "555-0002", "Night", "Emergency"));
    people.push_back(new Patient("John Chimi", "P001", "555-0003", "O+", "Penicillin"));
    
    // Display information using polymorphism
    cout << "Displaying information using polymorphic calls:" << endl;
    for (size_t i = 0; i < people.size(); i++) {
        cout << (i + 1) << ". " << people[i]->getInfo() << endl;
    }
    
}

//Check the overloading functionality
void testOperatorOverloading(Hospital* hospital) {
    cout << "\n=== Testing Operator Overloading ===" << endl;
    
    // Test Doctor equality operator
    Doctor* doc1 = new Doctor("Dr. Adams", "D100", "555-1001", "Neurology");
    Doctor* doc2 = new Doctor("Dr. Brown", "D100", "555-1002", "Pediatrics");
    Doctor* doc3 = new Doctor("Dr. Clark", "D101", "555-1003", "Surgery");
    
    cout << "Testing Doctor equality operator:" << endl;
    cout << "Doc1 == Doc2 (same ID): " << (*doc1 == *doc2 ? "true" : "false") << endl;
    cout << "Doc1 == Doc3 (different ID): " << (*doc1 == *doc3 ? "true" : "false") << endl;
    
    // Test Patient with the + operator
    Patient* pat1 = new Patient("Alice", "P100", "555-2001", "A+", "None");
    Patient* pat2 = new Patient("Bob", "P101", "555-2002", "B-", "Aspirin");
    
    cout << "\nTesting Patient + operator:" << endl;
    cout << (*pat1 + *pat2) << endl;
    
    // Test Department + operator
    Department* dept1 = new Department("Cardiology", "Floor 3");
    Department* dept2 = new Department("Emergency", "Ground Floor");
    
    dept1->addStaff(doc1);
    dept1->addStaff(new Nurse("Nurse White", "N100", "555-3001", "Day"));
    
    dept2->addStaff(doc3);
    dept2->addStaff(new Nurse("Nurse Green", "N101", "555-3002", "Night"));
    dept2->addStaff(new Nurse("Nurse Blue", "N102", "555-3003", "Day"));
    
    cout << "\nTesting Department + operator:" << endl;
    cout << "Total staff in both departments: " << (*dept1 + *dept2) << endl;
    
    // Cleaning 
    delete doc2;
    delete pat1;
    delete pat2;
    delete dept1;
    delete dept2;
}

int main() {
    // Create hospital instance
    Hospital* hospital = new Hospital("General Hospital", "123 Medical Center Blvd");
    
    // Vectors to store objects for the part of the memory management
    vector<Doctor*> doctors;
    vector<Nurse*> nurses;
    vector<Patient*> patients;
    vector<Department*> departments;
    
    int choice;
    string name, id, phone, specialty, shift, dept, bloodType, allergies, location;
    int experience, deptChoice, staffChoice, patientChoice, doctorChoice;
    
    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Clear
        
        switch (choice) {
            case 1: { // Add the Doctor
                cout << "Enter doctor's name: ";
                getline(cin, name);
                cout << "Enter doctor's ID: ";
                getline(cin, id);
                cout << "Enter doctor's phone: ";
                getline(cin, phone);
                cout << "Enter specialization: ";
                getline(cin, specialty);
                cout << "Enter years of experience (0 for default): ";
                cin >> experience;
                
                Doctor* doctor;
                if (experience > 0) {
                    doctor = new Doctor(name, id, phone, specialty, experience);
                } else {
                    doctor = new Doctor(name, id, phone, specialty);
                }
                
                doctors.push_back(doctor);
                cout << "Doctor added successfully!" << endl;
                break;
            }
            
            case 2: { // Add a Nurse
                cout << "Enter nurse's name: ";
                getline(cin, name);
                cout << "Enter nurse's ID: ";
                getline(cin, id);
                cout << "Enter nurse's phone: ";
                getline(cin, phone);
                cout << "Enter shift: ";
                getline(cin, shift);
                cout << "Enter department (or press Enter for default): ";
                getline(cin, dept);
                
                Nurse* nurse;
                if (!dept.empty()) {
                    nurse = new Nurse(name, id, phone, shift, dept);
                } else {
                    nurse = new Nurse(name, id, phone, shift);
                }
                
                nurses.push_back(nurse);
                cout << "Nurse added successfully!" << endl;
                break;
            }
            
            case 3: { // Add a Patient
                cout << "Enter patient's name: ";
                getline(cin, name);
                cout << "Enter patient's ID: ";
                getline(cin, id);
                cout << "Enter patient's phone: ";
                getline(cin, phone);
                cout << "Enter blood type: ";
                getline(cin, bloodType);
                cout << "Enter allergies (or press Enter for default): ";
                getline(cin, allergies);
                
                Patient* patient;
                if (!allergies.empty()) {
                    patient = new Patient(name, id, phone, bloodType, allergies);
                } else {
                    patient = new Patient(name, id, phone, bloodType);
                }
                
                patients.push_back(patient);
                hospital->addPatient(patient);
                cout << "Patient added successfully!" << endl;
                break;
            }
            
            case 4: { // Add a Department
                cout << "Enter department name: ";
                getline(cin, name);
                cout << "Enter location (or press Enter for default): ";
                getline(cin, location);
                
                Department* department;
                if (!location.empty()) {
                    department = new Department(name, location);
                } else {
                    department = new Department(name);
                }
                
                departments.push_back(department);
                hospital->addDepartment(department);
                cout << "Department added successfully!" << endl;
                break;
            }
            
            case 5: { // Assign Staff to the Department
                if (departments.empty()) {
                    cout << "No departments available. Add a department first." << endl;
                    break;
                }
                if (doctors.empty() && nurses.empty()) {
                    cout << "No staff available. Add doctors or nurses first." << endl;
                    break;
                }
                
                cout << "Available Departments:" << endl;
                for (size_t i = 0; i < departments.size(); i++) {
                    cout << (i + 1) << ". " << departments[i]->getName() << endl;
                }
                cout << "Select department: ";
                cin >> deptChoice;
                
                if (deptChoice < 1 || deptChoice > (int)departments.size()) {
                    cout << "Invalid department selection." << endl;
                    break;
                }
                
                cout << "Available Staff:" << endl;
                cout << "Doctors:" << endl;
                for (size_t i = 0; i < doctors.size(); i++) {
                    cout << "D" << (i + 1) << ". " << doctors[i]->getName() << endl;
                }
                cout << "Nurses:" << endl;
                for (size_t i = 0; i < nurses.size(); i++) {
                    cout << "N" << (i + 1) << ". " << nurses[i]->getName() << endl;
                }
                
                cout << "Enter staff type and number (e.g., D1 or N2): ";
                string staffInput;
                cin >> staffInput;
                
                if (staffInput[0] == 'D' || staffInput[0] == 'd') {
                    int docIndex = stoi(staffInput.substr(1)) - 1;
                    if (docIndex >= 0 && docIndex < (int)doctors.size()) {
                        departments[deptChoice - 1]->addStaff(doctors[docIndex]);
                        cout << "Doctor assigned successfully!" << endl;
                    } else {
                        cout << "Invalid doctor selection." << endl;
                    }
                } else if (staffInput[0] == 'N' || staffInput[0] == 'n') {
                    int nurseIndex = stoi(staffInput.substr(1)) - 1;
                    if (nurseIndex >= 0 && nurseIndex < (int)nurses.size()) {
                        departments[deptChoice - 1]->addStaff(nurses[nurseIndex]);
                        nurses[nurseIndex]->setDepartment(departments[deptChoice - 1]->getName());
                        cout << "Nurse assigned successfully!" << endl;
                    } else {
                        cout << "Invalid nurse selection." << endl;
                    }
                } else {
                    cout << "Invalid input format." << endl;
                }
                break;
            }
            
            case 6: { // Assign Patient to Doctor
                if (doctors.empty()) {
                    cout << "No doctors available. Add doctors first." << endl;
                    break;
                }
                if (patients.empty()) {
                    cout << "No patients available. Add patients first." << endl;
                    break;
                }
                
                cout << "Available Doctors:" << endl;
                for (size_t i = 0; i < doctors.size(); i++) {
                    cout << (i + 1) << ". " << doctors[i]->getName() 
                         << " - " << doctors[i]->getSpecialization() << endl;
                }
                cout << "Select doctor: ";
                cin >> doctorChoice;
                
                if (doctorChoice < 1 || doctorChoice > (int)doctors.size()) {
                    cout << "Invalid doctor selection." << endl;
                    break;
                }
                
                cout << "Available Patients:" << endl;
                for (size_t i = 0; i < patients.size(); i++) {
                    cout << (i + 1) << ". " << patients[i]->getName() << endl;
                }
                cout << "Select patient: ";
                cin >> patientChoice;
                
                if (patientChoice < 1 || patientChoice > (int)patients.size()) {
                    cout << "Invalid patient selection." << endl;
                    break;
                }
                
                doctors[doctorChoice - 1]->addPatient(patients[patientChoice - 1]);
                cout << "Patient assigned to doctor successfully!" << endl;
                break;
            }
            
            case 7: { // Display the Hospital Information
                cout << hospital->getAllHospitalInfo() << endl;
                break;
            }
            
            case 8: { // Display the Department Information
                if (departments.empty()) {
                    cout << "No departments available." << endl;
                    break;
                }
                
                cout << "Available Departments:" << endl;
                for (size_t i = 0; i < departments.size(); i++) {
                    cout << (i + 1) << ". " << departments[i]->getName() << endl;
                }
                cout << "Select department to display: ";
                cin >> deptChoice;
                
                if (deptChoice < 1 || deptChoice > (int)departments.size()) {
                    cout << "Invalid department selection." << endl;
                    break;
                }
                
                cout << departments[deptChoice - 1]->getAllStaffInfo() << endl;
                cout << "Doctors: " << departments[deptChoice - 1]->getStaffCount("Doctor") << endl;
                cout << "Nurses: " << departments[deptChoice - 1]->getStaffCount("Nurse") << endl;
                break;
            }
            
            case 9: { // Find a Patient
                cout << "Enter patient ID to search: ";
                getline(cin, id);
                
                Patient* foundPatient = hospital->findPatient(id);
                if (foundPatient != nullptr) {
                    cout << "Patient found: " << foundPatient->getInfo() << endl;
                } else {
                    cout << "Patient not found." << endl;
                }
                break;
            }
            
            case 10: { // Test the Operator Overloading
                testOperatorOverloading(hospital);
                break;
            }
            
            case 11: { // Test the Polymorphism
                testPolymorphism(hospital);
                break;
            }
            
            case 0: {
                cout << "Exiting MedicTrack System. Goodbye!" << endl;
                break;
            }
            
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    } while (choice != 0);
    
    // Clean up the memory
    for (Doctor* doctor : doctors) {
        delete doctor;
    }
    for (Nurse* nurse : nurses) {
        delete nurse;
    }
    for (Patient* patient : patients) {
        delete patient;
    }
    for (Department* department : departments) {
        delete department;
    }
    delete hospital;
    
    return 0;
}
