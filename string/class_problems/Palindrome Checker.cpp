#include <iostream>
#include <algorithm>
using namespace std;

bool isPalindromeIterative(string text)
{
    int left = 0;
    int right = text.length() - 1;

    while (left < right)
    {
        if (text[left] != text[right])
            return false;

        left++;
        right--;
    }

    return true;
}

bool isPalindromeRecursive(string text, int left, int right)
{
    if (left >= right)
        return true;

    if (text[left] != text[right])
        return false;

    return isPalindromeRecursive(text, left + 1, right - 1);
}

bool isPalindromeArrayReversal(string text)
{
    string reverseText = text;

    reverse(reverseText.begin(), reverseText.end());

    return text == reverseText;
}

int main()
{
    string text;

    cout << "Enter a word: ";
    cin >> text;

    cout << "\nIterative: ";

    if (isPalindromeIterative(text))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    cout << "\nRecursive: ";

    if (isPalindromeRecursive(text, 0, text.length() - 1))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    cout << "\nArray Reversal: ";

    if (isPalindromeArrayReversal(text))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}
