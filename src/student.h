//
//  student.h
//  Class Roster
//
//  Created by Elizabeth Yarrow on 6/21/20.
//  Copyright © 2020 Elizabeth Yarrow. All rights reserved.
//

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include "degree.h"
using namespace std;

class Student {
public:
    //Constant to hold Average days in course array size
    const static int courseDaysSize = 3;
    //Contructors:
    Student();
    Student(string id,
            string first,
            string last,
            string email,
            int age,
            int days[],
            DegreeProgram degree);

    //Getters
    int getAge() const;
    const int * getDaysInCourse() const;
    DegreeProgram getDegreeProgram();
    const string& getEmailAddress() const;
    const string& getFirstName() const;
    const string& getLastName() const;
    const string& getStudentId() const;

    //Setters
    void setAge(int age);
    void setDegreeProgram(const DegreeProgram &degreeProgram);
    void setEmailAddress(const string &emailAddress);
    void setFirstName(const string &firstName);
    void setLastName(const string &lastName);
    void setStudentId(const string &studentId);
    void setDaysInCourse(int days[]);

    //Print single student
    void printStudent();

    //Destructor
    ~Student();

protected: 
    string studentID;
    string firstName;
    string LastName;
    string emailAddress;
    int age;
    DegreeProgram degreeProgram;
    int daysInCourse[courseDaysSize];


};



#endif /* STUDENT_H_ */

