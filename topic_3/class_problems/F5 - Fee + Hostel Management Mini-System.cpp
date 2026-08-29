#include <iostream>
using namespace std;

class FeeAccount
{
protected:
    double totalFee;
    double amountPaid;

public:
    FeeAccount(double fee)
    {
        totalFee = fee;
        amountPaid = 0;
    }

    void pay(double amount)
    {
        if (amount > 0)
        {
            amountPaid += amount;
        }
        else
        {
            cout << "Payment rejected" << endl;
        }
    }

    double getDue()
    {
        return totalFee - amountPaid;
    }
};

class HostelFeeAccount : public FeeAccount
{
public:
    HostelFeeAccount(double fee)
        : FeeAccount(fee)
    {
    }
};

class HostelRoom
{
public:
    string roomNo;
    int beds;
    int occupied;

    HostelRoom(string r, int b, int o)
    {
        roomNo = r;
        beds = b;
        occupied = o;
    }

    bool allot()
    {
        if (occupied < beds)
        {
            occupied++;
            return true;
        }

        return false;
    }
};

class SrmStudent
{
public:
    string name;
    string regNo;

    HostelFeeAccount feeAccount;
    HostelRoom* room;

    static int totalStudents;

    SrmStudent(
        string n,
        string r,
        double fee
    ) : feeAccount(fee)
    {
        name = n;
        regNo = r;
        room = nullptr;

        totalStudents++;
    }

    string fullStatus()
    {
        string result;

        result = name + " | Due: Rs "
               + to_string(feeAccount.getDue())
               + " | Room: ";

        if (room == nullptr)
        {
            result += "unallotted";
        }
        else
        {
            result += room->roomNo;
        }

        return result;
    }
};

int SrmStudent::totalStudents = 0;

int main()
{
    HostelRoom room1("C-214", 1, 0);
    HostelRoom room2("C-507", 1, 0);

    SrmStudent ravi(
        "Ravi",
        "RA001",
        200000
    );

    SrmStudent anitha(
        "Anitha",
        "RA002",
        200000
    );

    SrmStudent karthik(
        "Karthik",
        "RA003",
        200000
    );

    // Payments
    ravi.feeAccount.pay(60000);

    anitha.feeAccount.pay(20000);

    // Negative payment is rejected
    karthik.feeAccount.pay(-5000);

    // Allot rooms to first two students
    if (room1.allot())
        ravi.room = &room1;

    if (room2.allot())
        anitha.room = &room2;

    cout << ravi.fullStatus() << endl;
    cout << anitha.fullStatus() << endl;
    cout << karthik.fullStatus() << endl;

    cout << "Total students: "
         << SrmStudent::totalStudents
         << endl;

    return 0;
}
