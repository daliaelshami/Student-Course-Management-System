#include <iostream>
#include "StudentManager.h"
using namespace std;

int main()
{
    StudentManager manager;
    manager.loadFromFile();
    int choice;

    do {
        cout << "\n1- Add\n2- Remove\n3- Search by ID\n4- Display\n5- Enroll\n6- Show Courses\n7- Sort\n8- Save to File\n9- Search by Name\n10- Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            manager.addStudent();
            break;

        case 2: {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            manager.removeStudent(id);
            break;
        }

        case 3: {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            Student* s = manager.findStudent(id);
            if (s) s->display();
            else cout << "Not found\n";
            break;
        }

        case 4:
            manager.displayAll();
            break;

        case 5:
            manager.enrollCourse();
            break;

        case 6:
            manager.showCourses();
            break;

        case 7:
            manager.sortByGPA();
            manager.displayAll();
            break;

        case 8:
            manager.saveToFile();
            break;

        case 9: {
            string name;
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);
            Student* s = manager.findStudentByName(name);
            if (s) s->display();
            else cout << "Not found";
            break;
        }

        case 10:
            manager.saveToFile();
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 10);

    manager.saveToFile();

    return 0;
}
