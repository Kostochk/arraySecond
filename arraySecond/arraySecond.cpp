#include <iostream>
#include <ctime>
using namespace std;

const int STUDENTS = 5;
const int SUBJECTS = 13;

int main() {
    srand(time(0));
    int grades[STUDENTS][SUBJECTS];

    for (int i = 0; i < STUDENTS; i++) {
        for (int j = 0; j < SUBJECTS; j++) {
            grades[i][j] = rand() % 12 + 1;
        }
    }

    cout << "Student Grades:\n";
    for (int i = 0; i < STUDENTS; i++) {
        cout << "Student " << i + 1 << ": ";
        for (int j = 0; j < SUBJECTS; j++) {
            cout << grades[i][j] << " ";
        }
        cout << endl;
    }

    double averages[STUDENTS];
    for (int i = 0; i < STUDENTS; i++) {
        int sum = 0;
        for (int j = 0; j < SUBJECTS; j++) {
            sum += grades[i][j];
        }
        averages[i] = static_cast<double>(sum) / SUBJECTS;
        cout << "Average grade for Student " << i + 1 << ": " << averages[i] << endl;
    }

    for (int i = 0; i < STUDENTS; i++) {
        if (averages[i] < 6) {
            cout << "Student " << i + 1 << " is not certified.\n";
        }
    }

    int honorsCount = 0;
    for (int i = 0; i < STUDENTS; i++) {
        if (averages[i] > 8) {
            honorsCount++;
        }
    }
    if (honorsCount > STUDENTS / 2) {
        cout << "The class is an honors class.\n";
    }

    for (int i = 0; i < STUDENTS; i++) {
        int highGradeCount = 0;
        cout << "Grades above 9 for Student " << i + 1 << ": ";
        for (int j = 0; j < SUBJECTS; j++) {
            if (grades[i][j] > 9) {
                cout << grades[i][j] << " ";
                highGradeCount++;
            }
        }
        cout << endl;
        if (highGradeCount > SUBJECTS / 2) {
            cout << "Student " << i + 1 << " is an honors student.\n";
        }
    }

    for (int i = 0; i < STUDENTS; i++) {
        for (int j = 0; j < SUBJECTS; j++) {
            int attempts = 0;
            while (grades[i][j] < 9 && attempts < 3) {
                grades[i][j] = rand() % 4 + 9;
                attempts++;
            }
        }
    }

    cout << "\nGrades after correction:\n";
    for (int i = 0; i < STUDENTS; i++) {
        cout << "Student " << i + 1 << ": ";
        for (int j = 0; j < SUBJECTS; j++) {
            cout << grades[i][j] << " ";
        }
        cout << endl;
    }

    for (int j = 0; j < SUBJECTS; j++) {
        bool allBelowNine = true;
        for (int i = 0; i < STUDENTS; i++) {
            if (grades[i][j] >= 9) {
                allBelowNine = false;
                break;
            }
        }
        if (allBelowNine) {
            cout << "All students scored below 9 in subject " << j + 1 << endl;
        }
    }

    return 0;
}
