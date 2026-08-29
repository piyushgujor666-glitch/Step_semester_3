#include <iostream>
using namespace std;

void analyzeInventory(int sectionA[], int sectionB[], int n)
{
    int totalA = 0;
    int totalB = 0;

    // Calculate totals
    for (int i = 0; i < n; i++)
    {
        totalA += sectionA[i];
        totalB += sectionB[i];
    }

    // Find highest quantity
    int highest = sectionA[0];
    char section = 'A';
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        if (sectionA[i] > highest)
        {
            highest = sectionA[i];
            section = 'A';
            index = i;
        }

        if (sectionB[i] > highest)
        {
            highest = sectionB[i];
            section = 'B';
            index = i;
        }
    }

    cout << "Section A Total: " << totalA << endl;
    cout << "Section B Total: " << totalB << endl;

    if (totalA == totalB)
        cout << "Status: Balanced" << endl;
    else
        cout << "Status: Not Balanced" << endl;

    cout << "Highest Quantity: " << highest << endl;
    cout << "Section: " << section << endl;
    cout << "Item: " << index + 1 << endl;
}

int main()
{
    int sectionA[] = {20, 15, 30};
    int sectionB[] = {25, 10, 30};

    int n = 3;

    analyzeInventory(sectionA, sectionB, n);

    return 0;
}
