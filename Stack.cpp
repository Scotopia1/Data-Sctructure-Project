#include "Stack.h"
#include "FileHandler.h"


Stack::Stack() {
    setStack(nullptr, nullptr);
}

Stack::Stack(const Stack& other) {
    currentOrder = nullptr; // Initialize the new stack's top to nullptr
    if (other.currentOrder != nullptr) {
        NodePtr current = other.currentOrder;
        NodePtr temp = new Node(current->data); // Create the first node
        currentOrder = temp;
        current = current->next;
        while (current != nullptr) {
            temp->next = new Node(current->data); // Create subsequent nodes
            temp = temp->next;
            current = current->next;
        }
        back = temp; // Set the back pointer to the last node
    }
}

Stack::~Stack() {
    while ( currentOrder != nullptr ) {
        NodePtr temp = currentOrder;
        currentOrder = currentOrder->next;
        delete temp;
    }
}

void Stack::push(const ElementType &order) {
    if ( currentOrder == nullptr ) {
        currentOrder = new Node(order);
        back = currentOrder;
    } else {
        back->next = new Node(order);
        back = back->next;
        total += order.getTotalAmount();
    }
}

ElementType Stack::pop() {
    if (currentOrder == nullptr ) {
        throw "Stack is empty!";
    }
    ElementType order = currentOrder->data;
    NodePtr temp = currentOrder;
    currentOrder = currentOrder->next;
    delete temp;
    return order;
}

ElementType Stack::getCurrentOrder() const {
    if ( currentOrder == nullptr ) {
        throw runtime_error("Stack is empty!");
    }
    return currentOrder->data;
}

int Stack::getSize() const {
    if ( currentOrder == nullptr ) {
        return 0;
    }
    int size = 1;
    NodePtr temp = currentOrder;
    while ( temp -> next != nullptr ) {
        size++;
        temp = temp->next;
    }
    return size;
}

double Stack::getTotalRevenue() const {
    return total;
}

void Stack::saveCompletedOrders() {
    FileHandler fileHandler("completed_orders.txt"); // Create a FileHandler object

    // Read the file content into the lines array
    fileHandler.read();

    // Modify the total revenue line in memory
    string totalRevenueLine = fileHandler.getLines()[0];
    totalRevenueLine = "Total Revenue = " + to_string(total);
    fileHandler.getLines()[0] = totalRevenueLine;

    // Write the modified lines array back to the file
    ofstream outFile("completed_orders.txt", ios::trunc);
    if (outFile.is_open()) {
        for (int i = 0; i < fileHandler.getSize(); i++) {
            outFile << fileHandler.getLines()[i] << "\n";
        }
        outFile.close();
    } else {
        cerr << "Unable to open file for writing.\n";
    }
    // Append the completed orders to the file
    NodePtr current = currentOrder;
    while (current != nullptr) {
        try {
            ElementType data = pop(); // Get the next completed order
            fileHandler.append(data.toString()); // Append the order to the file
        } catch (const char* message) {
            cerr << "Error: " << message << endl;
        }
        current = currentOrder; // Move to the next order
    }
}

void Stack::setStack(NodePtr currentOrder, NodePtr back) {
    // Set the current order and back pointers
    this->currentOrder = currentOrder;
    this->back = back;
}

void Stack::calculateTotalRevenue() {
    /*------------------------------------------------------------------------*
     *  calculateTotalRevenue                                                 *
     *  Calculates the total revenue from all completed orders.               *
     *                                                                        *
     *  Precondition:                                                         *
     *  Postcondition: The total revenue for all completed orders is          *
     *                 calculated and returned.                               *
     *------------------------------------------------------------------------*/
    Stack completedOrdersCopy = *this ; // Create a copy of the stack
    FileHandler fileHandler("completed_orders.txt"); // Create a FileHandler object
    completedOrdersCopy.loadTotalRevenue(); // Load the total revenue from the file
    double totalRevenue = completedOrdersCopy.getTotalRevenue();// Calculate the total revenue
    int size = completedOrdersCopy.getSize(); // Get the number of orders

    // Calculate the total revenue
    for (int i = 0; i < size; i++) {
        ElementType order = completedOrdersCopy.pop();
        totalRevenue += order.getTotalAmount();
    }
    total = totalRevenue; // Set the total revenue
}

void Stack::loadTotalRevenue() {
    /*------------------------------------------------------------------------*
     *  loadTotalRevenue                                                      *
     *  Loads the total revenue from a file.                                  *
     *                                                                        *
     *  Precondition:                                                         *
     *  Postcondition: The total revenue is read from the file.               *
     *------------------------------------------------------------------------*/
    FileHandler fileHandler("completed_orders.txt"); // Create a FileHandler object

    // Read the file content into the lines array
    if (fileHandler.getLines() == nullptr || fileHandler.getSize() == 0) {
        cerr << "No data to load. Ensure the file has been read first.\n";
        return;
    }

    // Parse the total revenue from the first line
    string note;
    double TotalRevenue;
    string line = fileHandler.getLines()[0];
    stringstream ss(line);
    getline(ss ,note , '=');
    ss >> TotalRevenue;

    total = TotalRevenue;// Set the total revenue
}