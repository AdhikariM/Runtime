#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include "Courses.h"

using namespace std;

// This function takes in a Course object and displays its details.
void displayCourse(Course course) {
    // Get the prerequisites of the course and store them in a vector
    vector<string> coursePrerequisites = course.getCoursePrerequisites();
    // Create a stringstream object to store the formatted prerequisites output.
    stringstream prerequisites;
    
    // Check if there are any prerequisites.
    if (coursePrerequisites.empty()) {
        // If there are no prerequisites, add "NA" to the stringstream.
        prerequisites << "NA";
    } else {
        // If there are prerequisites, iterate through the vector and add each prerequisite to the stringstream.
        for (size_t i = 0; i < coursePrerequisites.size(); ++i) {
            prerequisites << coursePrerequisites[i];
            // If this is not the last prerequisite, add a comma and a space.
            if (i != coursePrerequisites.size() - 1) {
                prerequisites << ", ";
            }
        }
    }

    // Print out the course ID and name.
    cout << course.getCourseId() << ", "
              << course.getCourseName() << endl;
    // Print out the formatted prerequisites output.
    cout << "Prerequisites: " << prerequisites.str() << endl;
}



// This function takes in an input file path and a pointer to a Courses object and loads the courses from the input file into the Courses object.
void loadCourses(const string& inputFilePath, Courses* coursesBst) {
	// Print out a message indicating that the input file is being loaded.
	cout << "Loading input file " << inputFilePath << endl;

	// Open the input file.
	ifstream file(inputFilePath);
	// Declare a string to hold the current line.
	string currentLine;

	try {
		// Iterate through each line of the file.
		while (getline(file, currentLine)) {
			// Create a stringstream object for the current line.
			stringstream ss(currentLine);
			// Declare variables to hold the course ID, name, and prerequisites.
			string word, id, name;
			vector<string> prerequisites;
			// Declare an index variable to keep track of which field (ID, name, or prerequisites) we are currently processing.
			int index = 0;

			// Iterate through each field of the current line.
			while (getline(ss, word, ',')) {
				// Remove any carriage return or newline characters from the field.
				word.erase(remove(word.begin(), word.end(), '\r'), word.end());
				word.erase(remove(word.begin(), word.end(), '\n'), word.end());
				// If this is the first field, assign it to the ID variable.
				if (index == 0) {
					id = word;
				// If this is the second field, assign it to the name variable.
				} else if (index == 1) {
					name = word;
				// If this is the third or later field, add it to the prerequisites vector.
				} else {
					prerequisites.push_back(word);
				}
				index++;
			}

			// Create a new Course object with the parsed ID, name, and prerequisites.
			Course course = Course(id, name, prerequisites);
			// Add the course to the Courses object using the Insert method.
			coursesBst->Insert(course);
		}
	} catch (ifstream::failure& e) {
		// If an exception occurs while reading the file, print the error message to standard error.
		cerr << e.what() << endl;
	}

	// Close the file.
	file.close();
}


int main() {
	// Define a binary search tree to hold all courses
	Courses *coursesBst;
	coursesBst = new Courses();
	Course course;
	string csvPath, courseKey;

	cout << "Welcome to the course planner." << endl;

	int choice = 0;
	while (choice != 9) {
		cout << "  1. Load Data Structure." << endl;
		cout << "  2. Print Course List." << endl;
		cout << "  3. Print Course." << endl;
		cout << "  9. Exit" << endl << endl;
		cout << "What would you like to do? ";
		cin >> choice;

		switch (choice) {
			case 1:
                csvPath = "./projectTwoInput.csv";
				loadCourses(csvPath, coursesBst);
				break;
			case 2:
				cout << "Here is a sample schedule: " << endl;
				coursesBst->InOrder();
				break;
			case 3:
				cout << "What course do you want to know about? ";
				cin >> courseKey;
				course = coursesBst->Search(courseKey);

				if (!course.getCourseId().empty()) {
					displayCourse(course);
				} else {
					cout << "Course Id " << courseKey << " not found." << endl;
				}
				break;
			case 9:
				cout << "Good bye." << endl;
				break;
			default:
				cout << choice << " is not a valid option." << endl;
				break;
		}
		cout << endl;
	}

	return 0;
}