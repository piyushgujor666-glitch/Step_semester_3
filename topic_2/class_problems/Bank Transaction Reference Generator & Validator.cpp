#include <iostream>
#include <cctype>
using namespace std;

string normalizeReference(string raw)
{
    // Remove spaces from beginning and end
    int start = 0;
    int end = raw.length() - 1;

    while (start <= end && raw[start] == ' ')
        start++;

    while (end >= start && raw[end] == ' ')
        end--;

    string reference = raw.substr(start, end - start + 1);

    // Convert first 3 characters to uppercase
    for (int i = 0; i < 3 && i < reference.length(); i++)
    {
        reference[i] = toupper(reference[i]);
    }

    return reference;
}

string validateAndFormat(string reference)
{
    // Check length
    if (reference.length() != 14)
        return "Invalid: wrong length";

    // Check first 3 characters are letters
    for (int i = 0; i < 3; i++)
    {
        if (!isalpha(reference[i]))
            return "Invalid: bank code must be 3 letters";
    }

    // Check remaining 11 characters are digits
    for (int i = 3; i < 14; i++)
    {
        if (!isdigit(reference[i]))
            return "Invalid: body must contain only digits";
    }

    string bankCode = reference.substr(0, 3);
    string date = reference.substr(3, 6);
    string sequence = reference.substr(9, 5);

    string formatted = "[" + bankCode + "] DATE: ";

    formatted += date.substr(0, 2);
    formatted += "/";
    formatted += date.substr(2, 2);
    formatted += "/";
    formatted += date.substr(4, 2);

    formatted += " | SEQ: ";
    formatted += sequence;

    return formatted;
}

int main()
{
    string raw;

    cout << "Enter reference: ";
    getline(cin, raw);

    string reference = normalizeReference(raw);

    cout << validateAndFormat(reference);

    return 0;
}
