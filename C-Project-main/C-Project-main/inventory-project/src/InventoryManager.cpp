
#include <iostream>
#include <vector>
#include <algorithm>
extern "C" {
    #include "../include/inventory.h"
}

using namespace std;

class InventoryManager {
public:
    void addItem() {
        Item item;
        cout << "Enter ID: ";
        cin >> item.id;
        cout << "Enter Name: ";
        cin >> item.name;
        cout << "Enter Quantity: ";
        cin >> item.quantity;
        cout << "Enter Price: ";
        cin >> item.price;
        item.is_deleted = 0;

        if (add_item(item)) cout << "Added!\n";
        else cout << "Error or duplicate ID\n";
    }

    void viewItem() {
        int id;
        cout << "Enter ID: ";
        cin >> id;
        Item item;
        if (get_item(id, &item)) {
            cout << item.id << " " << item.name << " " << item.quantity << " " << item.price << endl;
        } else cout << "Not found\n";
    }

    void updateItem() {
        int id;
        cout << "Enter ID: ";
        cin >> id;

        Item item;
        item.id = id;
        cout << "New Name: ";
        cin >> item.name;
        cout << "New Quantity: ";
        cin >> item.quantity;
        cout << "New Price: ";
        cin >> item.price;
        item.is_deleted = 0;

        if (update_item(id, item)) cout << "Updated\n";
        else cout << "Failed\n";
    }

    void deleteItem() {
        int id;
        cout << "Enter ID: ";
        cin >> id;
        if (delete_item(id)) cout << "Deleted\n";
        else cout << "Failed\n";
    }

    void listItems() {
        vector<Item> items(100);
        int count = list_items(items.data(), 100);

        sort(items.begin(), items.begin() + count, [](Item a, Item b) {
            return a.id < b.id;
        });

        for (int i = 0; i < count; i++) {
            cout << items[i].id << " | " << items[i].name << " | " << items[i].quantity << " | " << items[i].price << endl;
        }
    }
};
