#include "Order.h"


Order::Order() {
    setOrder("", nullptr);
}

Order::Order(const string &customerName, const MenuItem menuitems[]) {
    setOrder(customerName, menuitems);
}

Order::Order(const Order &order) {
    customerName = order.customerName;
    menuitems = order.menuitems;
}

string Order::toString() {
    string orderDetails = "Order ID: " + to_string(orderId) + ", ";
    orderDetails += "Customer Name: " + customerName + "\n";
    orderDetails += "Items:\n";
    for (int i = 0; i < menuitems.getSize(); i++) {
        orderDetails += "-" + menuitems.getMenuItem(i).getName() +
            " ($" + to_string(menuitems.getMenuItem(i).getPrice()) + ")\n";
    }
    orderDetails += "Total Amount: $" + to_string(totalAmount) + "\n";
    orderDetails += "Status: ";
    orderDetails += (status ? "Completed" : "Active");
    orderDetails += "\n";
    return orderDetails;
}

double Order::calculateTotalRevenue(const Stack& OcompletedOrders) {
    Stack completedOrders = OcompletedOrders;
    double totalRevenue = 0;
    int size = completedOrders.getSize();
    for (int i = 0; i < size; i++) {
        Order order = completedOrders.pop();
        totalRevenue += order.getTotalAmount();
    }
    return totalRevenue;
}

string Order::getCustomerName() const {
    return customerName;
}

DynamicArrayList Order::getMenuItems() const{
    return menuitems;
}

double Order::getTotalAmount() const {
    return totalAmount;
}

bool Order::isCompleted() const {
    return status;
}

void Order::setCompleted() {
    status = true;
    cout << "\033[1;31m"; // Set the text to the color red
    cout << "Order is set as completed!" << endl;
    cout << "\033[0m"; // Reset the text color
}

void Order::setOrder(const string &newCustomerName, const MenuItem menuitems[]) {
    orderId = time(0);
    customerName = newCustomerName;
    for (int i = 0; i < 10; i++) {
        this-> menuitems.add(menuitems[i]);
        totalAmount += menuitems[i].getPrice();
    }
    status = false;
    cout << "\033[1;31m"; // Set the text to the color red
    cout << "Order created successfully!" << endl;
    cout << "\033[0m"; // Reset the text color
}

