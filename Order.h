#ifndef ORDER_H
#define ORDER_H

#include "MenuItem.h"
#include "Stack.h"
#include "DynamicArrayList.h"

#include <iostream>
#include <string>
#include <ctime>


using namespace std;

/*------------------------------------------------------------------------*
 *  Order                                                                 *
 *  Represents a customer's order with a list of menu items.              *
 *------------------------------------------------------------------------*/
class Order {
public:
    /*------------------------------------------------------------------------*
     *  Order                                                                 *
     *  Default constructor. Initializes an empty Order object.               *
     *------------------------------------------------------------------------*/
    Order();

    /*------------------------------------------------------------------------*
     *  Order                                                                 *
     *  Parameterized constructor. Initializes an Order object with the       *
     *  provided data.                                                        *
     *                                                                        *
     *  Precondition:  id, customerName, and items are valid values.          *
     *  Postcondition: The Order object is created with the given data.       *
     *------------------------------------------------------------------------*/
    Order(const string &customerName, const MenuItem menuitems[]);

    /*------------------------------------------------------------------------*
     *  Order                                                                 *
     * Copy constructor. Creates a new Order object as a copy of              *
     * another Order object.                                                  *
     *                                                                        *
     * Precondition:  order is a valid Order object.                          *
     * Postcondition: A new Order object is created with the same data        *
     * as order.                                                              *
     * -----------------------------------------------------------------------*/
    Order(const Order &order);

    /*------------------------------------------------------------------------*
     *  display                                                               *
     *  Displays the details of the order.                                    *
     *                                                                        *
     *  Precondition:  The Order object is initialized.                       *
     *  Postcondition: The details of the order are printed to the console.   *
     *------------------------------------------------------------------------*/
    string toString();

    /*------------------------------------------------------------------------*
     *  calculateTotalRevenue                                                 *
     *  Calculates the total revenue from all completed orders.               *
     *                                                                        *
     *  Precondition:  completedOrders is a valid Stack object.               *
     *  Postcondition: The total revenue for all completed orders is          *
     *                 calculated and returned.                               *
     *------------------------------------------------------------------------*/
    static double calculateTotalRevenue(const Stack &completedOrders);

    /*------------------------------------------------------------------------*
     *  getCustomerName                                                       *
     *  Returns the name of the customer who placed the order.                *
     *                                                                        *
     *  Precondition:  The Order object is initialized.                       *
     *  Postcondition: The name of the customer who placed the order is       *
     *                 returned.                                              *
     *------------------------------------------------------------------------*/
    string getCustomerName() const;

    /*------------------------------------------------------------------------*
     *  getMenuItems                                                          *
     *  Returns the list of menu items in the order.                          *
     *                                                                        *
     *  Precondition:  The Order object is initialized.                       *
     *  Postcondition: The list of menu items in the order is returned.       *
     *------------------------------------------------------------------------*/
    DynamicArrayList getMenuItems() const;

    /*------------------------------------------------------------------------*
     *  getTotalAmount                                                        *
     *  Returns the total amount of the order.                                *
     *                                                                        *
     *  Precondition:  The Order object is initialized.                       *
     *  Postcondition: The total amount of the order is returned.             *
     *------------------------------------------------------------------------*/
    double getTotalAmount() const;

    /*------------------------------------------------------------------------*
     *  isCompleted                                                           *
     *  Returns whether the order is completed or not.                        *
     *                                                                        *
     *  Precondition:  The Order object is initialized.                       *
     *  Postcondition: True is returned if the order is completed, false      *
     *                 if the order is still active.                          *
     *------------------------------------------------------------------------*/
    bool isCompleted() const;

    /*------------------------------------------------------------------------*
     *  setCompleted                                                          *
     *  Sets the order as completed.                                          *
     *                                                                        *
     *  Precondition:  The Order object is initialized.                       *
     *  Postcondition: The order is set as completed.                         *
     *------------------------------------------------------------------------*/
    void setCompleted();

private:
    int orderId; // Unique identifier for the order

    string customerName; // Name of the customer who placed the order

    DynamicArrayList menuitems; // List of menu items in the order

    double totalAmount; // Total amount of the order

    bool status; // Status of the order (completed or not)

    /*------------------------------------------------------------------------*
     *  setOrder                                                              *
     *  Initializes the order with the provided data.                         *
     *                                                                        *
     *  Precondition:  customerName and menuitems are valid values.           *
     *  Postcondition: The Order object is created with the given data.       *
     *------------------------------------------------------------------------*/
    void setOrder(const string &customerName, const MenuItem menuitems[]);
};

#endif
