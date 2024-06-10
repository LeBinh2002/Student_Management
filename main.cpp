#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream> // Include for file operations

using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string address;
    string group; // Student group: "Natural" or "Social"
    float avgGrade; // Average grade
};

class StudentManagement {
private:
    vector<Student> students;

public:
    void addStudent() {
        system("cls"); // Clear console screen
        Student s;
        cout << "--- Add Student ---\n";
        cout << "Enter student ID: ";
        cin >> s.id;
        cin.ignore();
        cout << "Enter student name: ";
        getline(cin, s.name);
        cout << "Enter student age: ";
        cin >> s.age;
        cin.ignore();
        cout << "Enter student address: ";
        getline(cin, s.address);

        // Input grades for main subjects
        float math, literature, english;
        cout << "Enter grade for Math: ";
        cin >> math;
        cout << "Enter grade for Literature: ";
        cin >> literature;
        cout << "Enter grade for English: ";
        cin >> english;

        // Input grades for group subjects
        int choice;
        cout << "Select group of subjects:\n";
        cout << "1. Natural (Physics, Chemistry, Biology)\n";
        cout << "2. Social (History, Geography, Civic Education)\n";
        cout << "Enter your choice: ";
        cin >> choice;

        float grade1, grade2, grade3;
        if (choice == 1) {
            s.group = "Natural";
            cout << "Enter grade for Physics: ";
            cin >> grade1;
            cout << "Enter grade for Chemistry: ";
            cin >> grade2;
            cout << "Enter grade for Biology: ";
            cin >> grade3;
        } else if (choice == 2) {
            s.group = "Social";
            cout << "Enter grade for History: ";
            cin >> grade1;
            cout << "Enter grade for Geography: ";
            cin >> grade2;
            cout << "Enter grade for Civic Education: ";
            cin >> grade3;
        } else {
            cout << "Invalid choice. Aborting add student.\n";
            return;
        }

        // Calculate average grade
        s.avgGrade = (math + literature + english + grade1 + grade2 + grade3) / 6.0;
        students.push_back(s);
        cout << "Student added successfully!" << endl;
    }

    void deleteStudent() {
        system("cls"); // Clear console screen
        int id;
        cout << "--- Delete Student ---\n";
        cout << "Enter student ID to delete: ";
        cin >> id;
        auto it = remove_if(students.begin(), students.end(), [id](Student &s) { return s.id == id; });
        if (it != students.end()) {
            students.erase(it, students.end());
            cout << "Student deleted successfully!" << endl;
        } else {
            cout << "Student not found!" << endl;
        }
    }

    void updateStudent() {
        system("cls"); // Clear console screen
        int id;
        cout << "--- Update Student ---\n";
        cout << "Enter student ID to update: ";
        cin >> id;
        cin.ignore();
        for (auto &s : students) {
            if (s.id == id) {
                cout << "Enter new student name: ";
                getline(cin, s.name);
                cout << "Enter new student age: ";
                cin >> s.age;
                cin.ignore();
                cout << "Enter new student address: ";
                getline(cin, s.address);

                // Input grades for main subjects
                float math, literature, english;
                cout << "Enter grade for Math: ";
                cin >> math;
                cout << "Enter grade for Literature: ";
                cin >> literature;
                cout << "Enter grade for English: ";
                cin >> english;

                // Input grades for group subjects
                int choice;
                cout << "Select group of subjects:\n";
                cout << "1. Natural (Physics, Chemistry, Biology)\n";
                cout << "2. Social (History, Geography, Civic Education)\n";
                cout << "Enter your choice: ";
                cin >> choice;

                float grade1, grade2, grade3;
                if (choice == 1) {
                    s.group = "Natural";
                    cout << "Enter grade for Physics: ";
                    cin >> grade1;
                    cout << "Enter grade for Chemistry: ";
                    cin >> grade2;
                    cout << "Enter grade for Biology: ";
                    cin >> grade3;
                } else if (choice == 2) {
                    s.group = "Social";
                    cout << "Enter grade for History: ";
                    cin >> grade1;
                    cout << "Enter grade for Geography: ";
                    cin >> grade2;
                    cout << "Enter grade for Civic Education: ";
                    cin >> grade3;
                } else {
                    cout << "Invalid choice. Aborting update student.\n";
                    return;
                }

                // Calculate average grade
                s.avgGrade = (math + literature + english + grade1 + grade2 + grade3) / 6.0;
                cout << "Student updated successfully!" << endl;
                return;
            }
        }
        cout << "Student not found!" << endl;
    }

    void displayStudents() {
        system("cls"); // Clear console screen
        cout << "--- Display Students ---\n";
        if (students.empty()) {
            cout << "No students available!" << endl;
            return;
        }
        for (const auto &s : students) {
            cout << "ID: " << s.id << ", Name: " << s.name << ", Age: " << s.age << ", Address: " << s.address;
            cout << ", Group: " << s.group << ", Average Grade: " << s.avgGrade << endl;
        }
    }

    void exportStudentsToFile() {
        system("cls"); // Clear console screen
        cout << "--- Export Students to File ---\n";
        ofstream outFile("students.txt");
        if (!outFile) {
            cerr << "Error opening file for writing!" << endl;
            return;
        }
        for (const auto &s : students) {
            outFile << "ID: " << s.id << "\nName: " << s.name << "\nAge: " << s.age << "\nAddress: " << s.address;
            outFile << "\nGroup: " << s.group << "\nAverage Grade: " << s.avgGrade << "\n\n";
        }
        outFile.close();
        cout << "Students exported to students.txt successfully!" << endl;
    }
};

int main() {
    StudentManagement sm;
    int choice;
    do {
        system("cls"); // Clear console screen
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Update Student\n";
        cout << "4. Display Students\n";
        cout << "5. Export Students to File\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                sm.addStudent();
                system("pause"); // Pause the system to wait for user input
                break;
            case 2:
                sm.deleteStudent();
                system("pause");
                break;
            case 3:
                sm.updateStudent();
                system("pause");
                break;
            case 4:
                sm.displayStudents();
                system("pause");
                break;
            case 5:
                sm.exportStudentsToFile();
                system("pause");
                break;
            case 6:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                system("pause");
        }
    } while (choice != 6);
    return 0;
}