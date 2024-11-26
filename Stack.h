#ifndef STACK_H
#define STACK_H

#include "Order.h" // Include Order.h before using ElementType

#include <iostream>
#include <sstream>
#include <fstream>

typedef Order ElementType; // type of elements stored in the stack

/*------------------------------------------------------------------------*
 *  Stack                                                                 *
 *  Represents a stack data structure that stores orders.                 *
 *------------------------------------------------------------------------*/
class Stack {
public:
    /*------------------------------------------------------------------------*
     *  Stack                                                                 *
     *  Default constructor. Initializes an empty Stack object.               *
     *------------------------------------------------------------------------*/
    Stack();

    /*------------------------------------------------------------------------*
     *  Stack                                                                 *
     *  Copy constructor. Creates a new Stack object as a copy of             *
     *  another Stack object.                                                 *
     *                                                                        *
     *  Precondition:  stack is a valid Stack object.                         *
     *  Postcondition: A new Stack object is created with the same data       *
     *                 as stack.                                              *
     *------------------------------------------------------------------------*/
    Stack(const Stack &stack);

    /*------------------------------------------------------------------------*
     *  ~Stack                                                                *
     *  Destructor. Deletes the Stack object.                                 *
     *------------------------------------------------------------------------*/
    ~Stack();

    /* ----------------------------------------------------------------------*
     *  isEmpty                                                              *
     *  Returns whether the stack is empty or not.                           *
     *                                                                       *
     * Precondition:  The stack is initialized.                              *
     * Postcondition: True is returned if the stack is empty, false if the   *
     *                stack is not empty.                                    *
     *-----------------------------------------------------------------------*/
    bool isEmpty() const;

    /*------------------------------------------------------------------------*
     *  push                                                                  *
     *  Adds an order to the stack.                                           *
     *                                                                        *
     *  Precondition:  order is a valid Order object.                         *
     *  Postcondition: order is added to the top of the stack.                *
     *------------------------------------------------------------------------*/
    void push(const ElementType &order);

    /*------------------------------------------------------------------------*
     *  pop                                                                   *
     *  Removes and returns the top order from the stack.                     *
     *                                                                        *
     *  Precondition:  The stack is not empty.                                *
     *  Postcondition: The top order is removed from the stack and returned.  *
     *------------------------------------------------------------------------*/
    ElementType pop();

    /*------------------------------------------------------------------------*
     *  getCurrentOrder                                                       *
     *  Returns the current order being processed.                            *
     *                                                                        *
     *  Precondition:  The stack is initialized.                              *
     *  Postcondition: The current order being processed is returned.         *
     *  Warning: Use try & catch when calling it in case of an Empty Stack.   *
     *------------------------------------------------------------------------*/
    ElementType getCurrentOrder() const;

    /*------------------------------------------------------------------------*
     *  getSize                                                               *
     *  Returns the number of orders in the stack.                            *
     *                                                                        *
     *  Precondition:  The stack is initialized.                              *
     *  Postcondition: The number of orders in the stack is returned.         *
     *  Warning: Use try & catch when calling it in case of an Empty Stack.   *
     *------------------------------------------------------------------------*/
    int getSize() const;

    /*------------------------------------------------------------------------*
     *  getTotalRevenue                                                       *
     *  Returns the total revenue from all completed orders.                  *
     *                                                                        *
     *  Precondition:  completedOrders is a valid Stack object.               *
     *  Postcondition: The total revenue for all completed orders is          *
     *                 returned.                                              *
     *------------------------------------------------------------------------*/
    double getTotalRevenue() const;


    /*------------------------------------------------------------------------*
     *  processNextOrder                                                      *
     *  Processes the next order in the queue.                                *
     *                                                                        *
     *  Precondition:  The queue is not empty.                                *
     *  Postcondition: The next order in the queue is processed.              *
     *------------------------------------------------------------------------*/
    // void processNextOrder(const Queue &orders);

    /*------------------------------------------------------------------------*
     *  saveCompletedOrders                                                   *
     *  Saves the completed orders to a file.                                 *
     *                                                                        *
     *  Precondition:  The stack is initialized.                              *
     *  Postcondition: The completed orders are saved to a file.              *
     *------------------------------------------------------------------------*/
    void saveCompletedOrders();

    /*------------------------------------------------------------------------*
     *  calculateTotalRevenue                                                 *
     *  Calculates the total revenue from all completed orders.               *
     *                                                                        *
     *  Precondition:  completedOrders is a valid Stack object.               *
     *  Postcondition: The total revenue for all completed orders is          *
     *                 calculated and returned.                               *
     *------------------------------------------------------------------------*/
    void calculateTotalRevenue();

    /*------------------------------------------------------------------------*
     *  loadTotalRevenue                                                      *
     *  Loads the total revenue from a file.                                  *
     *                                                                        *
     *  Precondition: fileHandler has read the data from a valid file.        *
     *  Postcondition: The total revenue is read from the file.               *
     *------------------------------------------------------------------------*/
    void loadTotalRevenue();

private:
    struct Node {
        ElementType data; // order stored in the node
        Node *next; // pointer to the next node in the stack

        Node(const ElementType &data, Node *next = nullptr) {
            this->data = data;
            this->next = next;
        }
    };

    typedef Node *NodePtr; // pointer to a Node object

    NodePtr currentOrder; // pointer to the current order being processed

    NodePtr back; // pointer to the last node in the stack

    double total; // total price of all completed orders

    /*------------------------------------------------------------------------*
     *  setStack                                                              *
     *  Sets the stack to the given order and back pointers.                  *
     *                                                                        *
     *  Precondition:  currentOrder and back are valid NodePtr objects.       *
     *  Postcondition: The stack is set to the given order and back pointers. *
     *------------------------------------------------------------------------*/
    void setStack(NodePtr currentOrder, NodePtr back);
};


#endif
