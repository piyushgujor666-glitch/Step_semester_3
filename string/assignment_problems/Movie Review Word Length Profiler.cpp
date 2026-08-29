#include <iostream>
#include <sstream>
using namespace std;

void classifyWordLengths(string review)
{
    string word;

    int shortWords = 0;
    int mediumWords = 0;
    int longWords = 0;

    stringstream ss(review);

    while (ss >> word)
    {
        int length = word.length();

        if (length >= 1 && length <= 4)
        {
            shortWords++;
        }
        else if (length >= 5 && length <= 8)
        {
            mediumWords++;
        }
        else
        {
            longWords++;
        }
    }

    cout << "Short: " << shortWords << endl;
    cout << "Medium: " << mediumWords << endl;
    cout << "Long: " << longWords << endl;
}

int main()
{
    string review;

    cout << "Enter movie review: ";
    getline(cin, review);

    classifyWordLengths(review);

    return 0;
}
