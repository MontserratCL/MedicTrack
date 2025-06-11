# MedicTrack – Hospital Management System

**MedicTrack** is a C++ application that simulates a hospital management system using Object-Oriented Programming (OOP) principles. It provides healthcare institutions with a tool to manage patients, staff, and departments in an organized and efficient manner.

---

## Introduction

**MedicTrack** is a Hospital Management System developed in C++ using the core principles of Object-Oriented Programming (OOP). The purpose of this project is to support healthcare institutions in efficiently managing essential operations such as patient records, medical staff coordination, and departmental organization. By automating processes and centralizing information, MedicTrack significantly reduces manual workload, enhances accuracy, and improves the overall efficiency of hospital administration.

### Why this project?

Modern hospitals and clinics handle an overwhelming volume of sensitive information daily. Ensuring accuracy, confidentiality, and accessibility in such environments is a major operational challenge. **MedicTrack** addresses this need by providing a simulated, yet realistic, software solution tailored to the healthcare context. This project showcases a practical and socially impactful application of OOP. Through the implementation of inheritance, polymorphism, abstraction, and operator overloading, MedicTrack demonstrates the relevance and power of software engineering in real-world domains.

---
## UML Diagram 
![UML FINAL drawio](https://github.com/user-attachments/assets/c779c6a5-33b2-4403-83b4-abf687d7e3d8)

---
## Classes and Relationships (Design Justification)

### 1. Person (Abstract Superclass)
Defines shared attributes and a pure virtual method for all people in the hospital. Promotes code reuse and consistency.
- Attributes: `name`, `id`, `phone`
- Methods: Getters, `getInfo()` (pure virtual)

### 2. Doctor (Subclass of Person)
Represents doctors with specialization and a patient list.
- Attributes: `specialization`, `experience`, `patients`
- Methods: Overloaded constructors, `addPatient()` (overloaded), `getInfo()` (overridden), `operator==`

### 3. Nurse (Subclass of Person)
Represents nurses with shift and department information.
- Attributes: `shift`, `department`
- Methods: Constructors, `setDepartment()`, `getInfo()` (overridden), `operator==`

### 4. Patient (Subclass of Person)
Stores patient medical details.
- Attributes: `bloodType`, `allergies`
- Methods: Overloaded constructors, `updateInfo()` (overloaded), `getInfo()` (overridden), `operator+`

### 5. Department
Represents hospital departments and holds polymorphic staff.
- Attributes: `name`, `location`, `staff` (vector of `Person*`)
- Methods: Constructors, `addStaff()`, `getStaffCount()` (overloaded), `getAllStaffInfo()`, `operator+`

### 6. Hospital
Central system manager containing departments and patients.
- Attributes: `name`, `address`, `departments`, `patients`
- Methods: Constructors, `addPatient()`, `addDepartment()`, `findPatient()`, `getAllHospitalInfo()`

---

## Execution example

![Captura de Pantalla 2025-06-10 a la(s) 18 56 06](https://github.com/user-attachments/assets/320283a4-dcfd-4d0c-9713-7a1637e2b2c5)


g++ -std=c++11 -o medictrack *.cpp 

./medictrack

---

##  Usage Instructions

Upon starting the program, a menu is displayed with numeric options:

1. **Add Doctor** – Enter doctor’s information (with optional experience).  
2. **Add Nurse** – Register a nurse (with optional department).  
3. **Add Patient** – Input patient details (with optional allergy info).  
4. **Add Department** – Create a new department with optional location.  
5. **Assign Staff to Department** – Assign a doctor/nurse to a department.  
6. **Assign Patient to Doctor** – Assign a patient to an existing doctor.  
7. **Display Hospital Information** – Show all hospital details.  
8. **Display Department Information** – Show specific department info.  
9. **Find Patient** – Search by patient ID and display results.  
10. **Test Operator Overloading** – Demonstrate overloaded `+` and `==` operators.  
11. **Test Polymorphism** – Display info from a polymorphic vector of people.  
0. **Exit Program** – Exit the system and free memory.

---

## OOP Concepts and Evaluation

1.  **Proper Classes Identified**  
   Logical entities modeled clearly: Person, Doctor, Nurse, Patient, Department, Hospital.

2.  **Inheritance Implemented**  
   Doctor, Nurse, and Patient inherit from Person for shared structure.

3.  **Access Modifiers Used Properly**  
   Attributes are private/protected; access provided via getters/setters.

4.  **Overriding and Overloading Used**  
   `getInfo()` overridden; methods like `addPatient()` and `updateInfo()` are overloaded.

5.  **Polymorphism Used Effectively**  
   Polymorphic vector (`vector<Person*>`) in Department uses dynamic binding.

6.  **Abstract Class Implemented**  
   Person is abstract with a pure virtual `getInfo()` method.

7.  **Operator Overloading**  
   - `==` for Doctor and Nurse comparison  
   - `+` to merge Patients or count Department staff

---

## Limitations / Potential Failure Cases

- **Invalid input** (wrong formats) can crash the program.  
- **No file storage** – all data is lost on exit.  
- **Pointer mismanagement** – although currently handled, future changes could risk leaks.  
- **User must create entities in order** (e.g., no assigning staff if none exist).
  
---

## Personal Conclusion

This project was a valuable exercise in the application of Object-Oriented Programming principles. It provided the opportunity to explore abstraction, inheritance, polymorphism, and operator overloading in a real-world simulation. Building **MedicTrack** showed how thoughtful class design and clean architecture can simplify complex systems like healthcare management. Additionally, debugging support from Stack Overflow and ChatGPT proved essential in resolving hidden logic or memory issues. Overall, this project strengthened my ability to design, implement, and test structured C++ systems.

---

## References

- Stack Overflow – [How does dynamic_cast work?](https://stackoverflow.com/questions/13783312/how-does-dynamic-cast-work)  
- ChatGPT (OpenAI) – Used as translator when needed and debugging assistance  
- [cplusplus.com](https://cplusplus.com) – C++ Standard Library Documentation  
- Bro Code (YouTube) – C++ tutorials for operator overloading and OOP review



