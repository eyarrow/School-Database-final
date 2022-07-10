//
//  main.cpp
//  Class Roster
//
//  Created by Elizabeth Yarrow on 6/12/20.
//  Copyright © 2020 Elizabeth Yarrow. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "roster.h"
#include "student.h"
#include "string.h"



int main() {
    
    cout << left << "*********************************************************************" << endl;
    cout << left << setw(70) << "Course Title: C867 Scripting and Programming Applications" << endl;
    cout << left << "Programming Language: C++" << endl;
    cout << left << "WGU Student ID: 001172177" << endl;
    cout << left << "Name: Elizabeth Yarrow" << endl;
    cout << left << "*********************************************************************" << endl;
    cout << endl << endl;
    
    
    int arraySize = 5;
    const string classRosterArray[] =
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Elizabeth,Yarrow,eyarrow@wgu.edu,40,10,22,91,SOFTWARE"};

    Roster * classRoster = new Roster(arraySize);

    //Send each string to be parsed into data fields for student objects
    for(int i =0; i < arraySize; ++i) {
        classRoster->parse(classRosterArray[i]);

    }

    cout << left << "List of all students:" << endl;
    cout << left << "-------------------------" << endl;
    
    
    classRoster->printAll();
    cout << endl << endl;
    
    cout << left << "Students with invalid email addresses:" << endl;
    cout << left << "-------------------------" << endl;
    
    classRoster->printInvalidEmails();
    cout << endl << endl;
    
    cout << left << "Average Days in Course for all students:" << endl;
    cout << left << "-------------------------" << endl;
    
    for(int i =0; i < arraySize; ++i) {
        classRoster->printAverageDaysInCourse(classRoster->classRosterArray[i]->getStudentId());

    }
    cout << endl << endl;


    cout << left << "Print by degree Program (Software):" << endl;
    cout << left << "-------------------------" << endl;
    
    classRoster->printByDegreeProgram(SOFTWARE);
    cout << endl << endl;
   
    cout << left << "Removing student A3..............." << endl;
    
    
    classRoster->remove("A3");
    cout << endl << endl;
    
    cout << left << "Print all students left in roster:" << endl;
    cout << left << "-------------------------" << endl;
    
    classRoster->printAll();
    cout << endl << endl;
    
    cout << left << "Try to remove A3 again:" << endl;
    cout << left << "-------------------------" << endl;
    
    classRoster->remove("A3");
    cout << endl << endl;

    return 0;
}
