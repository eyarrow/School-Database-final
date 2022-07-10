//
//  roster.h
//  Class Roster
//
//  Created by Elizabeth Yarrow on 6/21/20.
//  Copyright © 2020 Elizabeth Yarrow. All rights reserved.
//

#ifndef ROSTER_H_
#define ROSTER_H_

#include <string>
#include "student.h"
#include "degree.h"




class Roster {
public:
    //Constructor
    Roster();
    Roster(int capacity); //Constructor that creates array with max capacity

    //Destructor
    ~Roster();

    void parse(string line); 
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    void remove(string studentID);
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printAll();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    

    Student ** classRosterArray; //Array of pointers to student objects


private:

    
    int maxCapacity; //maximum size of array
    int lastIndex; //last index in the array



};
#endif /* ROSTER_H_ */

