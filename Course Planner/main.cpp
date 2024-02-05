//  main.cpp
//  Course Planner
//
//  Created by Ihab Elrayah 
//



#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "course_data.hpp"

using namespace std;

// Function to load course data from a file and vector
void loadDataStructure(vector<Course>& courses, const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
        
    }

       courses.clear(); // Clear existing course data before loading new data

       // Read course data from the file
       string code, title;
       vector<string> prerequisites;
       while (inputFile >> code >> title) {
           string prereq;
           prerequisites.clear();
           while (inputFile >> prereq && prereq != "-1") {
               prerequisites.push_back(prereq);
           }
           courses.emplace_back(code, title, prerequisites);
           // Create Course objects and add to the vector
       }

    if (inputFile.fail() && !inputFile.eof()) {
            cerr << "Error: Failed to read course data from file." << endl;
        } else {
            cout << "Data loaded successfully." << endl;
        }

        inputFile.close();
    }
   

// Function to filter and retrieve Computer Science courses from the  list
vector<Course> getComputerScienceCourses(const vector<Course>& allCourses) {
    vector<Course> csCourses;
    for (const Course& course : allCourses) {
        // Course codes starting with "CSCI"
        if (course.getCode().substr(0, 4) == "CSCI") {
            csCourses.push_back(course);
        }
    }
    return csCourses;
}

// Function to print a list of courses with their codes and titles
void printCourseList(const vector<Course>& courses) {
    vector<Course> csCourses = getComputerScienceCourses(courses);
    for (const Course& course : csCourses) {
        cout << course.getCode() << " - " << course.getTitle() << endl;
    }
}

// Function to print information about a specific course
void printCourseInformation(const vector<Course>& courses, const string& courseCode) {

    auto it = find_if(courses.begin(), courses.end(),
                      [courseCode](const Course& course) {
                          return course.getCode() == courseCode;
                      });

    if (it != courses.end()) {
        cout << "Course Title: " << it->getTitle() << endl;
        cout << "Prerequisites: ";
        for (const string& prereq : it->getPrerequisites()) {
            cout << prereq << " ";
        }
        cout << endl;
    } else {
        cout << "Course not found." << endl;
    }
}

int main() {
    vector<Course> courses;
    string filename;

    

    loadDataStructure(courses, filename);
    
        courses.emplace_back("CSCI100", "Introduction to Computer Science", vector<string>());
        courses.emplace_back("CSCI101", "Introduction to Programming in C++", vector<string>{"CSCI100"});
        courses.emplace_back("CSCI200", "Data Structures", vector<string>{"CSCI101"});
        courses.emplace_back("MATH201", "Discrete Mathematics", vector<string>());
        courses.emplace_back("CSCI300", "Introduction to Algorithms", vector<string>{"CSCI200", "MATH201"});
        courses.emplace_back("CSCI301", "Advanced Programming in C++", vector<string>{"CSCI101"});
        courses.emplace_back("CSCI350", "Operating Systems", vector<string>{"CSCI300"});
        courses.emplace_back("CSCI400", "Large Software Development", vector<string>{"CSCI301", "CSCI350"});


    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Load Data Structure\n";
        cout << "2. Print Course List\n";
        cout << "3. Print Course\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        string courseCode;
        switch (choice) {
                    case 1:
                        cout << "Enter the course data filename: ";
                        cin >> filename;
                        loadDataStructure(courses, filename);
                        break;
                    case 2:
                        printCourseList(courses);
                        break;
                    case 3:
                //string courseCode;
                        cout << "Enter the course code: ";
                        cin >> courseCode;
                        printCourseInformation(courses, courseCode);
                        break;
                    case 4:
                        cout << "Exiting the program." << endl;
                        break;
                    default:
                        cout << "Invalid choice. Try again." << endl;
                        break;
                    }
                } while (choice != 4);

                return 0;
            }
