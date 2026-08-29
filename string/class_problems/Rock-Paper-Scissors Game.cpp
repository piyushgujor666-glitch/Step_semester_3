#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

string playRound(string player, string computer)
{
    if (player == computer)
        return "Draw";

    if ((player == "Rock" && computer == "Scissors") ||
        (player == "Paper" && computer == "Rock") ||
        (player == "Scissors" && computer == "Paper"))
    {
        return "Player Wins";
    }

    return "Computer Wins";
}

int main()
{
    srand(time(0));

    string moves[3] = {"Rock", "Paper", "Scissors"};

    int n = 5;
    int wins = 0, losses = 0, draws = 0;

    cout << "Rock Paper Scissors Game\n\n";

    for (int i = 0; i < n; i++)
    {
        string player;

        cout << "Round " << i + 1 << endl;
        cout << "Enter Rock, Paper or Scissors: ";
        cin >> player;

        int randomNumber = rand() % 3;
        string computer = moves[randomNumber];

        string result = playRound(player, computer);

        cout << "Player: " << player << endl;
        cout << "Computer: " << computer << endl;
        cout << "Result: " << result << endl;
        cout << "-------------------\n";

        if (result == "Player Wins")
            wins++;
        else if (result == "Computer Wins")
            losses++;
        else
            draws++;
    }

    double winPercentage = (wins * 100.0) / n;

    cout << "\nFinal Summary\n";
    cout << "Wins: " << wins << endl;
    cout << "Losses: " << losses << endl;
    cout << "Draws: " << draws << endl;
    cout << "Win Percentage: " << winPercentage << "%\n";

    return 0;
}
