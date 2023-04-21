
#ifndef Project2
#define Project2

#include <string>
#include <vector>
#include "Course.h"

using namespace std;

struct Node {
	Course course;
	Node *left;
	Node *right;

	// default constructor
	Node() {
		left = nullptr;
		right = nullptr;
	}

	// initialize with a course
	Node(Course newCourse) :
			Node() {
		course = newCourse;
	}
};

class Courses {
private:
	Node* root;
	void destroyRecursive(Node *node);
	void addNode(Node *node, Course course);
	void inOrder(Node *node);
	void postOrder(Node *node);
	void preOrder(Node *node);
	Node *removeNode(Node *node, string courseId);
public:
	Courses();
	virtual ~Courses();
	void InOrder();
	void PostOrder();
	void PreOrder();
	void Insert(Course course);
	void Remove(string courseId);
	Course Search(string courseId);
};

#endif