#ifndef QUEUE_H
#define QUEUE_H

#include "Order.h" // Include Order.h before using ElementType
#include "Stack.h"


#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

/*------------------------------------------------------------------------*
 * Queue                                                                  *
 * Represents a queue data structure that stores orders.                  *
 *------------------------------------------------------------------------*/
class Queue {
public:
    /*------------------------------------------------------------------------*
     *  Queue                                                                 *
     *  Default constructor. Initializes an empty Queue object.               *
     *------------------------------------------------------------------------*/
    Queue();

    /*------------------------------------------------------------------------*
     *  ~Queue                                                                *
     *  Destructor. Deallocates the memory used by the queue.                 *
     *------------------------------------------------------------------------*/
    ~Queue();

    /*------------------------------------------------------------------------*
     *  enqueue                                                               *
     *  Adds an order to the back of the queue.                               *
     *                                                                        *
     *  Precondition:  value is a valid Order object.                         *
     *  Postcondition: value is added to the back of the queue.               *
     *------------------------------------------------------------------------*/
    void enqueue(ElementType value);

    /*------------------------------------------------------------------------*
     *  dequeue                                                               *
     *  Removes and returns the front order from the queue.                   *
     *                                                                        *
     *  Precondition:  The queue is not empty.                                *
     *  Postcondition: The front order is removed from the queue and          *
     *                 returned.                                              *
     *------------------------------------------------------------------------*/
    ElementType dequeue();

    /*------------------------------------------------------------------------*
     *  peek                                                                  *
     *  Returns the front order in the queue without removing it.             *
     *                                                                        *
     *  Precondition:  The queue is not empty.                                *
     *  Postcondition: The front order is returned without removing it.       *
     *------------------------------------------------------------------------*/
    ElementType peek();

    /*------------------------------------------------------------------------*
     *  isEmpty                                                               *
     *  Returns whether the queue is empty or not.                            *
     *                                                                        *
     *  Precondition:  The queue is initialized.                              *
     *  Postcondition: True is returned if the queue is empty, false if the   *
     *                 queue is not empty.                                    *
     *------------------------------------------------------------------------*/
    bool isEmpty();

    /*------------------------------------------------------------------------*
     *  size                                                                  *
     *  Returns the current size (number of orders) in the queue.             *
     *                                                                        *
     *  Precondition: None.                                                   *
     *  Postcondition: Returns the number of orders currently in the queue.   *
     *------------------------------------------------------------------------*/
    int size();

    /*------------------------------------------------------------------------*
     *  print                                                                 *
     *  Prints the orders in the queue.                                       *
     *                                                                        *
     *  Precondition: None.                                                   *
     *  Postcondition: The orders in the queue are printed to the console.    *
     *------------------------------------------------------------------------*/
    void print();

    /*------------------------------------------------------------------------*
     *  clear                                                                 *
     *  Clears the queue by removing all orders.                              *
     *                                                                        *
     *  Precondition: None.                                                   *
     *  Postcondition: The queue is emptied and ready for new orders.         *
     *------------------------------------------------------------------------*/
    void clear();

    /*------------------------------------------------------------------------*
     *  processNextOrder                                                      *
     *  Processes the next order in the queue.                                *
     *                                                                        *
     *  Precondition:  The queue is not empty.                                *
     *  Postcondition: The next order in the queue is processed.              *
     *------------------------------------------------------------------------*/
    void processNextOrder(Stack* stack);

private:
    struct Node {
        ElementType data; // Data stored in the node

        Node *next; // Pointer to the next node in the queue

        /*------------------------------------------------------------*
         *  Node                                                      *
         *  Parameterized constructor. Initializes a Node object with *
         *  the provided data.                                        *
         *                                                            *
         *  Precondition:  data is a valid ElementType.               *
         *  Postcondition: A new Node object is created with the data *
         *                 and next pointer set.                      *
         *------------------------------------------------------------*/
        Node(ElementType data) : data(data), next(nullptr){
        }
    };

    typedef Node *NodePtr; // Pointer to a Node

    NodePtr front; // Pointer to the front of the queue
    NodePtr back; // Pointer to the back of the queue
};


#endif //QUEUE_H
