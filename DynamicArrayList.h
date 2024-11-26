#ifndef DYNAMICARRAYLIST_H
#define DYNAMICARRAYLIST_H
#include "MenuItem.h"
#include "FileHandler.h"

#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

/*------------------------------------------------------------------------*
 *  DynamicArrayList                                                       *
 *  A dynamic array implementation that stores a collection of MenuItem   *
 *  objects and allows for operations like adding, removing, and displaying*
 *  menu items.                                                            *
 *------------------------------------------------------------------------*/
class DynamicArrayList {
public:
    /*------------------------------------------------------------------------*
     *  DynamicArrayList                                                       *
     *  Default constructor. Initializes an empty DynamicArrayList object     *
     *  with a default capacity.                                               *
     *------------------------------------------------------------------------*/
    DynamicArrayList();

    /*------------------------------------------------------------------------*
     *  DynamicArrayList                                                       *
     *  Parameterized constructor. Initializes a DynamicArrayList object with *
     *  the given capacity.                                                     *
     *                                                                        *
     *  Precondition: capacity is a positive integer.                          *
     *  Postcondition: A DynamicArrayList object is created with the given    *
     *                 capacity.                                               *
     *------------------------------------------------------------------------*/
    DynamicArrayList(int capacity);

    /*------------------------------------------------------------------------*
     *  ~DynamicArrayList                                                      *
     *  Destructor. Deallocates the memory used by the dynamic array of Menu  *
     *  items.                                                                *
     *------------------------------------------------------------------------*/
    ~DynamicArrayList();

    /*------------------------------------------------------------------------*
     *  add                                                                   *
     *  Adds a new MenuItem to the list.                                      *
     *                                                                        *
     *  Precondition: The MenuItem item is valid and the array has sufficient *
     *                capacity.                                                *
     *  Postcondition: The MenuItem is added to the list.                     *
     *------------------------------------------------------------------------*/
    void add(const MenuItem &item);

    /*------------------------------------------------------------------------*
     *  remove                                                                *
     *  Removes the MenuItem at the specified position in the list.           *
     *                                                                        *
     *  Precondition: pos is a valid index in the range [0, size-1].          *
     *  Postcondition: The MenuItem at the specified position is removed and  *
     *                 the remaining items are shifted.                       *
     *------------------------------------------------------------------------*/
    void remove(int pos);

    /*------------------------------------------------------------------------*
     *  getMenuItem                                                           *
     *  Returns the MenuItem at the specified position in the list.           *
     *                                                                        *
     *  Precondition: pos is a valid index in the range [0, size-1].          *
     *  Postcondition: Returns the MenuItem at the specified position.        *
     *------------------------------------------------------------------------*/
    MenuItem &getMenuItem(int pos) const;

    /*------------------------------------------------------------------------*
     *  getSize                                                               *
     *  Returns the current size (number of items) of the list.               *
     *                                                                        *
     *  Precondition: None.                                                   *
     *  Postcondition: Returns the number of MenuItems currently in the list. *
     *------------------------------------------------------------------------*/
    int getSize() const;

    /*------------------------------------------------------------------------*
     *  resize                                                                *
     *  Resizes the dynamic array to accommodate more items.                  *
     *                                                                        *
     *  Precondition: The list is full (size == capacity).                    *
     *  Postcondition: The array capacity is doubled, and existing items are *
     *                 copied to the new array.                               *
     *------------------------------------------------------------------------*/
    void resize();

    /*------------------------------------------------------------------------*
     *  display                                                               *
     *  Displays all MenuItems in the list to the console.                    *
     *                                                                        *
     *  Precondition: The list has been initialized and contains MenuItems.   *
     *  Postcondition: All MenuItems are printed to the console.              *
     *------------------------------------------------------------------------*/
    void display() const;

    /*------------------------------------------------------------------------*
     *  loadMenu                                                              *
     *  Loads menu items from a file into the list.                           *
     *                                                                        *
     *  Precondition: fileHandler has read the data from a valid file.        *
     *  Postcondition: MenuItems are parsed from the file and added to the    *
     *                 list.                                                  *
     *------------------------------------------------------------------------*/
    void loadMenu();

    /*------------------------------------------------------------------------*
     *  saveMenu                                                              *
     *  Saves all MenuItems in the list to a specified file.                  *
     *                                                                        *
     *  Precondition: The fileName is a valid file path.                      *
     *  Postcondition: The MenuItems are written to the specified file.       *
     *------------------------------------------------------------------------*/
    void saveMenu() const;

    /*------------------------------------------------------------------------*
     *  displayMenu                                                           *
     *  Displays the current menu in a formatted manner.                      *
     *                                                                        *
     *  Precondition: The menu list is not empty.                             *
     *  Postcondition: The menu is printed to the console.                    *
     *------------------------------------------------------------------------*/
    void displayMenu();

    /*------------------------------------------------------------------------*
     *  operator<<                                                            *
     *  Overloaded ostream operator to display the MenuItem object.           *
     *                                                                        *
     *  Precondition: The MenuItem object is initialized.                     *
     *  Postcondition: The MenuItem details are printed to the console.       *
     *------------------------------------------------------------------------*/
    ostream operator<<(const ostream &out, const MenuItem &menuitem);

    /*------------------------------------------------------------------------*
     *  addMenuItem                                                           *
     *  Prompts the user to enter details for a new MenuItem and adds it to   *
     *  the list.                                                             *
     *                                                                        *
     *  Precondition: User input is valid (non-empty name, description, and   *
     *                valid price).                                           *
     *  Postcondition: A new MenuItem is added to the menu.                   *
     *------------------------------------------------------------------------*/
    void addMenuItem();

    /*------------------------------------------------------------------------*
     *  deleteMenuItem                                                        *
     *  Deletes a MenuItem from the list based on the provided ID.            *
     *                                                                        *
     *  Precondition: The ID to delete exists in the list.                    *
     *  Postcondition: The MenuItem is removed from the list.                 *
     *------------------------------------------------------------------------*/
    void deleteMenuItem();

    /*------------------------------------------------------------------------*
     *  resetMenu                                                             *
     *  Resets the menu to an empty state.                                    *
     *                                                                        *
     *  Precondition: None.                                                   *
     *  Postcondition: The menu is cleared, and all items are removed.        *
     *------------------------------------------------------------------------*/
    void resetMenu();

    /*------------------------------------------------------------------------*
     *  clear                                                                 *
     *  Clears the menu by resetting its size to zero and optionally resets   *
     *  the MenuItem array.                                                   *
     *                                                                        *
     *  Precondition: None.                                                   *
     *  Postcondition: The list is emptied and ready for new items.           *
     *------------------------------------------------------------------------*/
    void clear();

private:
    MenuItem *menuItem; // Pointer to the dynamic array of MenuItems
    int size; // Number of items currently in the list
    int capacity; // Maximum capacity of the dynamic array
};

#endif
