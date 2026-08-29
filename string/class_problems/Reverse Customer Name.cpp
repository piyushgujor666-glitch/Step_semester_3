#include <iostream>
using namespace std;

string reverseCustomerName(string customerName)
{
    string reverseName = "";

    for (int i = customerName.length() - 1; i >= 0; i--)
    {
        reverseName += customerName[i];
    }

    return reverseName;
}

int main()
{
    string customerName;

    cout << "Enter customer name: ";
    cin >> customerName;

    string reversedName = reverseCustomerName(customerName);

    cout << "Original Name: " << customerName << endl;
    cout << "Reversed Name: " << reversedName << endl;

    return 0;
}
