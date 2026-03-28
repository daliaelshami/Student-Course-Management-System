#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <set>
#include <string>
using namespace std;

class Person {
protected:
	string name;
};

class Student : public Person {

private:
	int id;
	double gpa;
	set<string> courses;

public:
	Student(int id, string name, double gpa);

	int getId();
	double getGpa();
	string getName();
	void addCourse(string course);
	void showCourses();
	void display();
};

#endif
