//
//  course_data.cpp
//  Course Planner
//
//  Created by Ihab Elrayah
//
#include "course_data.hpp"

// Constructor for the Course class
Course::Course(const string& code, const string& title, const vector<string>& prerequisites)
    : courseCode(code), courseTitle(title), coursePrerequisites(prerequisites) {}

// Function to get the course code
string Course::getCode() const {
    return courseCode;
}

// Function to get the course title
string Course::getTitle() const {
    return courseTitle;
}

// Function to get the prerequisites of the course
vector<string> Course::getPrerequisites() const {
    return coursePrerequisites;
}
