// MenuItem.h

#ifndef MENUITEM_H
#define MENUITEM_H

#include <iostream>
#include <string>
using namespace std;

/*------------------------------------------------------------------------*
 *  MenuItem                                                              *
 *  Represents a single item on the menu with its details.                *
 *------------------------------------------------------------------------*/
class MenuItem {
public:
    /*------------------------------------------------------------------------*
     *  MenuItem                                                              *
     *  Default constructor. Initializes an empty MenuItem object.            *
     *------------------------------------------------------------------------*/
    MenuItem();

    /*------------------------------------------------------------------------*
     *  MenuItem                                                              *
     *  Parameterized constructor. Initializes a MenuItem object with the     *
     *  provided data.                                                        *
     *                                                                        *
     *  Precondition:  id, name, description, and price are valid values.     *
     *  Postcondition: The MenuItem object is created with the given data.    *
     *------------------------------------------------------------------------*/
    MenuItem(string &name, string &description, double price);

    /*------------------------------------------------------------------------*
     *  MenuItem                                                              *
     *  Copy constructor. Creates a new MenuItem object as a copy of          *
     *  another MenuItem object.                                              *
     *                                                                        *
     *  Precondition:  other is a valid MenuItem object.                      *
     *  Postcondition: A new MenuItem object is created with the same data    *
     *                 as others.                                              *
     *------------------------------------------------------------------------*/
    MenuItem(const MenuItem &menuitem);

    /*------------------------------------------------------------------------*
     *  display                                                               *
     *  Displays the details of the MenuItem.                                 *
     *                                                                        *
     *  Precondition:  The MenuItem object is initialized.                    *
     *  Postcondition: The details of the MenuItem are printed to the         *
     *                 console.                                               *
     *------------------------------------------------------------------------*/
    string display();

    // Getters for accessing the private attributes
    int getId() const;

    string getName() const;

    string getDescription() const;

    double getPrice() const;

private:
    static int nextId;
    int id;
    string name;
    string description;
    double price;

    void setMenuItem(const string &name, const string &description, double price);
};

#endif
