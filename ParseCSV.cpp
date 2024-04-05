/*
Jonathan Argueta-Herrera
Mod 6: Parse CSV purchase order
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inputFile("orders.csv"); // Open CSV file

    if (!inputFile.is_open())
    { // Check if file opened successfully
        cerr << "Error opening file." << endl;
        return 1;
    }

    string line;
    double totalCost = 0.0;

    // Skip header line
    getline(inputFile, line);

    while (getline(inputFile, line))
    {
        string sku;
        int quantity;
        double price;

        // Find the position of the commas in the line
        int comma1 = line.find(',');
        int comma2 = line.find(',', comma1 + 1);

        // Extract SKU, quantity, and price from the line
        sku = line.substr(0, comma1);
        quantity = stoi(line.substr(comma1 + 1, comma2 - comma1 - 1));
        price = stod(line.substr(comma2 + 1));

        // Calculate cost for current line item and add to total cost
        totalCost += price * quantity;
    }

    inputFile.close(); // Close file

    cout << "Total cost of order: $" << totalCost << endl;

    return 0;
}
