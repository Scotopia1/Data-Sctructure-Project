#include "MenuItem.h"
#include <iostream>
#include <ostream>
using namespace std;

// Static variable for generating unique IDs for each menu item
int MenuItem::nextId = 1;

/*------------------------------------------------------------------------*
 *  MenuItem                                                              *
 *  A class that represents a menu item, including its ID, name,          *
 *  description, and price. The ID is automatically incremented.          *
 *------------------------------------------------------------------------*/

 // Default constructor
 // Initializes a MenuItem object with default values for name, description,
 // and price, calling the `setMenuItem` method to set those values.
MenuItem::MenuItem() {
    setMenuItem("", "", 0.0);  // Default values
}

// Parameterized constructor
// Initializes a MenuItem object with the provided name, description,
// and price by calling the `setMenuItem` method.
MenuItem::MenuItem(string& name, string& description, double price) {
    setMenuItem(name, description, price);
}

// Copy constructor
// Creates a copy of the given MenuItem by copying its attributes: id, name, 
// description, and price.
MenuItem::MenuItem(const MenuItem& menuitem) {
    id = menuitem.id;            // Copy the ID
    name = menuitem.name;        // Copy the name
    description = menuitem.description; // Copy the description
    price = menuitem.price;      // Copy the price
}

// Overloaded output stream operator
// Outputs the details of a MenuItem in a formatted way. This operator
// is used to print the menu item in a human-readable form.
ostream& operator<<(ostream& os, const MenuItem& item) {
    os << "Id: " << item.getId() << "\n"          // Print the ID
        << "Name: " << item.getName() << "\n"      // Print the name
        << "Description: " << item.getDescription() << "\n" // Print the description
        << "Price: $" << item.getPrice() << "\n";  // Print the price
    return os;  // Return the stream to allow chaining
}

// Getter for the ID
// Returns the ID of the menu item.
int MenuItem::getId() const {
    return id;
}

// Getter for the name
// Returns the name of the menu item.
string MenuItem::getName() const {
    return name;
}

// Getter for the description
// Returns the description of the menu item.
string MenuItem::getDescription() const {
    return description;
}

// Getter for the price
// Returns the price of the menu item.
double MenuItem::getPrice() const {
    return price;
}

// Setter method to set menu item properties
// Sets the menu item's ID (using a static nextId counter), name, description, 
// and price. After setting, it outputs a success message in red.
void MenuItem::setMenuItem(const string& newName, const string& newDescription, double newPrice) {
    id = nextId;         // Assign the current ID and increment nextId for the next item
    nextId++;            // Increment the static nextId for uniqueness
    name = newName;      // Set the name
    description = newDescription; // Set the description
    price = newPrice;    // Set the price

    // Print a success message in red
    cout << "\033[1;31m";   // Set the text to red
    cout << "Menu item created successfully!" << endl; // Success message
    cout << "\033[0m";       // Reset the text color to default
}
