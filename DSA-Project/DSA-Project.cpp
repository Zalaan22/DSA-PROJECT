#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Course {
public:
    double grade;
    double credits;

    Course(double grade, double credits) {
        this->grade = grade;
        this->credits = credits;
    }
};

class Semester {
public:
    vector<Course> courses;

    void addCourse(double grade, double credits) {
        courses.push_back(Course(grade, credits));
    }

    double calculateGPA() {
        double totalPoints = 0;
        double totalCredits = 0;
        for (const Course& course : courses) {
            totalPoints += course.grade * course.credits;
            totalCredits += course.credits;
        }
        return totalCredits == 0 ? 0 : totalPoints / totalCredits;
    }
};

class Student {
public:
    vector<Semester> semesters;

    void addSemester(Semester semester) {
        semesters.push_back(semester);
    }

    double calculateCGPA() {
        double totalPoints = 0;
        double totalCredits = 0;
        for (const Semester& semester : semesters) {
            for (const Course& course : semester.courses) {
                totalPoints += course.grade * course.credits;
                totalCredits += course.credits;
            }
        }
        return totalCredits == 0 ? 0 : totalPoints / totalCredits;
    }
};

double gradeToPoint(const string& grade) {
    unordered_map<string, double> gradeMap = {
        {"A", 4.0}, {"B", 3.0}, {"C", 2.0}, {"D", 1.0}, {"F", 0.0}
    };
    return gradeMap[grade];
}

int main() {
    Student student;

    int numSemesters;
    cout << "Enter number of semesters: ";
    cin >> numSemesters;

    for (int i = 0; i < numSemesters; i++) {
        Semester semester;
        int numCourses;
        cout << "Enter number of courses in semester " << i + 1 << ": ";
        cin >> numCourses;

        for (int j = 0; j < numCourses; j++) {
            string grade;
            double credits;
            cout << "Enter grade (A, B, C, D, F) and credits for course " << j + 1 << ": ";
            cin >> grade >> credits;
            semester.addCourse(gradeToPoint(grade), credits);
        }

        student.addSemester(semester);
    }

    cout << "CGPA: " << student.calculateCGPA() << endl;

    return 0;
}
