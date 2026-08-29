#include <iostream>
#include <cctype>
using namespace std;

string normalizeCode(string raw)
{
    // Remove spaces from beginning and end
    int start = 0;
    int end = raw.length() - 1;

    while (start <= end && raw[start] == ' ')
        start++;

    while (end >= start && raw[end] == ' ')
        end--;

    string code = raw.substr(start, end - start + 1);

    // Convert first 3 characters to uppercase
    for (int i = 0; i < 3 && i < code.length(); i++)
    {
        code[i] = toupper(code[i]);
    }

    return code;
}

string validateAndFormat(string code)
{
    // Check length
    if (code.length() != 13)
    {
        return "Invalid: wrong length";
    }

    // Check first 3 characters
    for (int i = 0; i < 3; i++)
    {
        if (!isalpha(code[i]))
        {
            return "Invalid: publisher code must be 3 letters";
        }
    }

    // Check remaining 10 characters
    for (int i = 3; i < 13; i++)
    {
        if (!isdigit(code[i]))
        {
            return "Invalid: body must contain only digits";
        }
    }

    string publisher = code.substr(0, 3);
    string year = code.substr(3, 4);
    string catalog = code.substr(7, 6);

    return "[" + publisher + "] YEAR: " +
           year + " | CATALOG: " + catalog;
}

int main()
{
    string raw;

    cout << "Enter code: ";
    getline(cin, raw);

    string code = normalizeCode(raw);

    cout << validateAndFormat(code);

    return 0;
}
