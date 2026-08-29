#include <iostream>
#include <iomanip>
using namespace std;

void checkTypingAccuracy(string original, string typed)
{
    int matched = 0;
    int firstMismatch = -1;

    for (int i = 0; i < original.length(); i++)
    {
        if (original[i] == typed[i])
        {
            matched++;
        }
        else if (firstMismatch == -1)
        {
            firstMismatch = i;
        }
    }

    double accuracy = (matched * 100.0) / original.length();

    cout << fixed << setprecision(2);

    cout << "Matched: " << matched << "/"
         << original.length() << endl;

    cout << "Accuracy: " << accuracy << "%" << endl;

    if (firstMismatch == -1)
    {
        cout << "No Mismatches";
    }
    else
    {
        cout << "First Mismatch at position "
             << firstMismatch + 1 << endl;

        cout << "Original: " << original[firstMismatch] << endl;
        cout << "Typed: " << typed[firstMismatch] << endl;
    }
}

int main()
{
    string original = "hello world";
    string typed = "hello worlt";

    checkTypingAccuracy(original, typed);

    return 0;
}
