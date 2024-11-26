#include "Queue.h"

#include <assert.h>

Queue::Queue() {
    /*------------------------------------------------------------*
     *  Queue                                                     *
     *  Default constructor. Initializes an empty Queue object.   *
     *------------------------------------------------------------*/
    front = nullptr;
    back = nullptr;
}

Queue::~Queue() {
    /*------------------------------------------------------------*
     *  ~Queue                                                    *
     *  Destructor. Deallocates the memory used by the queue.     *
     *------------------------------------------------------------*/
    clear();
}

void Queue::enqueue(int value) {
    /*------------------------------------------------------------*
     *  enqueue                                                   *
     *  Adds an order to the back of the queue.                   *
     *                                                            *
     *  Precondition:  value is a valid Order object.             *
     *  Postcondition: value is added to the back of the queue.   *
     *------------------------------------------------------------*/
    NodePtr newNode = new Node(value);
    if (isEmpty()) {
        front = newNode;
        back = newNode;
    } else {
        back->next = newNode;
        back = newNode;
    }
}

ElementType Queue::dequeue() {
    /*------------------------------------------------------------*
     *  dequeue                                                   *
     *  Removes and returns the front order from the queue.       *
     *                                                            *
     *  Precondition:  The queue is not empty.                    *
     *  Postcondition: The front order is removed from the queue  *
     *                 and returned.                              *
     *------------------------------------------------------------*/
    assert(!isEmpty());
    NodePtr temp = front;
    ElementType data = temp->data;
    front = front->next;
    delete temp;
    return data;
}

ElementType Queue::peek() {
    /*------------------------------------------------------------*
     *  peek                                                      *
     *  Returns the front order in the queue without removing it. *
     *                                                            *
     *  Precondition:  The queue is not empty.                    *
     *  Postcondition: The front order is returned without        *
     *                 removing it.                               *
     *------------------------------------------------------------*/
    if (isEmpty()) {
        cerr << "Error: Queue is empty.\n";
        return -1;
    }
    return front->data;
}

bool Queue::isEmpty() {
    /*------------------------------------------------------------*
     *  isEmpty                                                   *
     *  Returns whether the queue is empty or not.                *
     *                                                            *
     *  Precondition:  The queue is initialized.                  *
     *  Postcondition: True is returned if the queue is empty,    *
     *                 false if the queue is not empty.           *
     *------------------------------------------------------------*/
    return front == nullptr;
}

void Queue::clear() {
    /*------------------------------------------------------------*
     *  clear                                                     *
     *  Clears the queue by removing all orders.                  *
     *                                                            *
     *  Precondition: None.                                       *
     *  Postcondition: The queue is emptied and ready for new     *
     *                 orders.                                    *
     *------------------------------------------------------------*/
    while (!isEmpty()) {
        dequeue();
    }
}

void Queue::print() {
    /*------------------------------------------------------------*
     *  print                                                     *
     *  Prints the orders in the queue.                           *
     *                                                            *
     *  Precondition: None.                                       *
     *  Postcondition: The orders in the queue are printed to the *
     *                 console.                                   *
     *------------------------------------------------------------*/
    NodePtr current = front;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int Queue::size() {
    /*------------------------------------------------------------*
     *  size                                                      *
     *  Returns the current size (number of orders) in the queue. *
     *                                                            *
     *  Precondition: None.                                       *
     *  Postcondition: Returns the number of orders currently in  *
     *                 the queue.                                 *
     *------------------------------------------------------------*/
    int count = 0;
    NodePtr current = front;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}