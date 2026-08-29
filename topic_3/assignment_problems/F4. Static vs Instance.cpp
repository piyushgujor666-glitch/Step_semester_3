#include <iostream>
using namespace std;

class LibraryMember
{
public:
    // WRONG:
    // These are static, so only ONE copy exists
    // for the entire class.
    static string name;
    static string memberId;
    static int booksIssued;

    LibraryMember(
        string n,
        string id,
        int books
    )
    {
        name = n;
        memberId = id;
        booksIssued = books;
    }
};

string LibraryMember::name = "";
string LibraryMember::memberId = "";
int LibraryMember::booksIssued = 0;

int main()
{
    LibraryMember m1(
        "Aditi",
        "LM-1001",
        2
    );

    LibraryMember m2(
        "Rohan",
        "LM-1002",
        3
    );

    cout << m1.name << endl;
    cout << m2.name << endl;

    return 0;
}
