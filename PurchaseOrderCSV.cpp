/*
Jonathan Argueta-Herrera
Mod 6: Purchase Order to CSV
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream outputFile("orders.csv"); // Create CSV file

    if (!outputFile.is_open())
    { // Check if file opened successfully
        cerr << "Error opening file." << endl;
        return 1;
    }

    // CSV header
    outputFile << "SKU,Quantity,Price" << endl;

    string sku;
    int quantity;
    double price;

    while (true)
    {
        cout << "Enter SKU (q to quit): ";
        cin >> sku;

        if (sku == "q")
        {
            break; // Exit loop if user inputs q
        }

        cout << "Enter quantity: ";
        cin >> quantity;

        cout << "Enter price: ";
        cin >> price;

        // Write inputs into CSV file
        outputFile << sku << "," << quantity << "," << price << endl;
    }

    outputFile.close(); // Close file
    cout << "Orders saved to orders.csv." << endl;

    return 0;
}
