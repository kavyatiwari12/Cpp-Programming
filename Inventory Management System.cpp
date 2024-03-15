#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    string name;
    int quantity;
    double price;
};

class Inventory {
private:
    vector<Item> items;

public:
    void addItem(const string& name, int quantity, double price) {
        items.push_back({name, quantity, price});
        cout << "Item added to inventory.\n";
    }

    void removeItem(const string& name) {
        auto it = find_if(items.begin(), items.end(), [&name](const Item& item) {
            return item.name == name;
        });

        if (it != items.end()) {
            items.erase(it);
            cout << "Item removed from inventory.\n";
        } else {
            cout << "Item not found in inventory.\n";
        }
    }

    void displayInventory() const {
        if (items.empty()) {
            cout << "Inventory is empty.\n";
            return;
        }

        cout << "\n-------------------------------------\n";
        cout << setw(20) << left << "Item Name";
        cout << setw(10) << left << "Quantity";
        cout << setw(10) << left << "Price ($)";
        cout << "\n-------------------------------------\n";

        for (const auto& item : items) {
            cout << setw(20) << left << item.name;
            cout << setw(10) << left << item.quantity;
            cout << setw(10) << left << fixed << setprecision(2) << item.price;
            cout << endl;
        }
        cout << "-------------------------------------\n";
    }

    void searchItem(const string& name) const 
{
        auto it = find_if(items.begin(), items.end(), [&name](const Item& item) 
  {
            return item.name == name;
        });

        if (it != items.end()) {
            cout << "\n-------------------------------------\n";
            cout << setw(20) << left << "Item Name";
            cout << setw(10) << left << "Quantity";
            cout << setw(10) << left << "Price ($)";
            cout << "\n-------------------------------------\n";
            cout << setw(20) << left << it->name;
            cout << setw(10) << left << it->quantity;
            cout << setw(10) << left << fixed << setprecision(2) << it->price;
            cout << "\n-------------------------------------\n";
        } 
        else 
        {
            cout << "Item not found in inventory.\n";
        }
    }
};

int main() 
{
    Inventory inventory;

    char choice;
    do 
    {
        cout << "\n--------------------------\n";
        cout << "    Inventory System\n";
        cout << "--------------------------\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. Display Inventory\n";
        cout << "4. Search Item\n";
        cout << "5. Exit\n";
        cout << "--------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline character

        switch (choice) {
            case '1': {
                string name;
                int quantity;
                double price;
                cout << "Enter item name: ";
                getline(cin, name);
                cout << "Enter item quantity: ";
                cin >> quantity;
                cout << "Enter item price: ";
                cin >> price;
                inventory.addItem(name, quantity, price);
                break;
            }
            case '2': {
                string name;
                cout << "Enter item name to remove: ";
                getline(cin, name);
                inventory.removeItem(name);
                break;
            }
            case '3':
                inventory.displayInventory();
                break;
            case '4': {
                string name;
                cout << "Enter item name to search: ";
                getline(cin, name);
                inventory.searchItem(name);
                break;
            }
            case '5':
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } 
    while (choice != '5');

    return 0;
}
