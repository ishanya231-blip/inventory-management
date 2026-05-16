
#include <iostream>
#include "InventoryManager.cpp"
using namespace std;

int main() {
    InventoryManager m;
    int ch;
    while (true) {
        cout << "\n1 Add\n2 View\n3 Update\n4 Delete\n5 List\n6 Exit\nChoice: ";
        cin >> ch;

        if (ch==1) m.addItem();
        else if (ch==2) m.viewItem();
        else if (ch==3) m.updateItem();
        else if (ch==4) m.deleteItem();
        else if (ch==5) m.listItems();
        else if (ch==6) break;
    }
    return 0;
}
