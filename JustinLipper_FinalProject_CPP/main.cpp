
// Justin Lipper
// CS 285: CPP Programming
// due 5/5/2017
//
// PriorityQueue.h, linkedList.h and Heap.h were used from the book.
//
// My website is:
//
// justinlipper@gmail.com


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "PriorityQueue.h"
#include "LinkedList.h"
#include "SourceProjectIII.cpp"
#include "Course.h"

using namespace std;

int main(int argc, char * argv[]) {
    
    if (argc != 3) { // making sure there are three outputs
        
        cout << "Usaging : " << argv[0] << "input_data_filename output_data_filename\n\n.Exiting program" << endl;
        
        exit(1);
    } // End if Statement
    
    Course myCourse( argv[1], argv[2] );
    
    if ( myCourse.readStudentsScore()) {
        
        myCourse.saveSortedStudentsNamesAndGrades();
        myCourse.displayCourseStatistics();
    } // End if Statement
    
    return 0;
}

