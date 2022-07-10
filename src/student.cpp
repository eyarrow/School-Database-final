//
//  student.cpp
//  Class Roster
//
//  Created by Elizabeth Yarrow on 6/21/20.
//  Copyright © 2020 Elizabeth Yarrow. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;
#include "student.h"
#include "degree.h"

//Constructors
//Default Contstructor, no parameters given, delegates to constructor with arguments
Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->LastName = "";
    this->emailAddress = "";
    this->age = 0;
    for(int i =0; i < courseDaysSize; i++) {
        this->daysInCourse[i] = 0;
    }
    this->degreeProgram = SOFTWARE;
}


//Constructor with Paramteters
Student::Student(string id, string first, string last, string email, int age, int days[],DegreeProgram degree) {
    this->studentID = id;
    this->firstName = first;
    this->LastName = last;
    this->emailAddress = email;
    this->age = age;
    this->setDaysInCourse(days);
    this->degreeProgram = degree;
}

//Getters

int Student::getAge() const {
    return age;
}

const int* Student::getDaysInCourse() const {
    return daysInCourse;
}

DegreeProgram Student::getDegreeProgram() {
    return degreeProgram;
}

const string& Student::getEmailAddress() const {
    return emailAddress;
}

const string& Student::getFirstName() const {
    return firstName;
}

const string& Student::getLastName() const {
    return LastName;
}

const string& Student::getStudentId() const {
    return studentID;
}


//Setters

void Student::setAge(int age) {
    this->age = age;
}

void Student::setDegreeProgram(const DegreeProgram &degreeProgram) {
    this->degreeProgram = degreeProgram;
}

void Student::setEmailAddress(const string &emailAddress) {
    this->emailAddress = emailAddress;
}

void Student::setFirstName(const string &firstName) {
    this->firstName = firstName;
}

void Student::setLastName(const string &lastName) {
    this->LastName = lastName;
}

void Student::setStudentId(const string &studentId) {
    this->studentID = studentId;
}

void Student::setDaysInCourse(int days[]) {
    for(int i = 0; i < courseDaysSize; i++) {
        this->daysInCourse[i] = days[i];
    }

}


//print student record per instructions
//print format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security.
void Student::printStudent() {
    


    cout << left << getStudentId() <<  "\tFirst Name: " << getFirstName() <<  "\tLast Name: " << getLastName() << "\tEmail: " << setw(18) << this->getEmailAddress()
            << "\tAge: " << getAge() << "\tdaysInCourse: "

			<< "{" << daysInCourse[0] << "," << daysInCourse[1] << "," << daysInCourse[2] << "}" << "\tDegree Program: " << degreeType[this->degreeProgram] << endl;


}

//Default Constuctor, sets values to null
Student::~Student() {
    this->studentID = "";
    this->firstName = "";
    this->LastName = "";
    this->emailAddress = "";
    this->age = 0;
    for(int i =0; i < courseDaysSize; i++) {
        this->daysInCourse[i] = 0;
    }
    this->degreeProgram = SOFTWARE;
}








