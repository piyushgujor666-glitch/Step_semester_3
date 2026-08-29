#include <iostream>
#include <iomanip>
using namespace std;

string getBmiStatus(double bmi)
{
    if (bmi < 18.5)
        return "Underweight";
    else if (bmi < 25)
        return "Normal";
    else if (bmi < 30)
        return "Overweight";
    else
        return "Obese";
}

void printWellnessReport(double heights[], double weights[], int n)
{
    cout << fixed << setprecision(2);

    cout << "\nPerson\tHeight\tWeight\tBMI\tStatus\n";
    cout << "-------------------------------------------\n";

    for (int i = 0; i < n; i++)
    {
        double bmi = weights[i] / (heights[i] * heights[i]);

        cout << i + 1 << "\t"
             << heights[i] << "\t"
             << weights[i] << "\t"
             << bmi << "\t"
             << getBmiStatus(bmi) << endl;
    }
}

int main()
{
    int n;

    cout << "Enter number of people: ";
    cin >> n;

    double heights[n];
    double weights[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nPerson " << i + 1 << endl;

        cout << "Enter height (m): ";
        cin >> heights[i];

        cout << "Enter weight (kg): ";
        cin >> weights[i];
    }

    printWellnessReport(heights, weights, n);

    return 0;
}
