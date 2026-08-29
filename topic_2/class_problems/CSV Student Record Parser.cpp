#include <iostream>
#include <sstream>
using namespace std;

void parseStudentRecord(string csvLine)
{
    string name, rollNo, department;

    stringstream ss(csvLine);

    getline(ss, name, ',');
    getline(ss, rollNo, ',');
    getline(ss, department, ',');

    if (name == "" || rollNo == "" || department == "")
    {
        cout << "Invalid Record";
        return;
    }

    cout << "Name: " << name << endl;
    cout << "Roll No: " << rollNo << endl;
    cout << "Dept: " << department << endl;
}

int main()
{
    string csvLine;

    cout << "Enter student record: ";
    getline(cin, csvLine);

    parseStudentRecord(csvLine);

    return 0;
}
