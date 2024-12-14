/*
Write a C++ program using STL for sorting and searching user-defined records
such as item records using vector container.
*/

#include <iostream>
#include <algorithm>  // For STL algorithms like sort, find, for_each
#include <vector>     // For STL vector container
#include <cstring>    // For handling C-style strings
using namespace std;

// Class to represent an Item
class Item {
public:
    char name[10];  // Item name
    int quantity;   // Item quantity
    int cost;       // Item cost
    int code;       // Unique item code

    // Operator overload to check equality based on item code
    bool operator==(const Item& i1) const {
        return code == i1.code;
    }

    // Operator overload to compare items based on item code (for sorting)
    bool operator<(const Item& i1) const {
        return code < i1.code;
    }
};

vector<Item> itemList;  // Vector to store Item objects

// Function declarations
void print(const Item& i1);
void display();
void insert();
void search();
void dlt();
bool compareByCost(const Item& i1, const Item& i2);

int main() {
    int choice;
    do {
        cout << "\n* * * * * Menu * * * * *";
        cout << "\n1. Insert";
        cout << "\n2. Display";
        cout << "\n3. Search";
        cout << "\n4. Sort by Code";
        cout << "\n5. Sort by Cost";
        cout << "\n6. Delete";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            insert();
            break;

        case 2:
            display();
            break;

        case 3:
            search();
            break;

        case 4:
            sort(itemList.begin(), itemList.end());  // Sorting the items by code
            cout << "\n\nSorted by Code:\n";
            display();
            break;

        case 5:
            sort(itemList.begin(), itemList.end(), compareByCost);  // Sorting the items by cost
            cout << "\n\nSorted by Cost:\n";
            display();
            break;

        case 6:
            dlt();
            break;

        case 7:
            exit(0);
            break;

        default:
            cout << "\nInvalid choice! Please try again.";
        }
    } while (choice != 7);

    return 0;
}

// Function to insert a new item into the vector
void insert() {
    Item newItem;
    cout << "\nEnter Item Name: ";
    cin.ignore();  // Ignore leftover newline
    cin.getline(newItem.name, 10);
    cout << "Enter Item Quantity: ";
    cin >> newItem.quantity;
    cout << "Enter Item Cost: ";
    cin >> newItem.cost;
    cout << "Enter Item Code: ";
    cin >> newItem.code;
    itemList.push_back(newItem);  // Add the item to the vector
    cout << "\nItem added successfully!\n";
}

// Function to display all items in the vector
void display() {
    if (itemList.empty()) {
        cout << "\nNo items to display.\n";
        return;
    }
    cout << "\nItems in the list:\n";
    for_each(itemList.begin(), itemList.end(), print);  // Use for_each to display all items
}

// Function to print details of a single item
void print(const Item& item) {
    cout << "\nItem Name: " << item.name;
    cout << "\nItem Quantity: " << item.quantity;
    cout << "\nItem Cost: " << item.cost;
    cout << "\nItem Code: " << item.code;
    cout << "\n";
}

// Function to search for an item based on its code
void search() {
    if (itemList.empty()) {
        cout << "\nNo items to search.\n";
        return;
    }

    int searchCode;
    cout << "\nEnter Item Code to search: ";
    cin >> searchCode;

    // Use find_if to search for the item based on its code
    auto it = find_if(itemList.begin(), itemList.end(), [searchCode](const Item& item) {
        return item.code == searchCode;
    });

    if (it != itemList.end()) {
        cout << "\nItem found:\n";
        print(*it);
    } else {
        cout << "\nItem not found!\n";
    }
}

// Function to delete an item based on its code
void dlt() {
    if (itemList.empty()) {
        cout << "\nNo items to delete.\n";
        return;
    }

    int deleteCode;
    cout << "\nEnter Item Code to delete: ";
    cin >> deleteCode;

    // Use find_if to locate the item to delete
    auto it = find_if(itemList.begin(), itemList.end(), [deleteCode](const Item& item) {
        return item.code == deleteCode;
    });

    if (it != itemList.end()) {
        itemList.erase(it);  // Remove the item from the vector
        cout << "\nItem deleted successfully!\n";
    } else {
        cout << "\nItem with the given code not found.\n";
    }
}

// Function to compare two items based on their cost (used for sorting)
bool compareByCost(const Item& i1, const Item& i2) {
    return i1.cost < i2.cost;
}
