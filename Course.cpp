

#include "Course.h"

using namespace std;
//constructor for creating a Course Object
Course::Course(string &id, string &name, vector<string> &prerequisites) {
	this->courseId = id;
	this->courseName = name;
	this->coursePrerequisites = prerequisites;
}

// Getter for the course id.
string Course::getCourseId() {
	return this->courseId;
}

// Getter for the course name.
string Course::getCourseName() {
	return this->courseName;
}

///Getter for the list of course prerequisites.
vector<string> Course::getCoursePrerequisites() {
	return this->coursePrerequisites;
}

//return courseID and courseName.
string Course::courseToString() {
	return this->courseId + ", " + this->courseName;
}