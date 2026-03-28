#include "Student.h"
using namespace std;

Student::Student(int id, string name, double gpa) {
	this->id = id;
	this->name = name;
	this->gpa = gpa;
}

int Student::getId() {
	return id;
}

string Student::getName() {
	return name;
}

double Student::getGpa() {
	return gpa;
}

void Student::addCourse(string course) {
	courses.insert(course);
}

void Student::showCourses() {
	for (auto c : courses) {
		cout << c << endl;
	}
}

void Student::display() {
	cout << "ID: " << id << " | Name: " << name << " | GPA: " << gpa << endl;
}