#include <bits/stdc++.h>
using namespace std;

class SrmStudent {
    string name;
    string regNo;
    int attendance;

public:

    SrmStudent(string name, string regNo, int attendance) {
        this->name = name;
        this->regNo = regNo;
        this->attendance = attendance;
    }

    void addAttendanceUpdate(int newAttendance) {
        attendance = newAttendance;
    }

    bool isEligible() {
        return attendance >= 75;
    }

    static double classAverage(SrmStudent students[]) {
        int total = 0;

        for (int i = 0; i < 5; i++) {
            total += students[i].attendance;
        }

        return total / 5.0;
    }

    string getName() {
        return name;
    }
};

int main() {

    SrmStudent students[5] = {
        SrmStudent("Piyush", "RA2511003012106", 80),
        SrmStudent("Rahul", "RA2511003012107", 72),
        SrmStudent("Aman", "RA2511003012108", 90),
        SrmStudent("Rohan", "RA2511003012109", 65),
        SrmStudent("Karan", "RA2511003012110", 78)
    };

    for (int i = 0; i < 5; i++) {
        cout << students[i].getName() << " : ";

        if (students[i].isEligible()) {
            cout << "Eligible for exam";
        } else {
            cout << "Not eligible for exam";
        }

        cout << endl;
    }

    cout << "Class Average Attendance: "
         << SrmStudent::classAverage(students) << "%" << endl;

    return 0;
}
