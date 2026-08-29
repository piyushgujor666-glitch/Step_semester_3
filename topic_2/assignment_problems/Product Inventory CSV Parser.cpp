#include <iostream>
#include <sstream>
using namespace std;

void parseInventoryRecord(string csvLine)
{
    string product;
    string sku;
    string quantity;
    string extra;

    stringstream ss(csvLine);

    getline(ss, product, ',');
    getline(ss, sku, ',');
    getline(ss, quantity, ',');

    // Check if there is an extra field
    if (getline(ss, extra, ','))
    {
        cout << "Invalid Record";
        return;
    }

    if (product == "" || sku == "" || quantity == "")
    {
        cout << "Invalid Record";
        return;
    }

    cout << "Product: " << product << endl;
    cout << "SKU: " << sku << endl;
    cout << "Qty: " << quantity << endl;
}

int main()
{
    string csvLine;

    cout << "Enter inventory record: ";
    getline(cin, csvLine);

    parseInventoryRecord(csvLine);

    return 0;
}
