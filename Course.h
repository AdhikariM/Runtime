#ifndef PROJECT2
#define PROJECT2

#include <string>
#include <vector>

using namespace std;

class Course {
// private fields for a course object.
private:
	string courseId;
	string courseName;
	vector<string> coursePrerequisites;
// public methods for a course object.
public:
	Course() = default;
	Course(string &id, string &name, vector<string> &prerequisites);
	string getCourseId();
	string getCourseName();
	vector<string> getCoursePrerequisites();
	string courseToString();
};

#endif