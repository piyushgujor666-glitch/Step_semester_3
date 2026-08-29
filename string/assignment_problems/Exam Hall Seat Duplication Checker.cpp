#include <iostream>
using namespace std;

void checkDuplicateSeats(int seatNumbers[], int n)
{
    bool duplicate = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (seatNumbers[i] == seatNumbers[j])
            {
                cout << "Duplicate Seat Number Found: "
                     << seatNumbers[i] << endl;

                duplicate = true;
            }
        }
    }

    if (!duplicate)
        cout << "No Duplicate Seats Found";
}

int main()
{
    int seatNumbers[] = {101, 102, 103, 102, 105};

    int n = 5;

    checkDuplicateSeats(seatNumbers, n);

    return 0;
}
