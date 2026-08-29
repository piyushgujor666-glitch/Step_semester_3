#include <iostream>
using namespace std;

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

    void allot(string name)
    {
        if (occupied < beds)
        {
            occupied++;

            cout << name
                 << " allotted to room "
                 << roomNo << endl;
        }
    }
};

HostelRoom* findAvailableRoom(
    HostelRoom* rooms[],
    int n)
{
    for (int i = 0; i < n; i++)
    {
        if (rooms[i]->occupied < rooms[i]->beds)
        {
            return rooms[i];
        }
    }

    return nullptr;
}

void safeAllot(
    HostelRoom* rooms[],
    int n,
    string studentName)
{
    HostelRoom* room =
        findAvailableRoom(rooms, n);

    if (room == nullptr)
    {
        cout << "No rooms available for "
             << studentName << endl;
    }
    else
    {
        room->allot(studentName);
    }
}

int main()
{
    HostelRoom room1("C-214", 3, 2);
    HostelRoom room2("C-507", 2, 2);

    HostelRoom* rooms[] =
    {
        &room1,
        &room2
    };

    safeAllot(rooms, 2, "Divya");

    safeAllot(rooms, 2, "Divya");

    return 0;
}
