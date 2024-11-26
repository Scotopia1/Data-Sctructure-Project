#include <iostream>

#include "DynamicArrayList.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main() {
    DynamicArrayList menu = DynamicArrayList();
    cout << "Loading menu items from file...\n";
    menu.loadMenu();
    cout << "Menu items loaded successfully!\n";
    Stack completedOrders = Stack();
    cout << "Loading completed orders from file...\n";
    completedOrders.loadTotalRevenue();
    cout << "Completed orders loaded successfully!\n";
    Queue activeorders = Queue();
    cout << "Loading active orders from file...\n";

    cout << "--- Restaurant Order Management System ---" << endl;

    while (true) {
        cout << "1. Display Menu" << endl;
        cout << "2. Add Menu Item" << endl;
        cout << "3. Delete Menu Item" << endl;
        cout << "4. Reset Menu" << endl;
        cout << "5. Add New Order" << endl;
        cout << "6. Process Next Order" << endl;
        cout << "7. Display Orders" << endl;
        cout << "8. Delete Order" << endl;
        cout << "9. Calculate Total Amount of Sold Orders" << endl;
        cout << "10. Save Completed Orders to File" << endl;
        cout << "11. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;


        switch (choice) {
            case 1:
                menu.display();
                break;
            case 2:
                menu.addMenuItem();
                break;
            case 3:
                menu.deleteMenuItem();
                break;
            case 4:
                menu.resetMenu();
                break;
            case 5:
                break;
            case 6:
                activeorders.processNextOrder(&completedOrders);
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                completedOrders.calculateTotalRevenue();
                break;
            case 10:
                completedOrders.saveCompletedOrders();
                break;
            case 11:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}