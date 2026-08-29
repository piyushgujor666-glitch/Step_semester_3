#include <iostream>
using namespace std;

class SrmStudent
{
public:
    static string name;
    static string regNo;
    static int attendance;

    SrmStudent(string n, string r, int a)
    {
        name = n;
        regNo = r;
        attendance = a;
    }
};

string SrmStudent::name = "";
string SrmStudent::regNo = "";
int SrmStudent::attendance = 0;

int main()
{
    SrmStudent s1("Ravi", "RA001", 82);
    SrmStudent s2("Meera", "RA002", 74);

    cout << s1.name << endl;
    cout << s2.name << endl;

    return 0;
}
