#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    string empId;
    string empName;
    double salary;

public:
    Employee(string id, string name, double s)
    {
        empId = id;
        empName = name;
        salary = s;
    }

    double getSalary()
    {
        return salary;
    }

    virtual ~Employee()
    {
    }
};

class ManagerEmployee : public Employee
{
private:
    double teamBonus;

public:
    ManagerEmployee(
        string id,
        string name,
        double salary,
        double bonus
    ) : Employee(id, name, salary)
    {
        teamBonus = bonus;
    }

    double effectiveSalary()
    {
        return getSalary() + teamBonus;
    }
};

class InternEmployee : public Employee
{
private:
    double stipendCap;

public:
    InternEmployee(
        string id,
        string name,
        double salary,
        double cap
    ) : Employee(id, name, salary)
    {
        stipendCap = cap;
    }

    double effectiveSalary()
    {
        if (getSalary() < stipendCap)
            return getSalary();

        return stipendCap;
    }
};

int main()
{
    Employee plain(
        "E001",
        "Ravi",
        40000
    );

    ManagerEmployee manager(
        "E002",
        "Divya",
        70000,
        8000
    );

    InternEmployee intern(
        "E003",
        "Meera",
        12000,
        10000
    );

    cout << "Plain employee pay: Rs "
         << plain.getSalary() << endl;

    cout << "Manager effective pay: Rs "
         << manager.effectiveSalary() << endl;

    cout << "Intern effective pay: Rs "
         << intern.effectiveSalary() << endl;

    return 0;
}
