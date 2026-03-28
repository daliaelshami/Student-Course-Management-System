#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H
#include "Student.h"
#include <vector>
#include <fstream>

class StudentManager {

private:
	vector<Student> students;

public:
	void addStudent();
	void removeStudent(int id);
	Student* findStudent(int id);
	Student* findStudentByName(string name);
	void displayAll();
	void enrollCourse();
	void showCourses();
	void sortByGPA();
	void saveToFile();
	void loadFromFile();
};

#endif