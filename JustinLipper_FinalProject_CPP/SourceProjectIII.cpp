//
//  SourceProjectIII.cpp
//  JustinLipper_FinalProject_CPP
//
//  Created by Justin Lipper on 5/5/17.
//  Copyright © 2017 Justin LipperJustin Lipper Inc. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "PriorityQueue.h"
#include "LinkedList.h"

class Student{
public:
    Student() { }
    
    Student(const string& name, char letterGrade) {
        this->name = name;
        this->letterGrade = letterGrade;
    }
    bool operator<(const Student& secondPatient) {
        return (this->name > secondPatient.name);
    }
    bool operator>(const Student& secondStudent) {
        return (this->name < secondStudent.name);
    }
    string getName() {
        return name;
    }
    char getLetterGrade() {
        return letterGrade;
    }
    int score[7];
    
    string name;
    
private:
    char letterGrade;
};
