//
//  Course.h
//  JustinLipper_FinalProject_CPP
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "PriorityQueue.h"
#include "LinkedList.h"

#ifndef Course_h
#define Course_h

class Course {
    
    public:
        Course( const string& inputFile, const string& outputFile ) { // initialize the course public class
            
            this->inputFile = inputFile; // point to the input file
            this->outputFile = outputFile; // same for output
            
            cout << "Data will be read from: " << inputFile << endl
            << "Letter grade will be written into: " << outputFile
            << endl << endl;
        }
        
        bool readStudentsScore() { // Set up a constructor that will read student score
            
            ifstream input(inputFile);
            ofstream output(outputFile);
            
            if ( input.fail() ) {
                
                cout << "Error opening youu input file" << inputFile << endl;
                cout << "Exiting program!" << endl;
                return false;
            } // End of if statement
            
            string studentName;
            string strScore;
            
            while ( !input.eof() ) {
                
                Student tempStudent;
                getline( input, tempStudent.name, ',' );
                
                for ( int i = 0; i < 6; i++ ) {
                    
                    getline( input, strScore, ',' );
                    tempStudent.score[i] = stoi(strScore);
                    
                } // End of for loop
                
                getline(input, strScore, '\n');
                
                tempStudent.score[6] = stoi( strScore );
                studentList.add( tempStudent );
            }
            
            input.close();
            return true;
        }
        
        void saveSortedStudentsNamesAndGrades() { // Making constructor for Sorting through the students
            
            double TotalScore;
            char studentGrade;
            
            ofstream output( outputFile );
            
            PriorityQueue<Student> StudentQueue;
            for ( int i = 0; i < studentList.getSize(); i++ ) {
                
                Student tempStudent = studentList.get(i);
                
                TotalScore = tempStudent.score[0] * .10 + tempStudent.score[1] * .10 + tempStudent.score[2] * .10 + tempStudent.score[3] * .10 + tempStudent.score[4] * .20 + tempStudent.score[5] * .15 + tempStudent.score[6] * .25;
                
                // Calculating the final grade for the student
                if (TotalScore >= 90)
                    studentGrade = 'A';
                
                else if (TotalScore >= 80)
                        studentGrade = 'B';
                
                    else if (TotalScore >= 70)
                            studentGrade = 'C';
                
                        else if (TotalScore >= 60)
                                studentGrade = 'D';
                            else
                                studentGrade = 'F';
                
                StudentQueue.enqueue(Student(tempStudent.getName(), studentGrade));
                
            }
            
            output << "Letter grade for " << studentList.getSize() << " students given in " << outputFile
            << " file is:" << endl << endl; // Printing the grades and the students
            
            while ( StudentQueue.getSize() > 0 ) {
                
                Student element = StudentQueue.dequeue();
                output << setw(20) << left << element.getName() << " : " << element.getLetterGrade() << endl;
                
            }
            
            cout << endl << "Letter grade has been calculated for " <<
            studentList.getSize() << " students listed in input file " << inputFile   << " and written to output file " << outputFile << endl;
            
            output.close();
        }
        
        void displayCourseStatistics() {
            // setting up for min max and total caculations
            int max[7] = { 0 };
            int min[7] = { 100, 100, 100, 100, 100, 100, 100};
            int total[7] = { 0 };
            
            for (int i = 0; i < studentList.getSize(); i++)  {
                
                Student tempStudent = studentList.get(i);
                
                for (int i = 0; i < 7; i++) {
                    
                    if (tempStudent.score[i] > max[i]) {
                        // Finding max score
                        max[i] = tempStudent.score[i];
                    }
                    
                    if (tempStudent.score[i] < min[i]) {
                        // Finding min score
                        min[i] = tempStudent.score[i];
                    }
                    // total score
                    total[i] += tempStudent.score[i];
                }
            }
            
            cout << endl;
            cout << "Here are the class averages:" << endl << endl;
            
            // Printing out the results
            
            cout << setw(24) << "Q1" << setw(12) << "Q2"   << setw(12) << "Q3" << setw(12) << "Q4" << setw(12) << "MidI" << setw(12) << "MidII"   << setw(12) << "Final" << endl << endl;
            
            cout << setw(12) << "Avearage:" << setw(12) << fixed << setprecision(2);
            for (int i = 0; i < 7; i++) {
                cout << total[i] * 1.0 / studentList.getSize() << setw(12) << fixed << setprecision(2);
            }
            
            cout << endl << setw(12) << "Minimum: " << setw(12);
            
            for (int i = 0; i < 7; i++) {
                cout << min[i] << setw(12);
            }
            
            cout << endl << setw(12) << "Maximum: " << setw(12);
            
            for (int i = 0; i < 7; i++) {
                
                cout << max[i] << setw(12);
                
            }
            cout << endl << endl;
        }
        
        void printStudentList() {
            
            for (int i = 0; i < studentList.getSize(); i++)  {
                
                Student aStudent = studentList.get(i);
                cout << aStudent.getName() << endl;
                
            }
            
            cout << endl;
        }
    
    // setting internal
    private:
    
        LinkedList<Student> studentList;
        string inputFile;
        string outputFile;
};

#endif /* Course_h */
