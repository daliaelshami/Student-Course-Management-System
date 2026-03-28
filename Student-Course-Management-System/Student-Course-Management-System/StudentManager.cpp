#include "StudentManager.h"
#include <algorithm>
#include <string>
#include <fstream>

void StudentManager::addStudent() {
    int id;
    string name;
    double gpa;

    cout << "Enter ID: ";

    while (!(cin >> id)) {
        cout << "Invalid input. Please enter a numeric ID: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    if (findStudent(id) != nullptr) {
        cout << "Student ID already exists" << endl;
        return;
    }

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter GPA (0.0 - 4.0): ";
    while (!(cin >> gpa) || gpa < 0.0 || gpa > 4.0) {
        cout << "Invalid GPA. Please enter a value between 0.0 and 4.0: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    students.push_back(Student(id, name, gpa));
    cout << "Student Added Successfully!" << endl;
}

Student* StudentManager::findStudent(int id) {
    for (auto& s : students) {
        if (s.getId() == id)
            return &s;
    }
    return nullptr;
}

Student* StudentManager::findStudentByName(string name) {
    for (auto& s : students) {
        if (s.getName() == name) {
            return &s;
        }
    }
    return nullptr;
}

void StudentManager::removeStudent(int id) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {
            students.erase(students.begin() + i);
            cout << "Deleted!" << endl;
            return;
        }
    }
    cout << "Not found!" << endl;
}

void StudentManager::displayAll() {
    if (students.empty()) {
        cout << "No students found\n";
        return;
    }

    for (auto& s : students) {
        s.display();
    }
}

void StudentManager::enrollCourse() {
    int id;
    string course;

    cout << "Enter Student ID: ";
    cin >> id;

    Student* s = findStudent(id);

    if (s) {
        cout << "Enter course: ";
        cin.ignore();
        getline(cin, course);
        s->addCourse(course);
        cout << "Course enrolled successfully\n";
    }
    else {
        cout << "Student not found" << endl;
    }
}

void StudentManager::showCourses() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    Student* s = findStudent(id);

    if (s) {
        s->showCourses();
    }
    else {
        cout << "Not found" << endl;
    }
}

void StudentManager::sortByGPA() {
    sort(students.begin(), students.end(), [](Student& a, Student& b) {
        return a.getGpa() > b.getGpa();
        });
}

void StudentManager::saveToFile() {
    ofstream outFile("students_db.txt");
    if (!outFile) {
        cout << "Error opening file for saving" << endl;
        return;
    }

    for (auto& s : students) {
        outFile << s.getId() << " " << s.getName() << "|" << s.getGpa() << endl;
    }

    outFile.close();
    cout << "Data saved successfully to students_db.txt" << endl;
}

void StudentManager::loadFromFile() {
    ifstream inFile("students_db.txt");
    if (!inFile) {
        return;
    }

    int id;
    string name;
    double gpa;

    while (inFile >> id) {
        inFile.ignore();
        getline(inFile, name, '|');
        inFile >> gpa;

        students.push_back(Student(id, name, gpa));
    }

    inFile.close();
}