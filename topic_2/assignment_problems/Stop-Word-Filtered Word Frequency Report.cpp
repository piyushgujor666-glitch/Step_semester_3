#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

bool isStopWord(string word)
{
    string stopWords[] = {
        "the", "was", "and", "a",
        "is", "of", "in"
    };

    for (int i = 0; i < 7; i++)
    {
        if (word == stopWords[i])
            return true;
    }

    return false;
}

void printFilteredWordFrequency(string feedback)
{
    // Convert to lowercase
    for (int i = 0; i < feedback.length(); i++)
    {
        if (feedback[i] >= 'A' && feedback[i] <= 'Z')
        {
            feedback[i] = feedback[i] + 32;
        }
    }

    // Remove punctuation
    for (int i = 0; i < feedback.length(); i++)
    {
        if (feedback[i] == '.' || feedback[i] == ',')
        {
            feedback[i] = ' ';
        }
    }

    map<string, int> frequency;

    string word;
    stringstream ss(feedback);

    // Count words
    while (ss >> word)
    {
        if (!isStopWord(word))
        {
            frequency[word]++;
        }
    }

    // Store word and count
    vector<pair<string, int>> words;

    for (auto item : frequency)
    {
        words.push_back(item);
    }

    // Sort by count descending
    sort(words.begin(), words.end(),
        [](pair<string, int> a, pair<string, int> b)
        {
            return a.second > b.second;
        });

    // Print result
    for (auto item : words)
    {
        cout << item.first << ": "
             << item.second << endl;
    }
}

int main()
{
    string feedback;

    cout << "Enter feedback: ";
    getline(cin, feedback);

    printFilteredWordFrequency(feedback);

    return 0;
}
