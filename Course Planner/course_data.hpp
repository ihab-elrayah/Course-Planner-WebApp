//
//  course_data.hpp
//  Course Planner
//
//  Created by Ihab Elrayah
//
#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>
#include <vector>

using namespace std;

class Course {
public:
    // Constructor to initialize Course object with code, title, and prerequisites
    Course(const string& code, const string& title, const vector<string>& prerequisites);

    // Functions to get course code, title, and prerequisites
    string getCode() const;
    string getTitle() const;
    vector<string> getPrerequisites() const;

private:
    // Private member variables to store course information
    string courseCode;
    string courseTitle;
    vector<string> coursePrerequisites;
};

#endif 
