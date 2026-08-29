#include <iostream>
#include <string>
using namespace std;


// ---------------- Employee ----------------

class Employee
{
private:
    string empId;
    string empName;
    double salary;

public:
    Employee(
        string id,
        string name,
        double s
    )
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


// ---------------- Manager ----------------

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


// ---------------- Intern ----------------

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


// ---------------- Parking Slot ----------------

class ParkingSlot
{
public:
    string slotNo;
    int capacity;
    int occupiedCount;

    ParkingSlot(
        string s,
        int c,
        int o
    )
    {
        slotNo = s;
        capacity = c;
        occupiedCount = o;
    }

    bool allot()
    {
        if (occupiedCount < capacity)
        {
            occupiedCount++;
            return true;
        }

        return false;
    }
};


// ---------------- Company Record ----------------

class CompanyEmployeeRecord
{
public:
    string name;
    string empId;

    Employee* employee;
    ParkingSlot* slot;

    static int totalRecords;

    CompanyEmployeeRecord(
        string n,
        string id,
        Employee* e
    )
    {
        name = n;
        empId = id;
        employee = e;
        slot = nullptr;

        totalRecords++;
    }

    double getEffectivePay()
    {
        // C++ equivalent of instanceof
        ManagerEmployee* manager =
            dynamic_cast<ManagerEmployee*>(employee);

        if (manager != nullptr)
        {
            return manager->effectiveSalary();
        }

        InternEmployee* intern =
            dynamic_cast<InternEmployee*>(employee);

        if (intern != nullptr)
        {
            return intern->effectiveSalary();
        }

        return employee->getSalary();
    }

    void fullProfile()
    {
        cout << name
             << " | Pay: Rs "
             << getEffectivePay()
             << " | Slot: ";

        if (slot == nullptr)
        {
            cout << "no parking assigned";
        }
        else
        {
            cout << slot->slotNo;
        }

        cout << endl;
    }
};

int CompanyEmployeeRecord::totalRecords = 0;


// ---------------- Main ----------------

int main()
{
    // Employees
    ManagerEmployee manager(
        "E001",
        "Divya",
        70000,
        8000
    );

    Employee employee(
        "E002",
        "Karan",
        40000
    );

    InternEmployee intern(
        "E003",
        "Meera",
        12000,
        10000
    );


    // Parking
    ParkingSlot slot1("A1", 1, 0);
    ParkingSlot slot2("A2", 1, 0);


    // Records
    CompanyEmployeeRecord r1(
        "Divya",
        "E001",
        &manager
    );

    CompanyEmployeeRecord r2(
        "Karan",
        "E002",
        &employee
    );

    CompanyEmployeeRecord r3(
        "Meera",
        "E003",
        &intern
    );


    // Allot parking to first two
    if (slot1.allot())
    {
        r1.slot = &slot1;
    }

    if (slot2.allot())
    {
        r2.slot = &slot2;
    }


    // Print profiles
    r1.fullProfile();
    r2.fullProfile();
    r3.fullProfile();


    cout << "Total records: "
         << CompanyEmployeeRecord::totalRecords
         << endl;

    return 0;
}
