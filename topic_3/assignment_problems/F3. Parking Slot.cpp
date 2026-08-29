#include <iostream>
#include <string>
using namespace std;

class ParkingSlot
{
public:
    string slotNo;
    int capacity;
    int occupiedCount;

    ParkingSlot(string s, int c, int o)
    {
        slotNo = s;
        capacity = c;
        occupiedCount = o;
    }

    void allot(string vehicleNo)
    {
        if (occupiedCount < capacity)
        {
            occupiedCount++;

            cout << vehicleNo
                 << " allotted to slot "
                 << slotNo << endl;
        }
    }
};

ParkingSlot* findAvailableSlot(
    ParkingSlot* slots[],
    int n)
{
    for (int i = 0; i < n; i++)
    {
        if (slots[i]->occupiedCount <
            slots[i]->capacity)
        {
            return slots[i];
        }
    }

    return nullptr;
}

void safeAllot(
    ParkingSlot* slots[],
    int n,
    string vehicleNo)
{
    ParkingSlot* slot =
        findAvailableSlot(slots, n);

    if (slot == nullptr)
    {
        cout << "No slots available for "
             << vehicleNo << endl;
    }
    else
    {
        slot->allot(vehicleNo);
    }
}

int main()
{
    ParkingSlot slot1("A1", 4, 3);
    ParkingSlot slot2("A2", 5, 5);

    ParkingSlot* slots[] =
    {
        &slot1,
        &slot2
    };

    // First call: A1 has one free space
    safeAllot(slots, 2, "TN09AB1234");

    // Now both slots are full
    safeAllot(slots, 2, "TN09AB1234");

    return 0;
}
