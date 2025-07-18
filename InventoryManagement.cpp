#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void addItem() {
    string itemName;
    int itemCode;
    int quantity;
    float price;

    cout << "Enter Item Name: ";
    cin.ignore();
    getline(cin, itemName);
    
    while (true) {
        cout << "Enter Item Code: ";
        cin >> itemCode;
        if (itemCode < 0) {
            cout << "Item code cannot be negative" << endl;
        } else {
            break;
        }
    }

    cout << "Enter Quantity: ";
    cin >> quantity;
    cout << "Enter Price: ";
    cin >> price;

    ofstream file("Inventory.txt", ios::app);
    if (file.is_open()) {
        file << itemName << "," << itemCode << "," << quantity << "," << price << endl;
        file.close();
        cout << "Item added successfully" << endl;
    } else {
        cout << "Error opening file" << endl;
    }
}

void displayItems() {
    string line;
    ifstream file("Inventory.txt");
    if (file.is_open()) {
        cout << "Inventory Items: " << endl;
        cout << "\tName\t\tCode\tQuantity\tPrice" << endl;
        cout << "---------------------------------------------" << endl;
        int count = 1;
        while (getline(file, line)) {
            string name;
            int code, quantity;
            float price;

            size_t pos1 = line.find(",");
            size_t pos2 = line.find(",", pos1 + 1);
            size_t pos3 = line.find(",", pos2 + 1);
            name = line.substr(0, pos1);
            code = stoi(line.substr(pos1 + 1, pos2));
            quantity = stoi(line.substr(pos2 + 1, pos3));
            price = stof(line.substr(pos3 + 1));

            cout << count << ". " << name << "\t\t" << code << "\t" << quantity << "\t\t" << price << endl;
            count++;
        }
        file.close();
    } else {
        cout << "Error opening file" << endl;
    }
}

int main() {
    int choice;

    while (1) {
        cout << "Inventory Management System" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. Display Items" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                displayItems();
                break;
            case 3:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}
