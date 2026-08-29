#include <iostream>
using namespace std;

string maskPhoneNumber(string phone)
{
    // Check length
    if (phone.length() != 10)
        return "Invalid phone number";

    // Check digits
    for (int i = 0; i < phone.length(); i++)
    {
        if (phone[i] < '0' || phone[i] > '9')
            return "Invalid phone number";
    }

    string result = "XXXXXX-";

    result += phone.substr(6, 4);

    return result;
}

int main()
{
    string phone;

    cout << "Enter phone number: ";
    cin >> phone;

    cout << maskPhoneNumber(phone);

    return 0;
}
