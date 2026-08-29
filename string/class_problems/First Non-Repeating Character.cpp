#include <iostream>
using namespace std;

char findFirstNonRepeatingChar(string text)
{
    int frequency[256] = {0};

    // Count frequency
    for (int i = 0; i < text.length(); i++)
    {
        frequency[text[i]]++;
    }

    // Find first character with frequency 1
    for (int i = 0; i < text.length(); i++)
    {
        if (frequency[text[i]] == 1)
            return text[i];
    }

    return '\0';
}

int main()
{
    string text;

    cout << "Enter a string: ";
    cin >> text;

    char answer = findFirstNonRepeatingChar(text);

    if (answer == '\0')
        cout << "No Non-Repeating Character Found";
    else
        cout << "First Non-Repeating Character: '" << answer << "'";

    return 0;
}
