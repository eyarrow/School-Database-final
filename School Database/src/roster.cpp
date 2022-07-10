//
//  roster.cpp
//  Class Roster
//
//  Created by Elizabeth Yarrow on 6/21/20.
//  Copyright © 2020 Elizabeth Yarrow. All rights reserved.
//

#include <iostream>
#include <string>
#include <array>
#include <cstring>
#include <cctype>
using namespace std;

#include "roster.h"
#include "student.h"


//Default Constructor, creates roster with existing data
Roster::Roster() {
    this->classRosterArray = nullptr;
    this->maxCapacity = 0;
    this->lastIndex = -1; //indicates empty list

}

//Constructor with parameters: creates an array of given size
Roster::Roster(int capacity) {
    this->maxCapacity = capacity;
    this->lastIndex = -1;
    this->classRosterArray = new Student * [capacity];

}

//Destuctor
Roster::~Roster() {
    for(int i=0; i<maxCapacity; i++) {
        delete classRosterArray[i];
    }

    delete this;
}


//Parses const string array into individual tokens
void Roster::parse(string line) {
    int left = 0;
    int right = 0;
    string id;
    string first;
    string last;
    string email;
    int age;
    int days1;
    int days2;
    int days3;
    string program;
    DegreeProgram degree;

    if(this->lastIndex < this->maxCapacity) {
        //student id:
        left = 0;
        right = line.find(",", left);
        id = line.substr(left, right-left);

        //first name
        left = right + 1;
        right = line.find(",", left);
        first = line.substr(left,right-left);

        //last name
        left = right + 1;
        right = line.find(",", left);
        last = line.substr(left,right-left);

        //email
        left = right + 1;
        right = line.find(",", left);
        email = line.substr(left,right-left);

        //age
        left = right + 1;
        right = line.find(",", left);
        age = stoi(line.substr(left,right-left));

        //days1
        left = right + 1;
        right = line.find(",", left);
        days1 = stoi(line.substr(left,right-left));

        //days2
        left = right + 1;
        right = line.find(",", left);
        days2 = stoi(line.substr(left,right-left));

        //days3
        left = right + 1;
        right = line.find(",", left);
        days3 = stoi(line.substr(left,right-left));

        //Program
        left = right + 1;
        right = line.find(",", left);
        program = line.substr(left,right-left);

        //Determine enum value for degree:
        if(program == "SOFTWARE") {
            degree = SOFTWARE;
        }
        else if(program == "NETWORK") {
            degree = NETWORK;
        }
        else {
            degree = SECURITY;
        }

        this->add(id,first,last,email,age,days1,days2,days3,degree);

    }
}

//Adds student records to the array
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
    int days[Student::courseDaysSize];
    days[0] = daysInCourse1;
    days[1] = daysInCourse2;
    days[2] = daysInCourse3;

    this->lastIndex++;
    this->classRosterArray[lastIndex] = new Student(studentID,firstName,lastName,emailAddress, age, days, degreeprogram);


}

//Prints all students in the roster
void Roster::printAll(){
    for(int i = 0; i < maxCapacity; i++) {
        this->classRosterArray[i]->printStudent();


    }
}

//Print all students who are in the provided degree
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for(int i = 0; i < maxCapacity; i++) {
        if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            this->classRosterArray[i]->printStudent();
        }

    }

}

//Remove student record from the roster by StudentID
void Roster::remove(string studentID) {
    bool found = false;
    
    for(int i = 0; i < maxCapacity; i++) {
        if(this->classRosterArray[i]->getStudentId() == studentID) {
            delete this->classRosterArray[i];
            for(int j= i; j < this->lastIndex; j++) {
                this->classRosterArray[j] = this->classRosterArray[j+1];
            }
            this->classRosterArray[this->lastIndex] = nullptr;
            this->lastIndex = this->lastIndex-1;
            this->maxCapacity = this->maxCapacity-1;
            found = true;
        }
        
    }
    if(!found)
           {
               cout << "Student with this id not found!" << endl;
           }
}


//Print average day remaining across all 3 courses - using student id as paramter
void Roster::printAverageDaysInCourse(string studentID) {
    for(int i = 0; i < maxCapacity; i++)
    {
        if(this->classRosterArray[i]->getStudentId() == studentID) {
            const int * days = this->classRosterArray[i]->getDaysInCourse();
            int total = days[0] + days[1] + days[2];
            int average = total/3;

            cout << "Student ID: " << studentID << " Average number of days are: " << average << endl;

        }
    }
}

//Find invalid emails. Valid emails must have an @ and a period, but cannot have a space
void Roster::printInvalidEmails() {
 
    for(int i = 0; i < this->maxCapacity; i++) {
        string email(this->classRosterArray[i]->getEmailAddress());
       if ((email.find(".") == string::npos) || (email.find(" ") != string::npos) || (email.find("@") == string::npos)) {
           cout << this->classRosterArray[i]->getEmailAddress() << endl;
       }
        
    }
}
