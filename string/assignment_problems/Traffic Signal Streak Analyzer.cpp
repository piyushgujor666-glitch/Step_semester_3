#include <iostream>
using namespace std;

void findLongestStreak(string signalLog)
{
    int currentCount = 1;
    int longestCount = 1;

    char currentColor = signalLog[0];
    char longestColor = signalLog[0];

    for (int i = 1; i < signalLog.length(); i++)
    {
        if (signalLog[i] == signalLog[i - 1])
        {
            currentCount++;
        }
        else
        {
            currentCount = 1;
        }

        if (currentCount > longestCount)
        {
            longestCount = currentCount;
            longestColor = signalLog[i];
        }
    }

    cout << "Longest Streak: '"
         << longestColor
         << "' repeated "
         << longestCount
         << " times";
}

int main()
{
    string signalLog = "RRGGGYRR";

    findLongestStreak(signalLog);

    return 0;
}
