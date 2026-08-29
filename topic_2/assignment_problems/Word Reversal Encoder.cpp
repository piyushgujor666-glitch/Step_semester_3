#include <iostream>
#include <sstream>
using namespace std;

string reverseEachWord(string sentence)
{
    string word;
    string result = "";

    stringstream ss(sentence);

    while (ss >> word)
    {
        string reverseWord = "";

        for (int i = word.length() - 1; i >= 0; i--)
        {
            reverseWord += word[i];
        }

        result += reverseWord;
        result += " ";
    }

    return result;
}

int main()
{
    string sentence;

    cout << "Enter sentence: ";
    getline(cin, sentence);

    cout << reverseEachWord(sentence);

    return 0;
}
