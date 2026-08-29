#include <iostream>
#include <string>
using namespace std;

class BookIssue
{
private:
    string title;
    string borrowerName;
    int daysOverdue;

public:
    BookIssue(string t, string b, int d)
    {
        title = t;
        borrowerName = b;
        daysOverdue = d;
    }

    double fineAmount()
    {
        if (daysOverdue > 0)
            return daysOverdue * 5;

        return 0;
    }

    bool isSeverelyOverdue()
    {
        return daysOverdue > 14;
    }

    static double totalFineCollected(BookIssue issues[], int n)
    {
        double total = 0;

        for (int i = 0; i < n; i++)
        {
            total += issues[i].fineAmount();
        }

        return total;
    }

    void printDetails()
    {
        cout << title << " - "
             << daysOverdue << " days - ";

        if (isSeverelyOverdue())
            cout << "Severely overdue";
        else
            cout << "OK";

        cout << endl;
    }
};

int main()
{
    BookIssue issues[5] =
    {
        BookIssue("Clean Code", "Ravi", 18),
        BookIssue("Effective Java", "Anitha", 5),
        BookIssue("Refactoring", "Karthik", 0),
        BookIssue("DSA Handbook", "Meera", 21),
        BookIssue("Design Patterns", "Suresh", 9)
    };

    for (int i = 0; i < 5; i++)
    {
        issues[i].printDetails();
    }

    cout << "Total fine collected: Rs "
         << BookIssue::totalFineCollected(issues, 5)
         << endl;

    return 0;
}
