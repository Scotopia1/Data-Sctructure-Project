#include "DynamicArrayList.h"
#include "MenuItem.h"
#include "FileHandler.h"

using namespace std;

/*------------------------------------------------------------------------*
 *  DynamicArrayList                                                      *
 *  Represents a dynamic array list for storing MenuItem objects.          *
 *  It provides methods for adding, removing, resizing, and displaying     *
 *  the items.                                                             *
 *------------------------------------------------------------------------*/
DynamicArrayList::DynamicArrayList() {
    /*------------------------------------------------------------------------*
     *  DynamicArrayList                                                      *
     *  Default constructor. Initializes an empty DynamicArrayList object     *
     *  with a default capacity of 100.                                       *
     *------------------------------------------------------------------------*/
    capacity = 100;
    menuItem = new MenuItem[capacity];
}

DynamicArrayList::DynamicArrayList(int capacity) {
    /*------------------------------------------------------------------------*
     *  DynamicArrayList                                                      *
     *  Parameterized constructor. Initializes the DynamicArrayList object    *
     *  with a specified capacity.                                            *
     *                                                                        *
     *  Precondition:  capacity is a valid positive integer.                  *
     *  Postcondition: A DynamicArrayList object with the given capacity is   *
     *                 created.                                                *
     *------------------------------------------------------------------------*/
    this->capacity = capacity;
    menuItem = new MenuItem[capacity];
}

DynamicArrayList::~DynamicArrayList() {
    /*------------------------------------------------------------------------*
     *  ~DynamicArrayList                                                     *
     *  Destructor. Deallocates memory used by the menuItem array.            *
     *------------------------------------------------------------------------*/
    delete[] menuItem;
}

void DynamicArrayList::add(const MenuItem &item) {
    /*------------------------------------------------------------------------*
     *  add                                                                  *
     *  Adds a new MenuItem object to the list. If the list is full, it      *
     *  resizes the array.                                                    *
     *                                                                        *
     *  Precondition:  item is a valid MenuItem object.                       *
     *  Postcondition: The MenuItem is added to the list, and the size is     *
     *                 updated.                                               *
     *------------------------------------------------------------------------*/
    if (size >= capacity)
        resize();
    menuItem[size] = item;
    size++;
}

void DynamicArrayList::remove(int pos) {
    /*------------------------------------------------------------------------*
     *  remove                                                               *
     *  Removes a MenuItem from the list at the specified position.           *
     *  If the position is invalid, an error message is displayed.            *
     *                                                                        *
     *  Precondition:  pos is a valid index within the range of the list.     *
     *  Postcondition: The item at the specified position is removed, and     *
     *                 the size is updated.                                   *
     *------------------------------------------------------------------------*/
    if (pos < 0 || pos >= size)
        cout << "Index not found.\n";

    if (size - 1 == pos) {
        size--;
    } else {
        for (int i = pos; i < size - 1; i++)
            menuItem[i] = menuItem[i + 1];
        size--;
    }
}

MenuItem &DynamicArrayList::getMenuItem(int pos) const {
    /*------------------------------------------------------------------------*
     *  getMenuItem                                                          *
     *  Returns the MenuItem at the specified position.                       *
     *                                                                        *
     *  Precondition:  pos is a valid index within the range of the list.     *
     *  Postcondition: The MenuItem at the specified position is returned.    *
     *------------------------------------------------------------------------*/
    return menuItem[pos];
}

int DynamicArrayList::getSize() const {
    /*------------------------------------------------------------------------*
     *  getSize                                                              *
     *  Returns the current size (number of items) in the list.               *
     *                                                                        *
     *  Precondition:  The list has been initialized.                         *
     *  Postcondition: The size of the list is returned.                      *
     *------------------------------------------------------------------------*/
    return size;
}

void DynamicArrayList::resize() {
    /*------------------------------------------------------------------------*
     *  resize                                                                *
     *  Doubles the capacity of the list and reallocates memory to store      *
     *  more MenuItem objects.                                                *
     *                                                                        *
     *  Precondition:  The list has reached its capacity.                     *
     *  Postcondition: The array is resized, and the existing items are       *
     *                 copied into the new array.                             *
     *------------------------------------------------------------------------*/
    MenuItem *newMenuItem = new MenuItem[capacity * 2];
    for (int i = 0; i < size; i++)
        newMenuItem[i] = menuItem[i];

    delete[] menuItem; // Deallocate old array
    menuItem = newMenuItem; // Assign new resized array
    capacity *= 2;
}

void DynamicArrayList::display() const {
    /*------------------------------------------------------------------------*
     *  display                                                               *
     *  Displays all the MenuItems in the list.                               *
     *                                                                        *
     *  Precondition:  The list contains MenuItem objects.                    *
     *  Postcondition: Each MenuItem is printed to the console.               *
     *------------------------------------------------------------------------*/
    for (int i = 0; i < size; i++) {
        if (menuItem[i].getPrice() == 0.00000000) {
            continue;
        }
        cout << menuItem[i].display() << endl;
    }
}


void DynamicArrayList::loadMenu() {
    /*------------------------------------------------------------------------*
     *  loadMenu                                                             *
     *  Loads the menu items from a file using the provided FileHandler       *
     *  object. The file must have valid data in the correct format.          *
     *                                                                        *
     *  Precondition:  fileHandler has a valid file with menu item data.      *
     *  Postcondition: The menu items are read from the file and added to the *
     *                 list.                                                  *
     *------------------------------------------------------------------------*/
    string fileName = "menu.txt";
    FileHandler fileHandler(fileName);

    if (fileHandler.getLines() == nullptr || fileHandler.getSize() == 0) {
        cerr << "No data to load. Ensure the file has been read first.\n";
        return;
    } else {
        for (int i = 0; i < fileHandler.getSize(); i++) {
            string line = fileHandler.getLines()[i];
            stringstream ss(line);
            string id, name, description;
            double price;

            // Check if the line is empty
            if (line.empty()) {
                continue; // Skip to the next line
            }

            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, description, ',');
            ss >> price;

            if (!ss.fail() || !id.empty() || !name.empty() || !description.empty() || price != 0.0000) {
                cerr << "Error parsing line: " << line << endl;
                continue;


                MenuItem menuItem = MenuItem(name, description, price);

                cout << "\033[1;32m";
                cout << "Created MenuItem: " << menuItem.getId() << " " << menuItem.getName() << " "
                        << menuItem.getDescription() << " " << menuItem.getPrice() << endl;
                cout << "\033[0m";
                add(menuItem);
            }
        }
    }
}

void DynamicArrayList::saveMenu() const {
    /*------------------------------------------------------------------------*
     *  saveMenu                                                             *
     *  Saves the current menu items to a file using the provided file name.  *
     *                                                                        *
     *  Precondition:  The menu has items, and fileName is a valid file path. *
     *  Postcondition: The menu items are written to the file in CSV format.  *
     *------------------------------------------------------------------------*/
    string fileName = "menu.txt";

    FileHandler fileHandler(fileName);
    ostringstream content;

    for (int i = 0; i < size; i++) {
        const MenuItem &item = menuItem[i];
        content << item.getId() << ","
                << item.getName() << ","
                << item.getDescription() << ","
                << item.getPrice() << "\n";
    }

    fileHandler.write(content.str());
}

void DynamicArrayList::displayMenu() {
    /*------------------------------------------------------------------------*
     *  displayMenu                                                           *
     *  Displays all menu items with their details.                           *
     *                                                                        *
     *  Precondition:  menu is a valid DynamicArrayList object with items.    *
     *  Postcondition: The details of each menu item are displayed.           *
     *------------------------------------------------------------------------*/
    if (this->size == 0) {
        cout << "The menu is empty!" << endl;
        return;
    }

    cout << "Menu Items:\n";
    cout << "--------------------------------------\n";

    for (int i = 0; i < size; i++) {
        const MenuItem &item = getMenuItem(i);
        cout << "ID: " << item.getId() << "\n"
                << "Name: " << item.getName() << "\n"
                << "Description: " << item.getDescription() << "\n"
                << "Price: $" << item.getPrice() << "\n";
        cout << "--------------------------------------\n";
    }
}

void DynamicArrayList::addMenuItem() {
    /*------------------------------------------------------------------------*
     *  addMenuItem                                                           *
     *  Adds a new menu item to the list after prompting the user for input.  *
     *                                                                        *
     *  Precondition:  The menu is a valid DynamicArrayList object.           *
     *  Postcondition: A new MenuItem is added to the menu.                   *
     *------------------------------------------------------------------------*/
    string name, description;
    double price;

    cout << "Enter the name of the menu item: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter the description of the menu item: ";
    getline(cin, description);

    cout << "Enter the price of the menu item: ";
    cin >> price;

    MenuItem newItem = MenuItem(name, description, price);
    add(newItem);

    cout << "Menu item added successfully!" << endl;
    saveMenu();
}

void DynamicArrayList::deleteMenuItem() {
    /*------------------------------------------------------------------------*
     *  deleteMenuItem                                                        *
     *  Deletes a menu item from the list based on its ID.                    *
     *------------------------------------------------------------------------*/

    int idToDelete;

    display();

    // Ask the user for the ID of the menu item to delete
    cout << "Enter the ID of the menu item to delete: ";
    cin >> idToDelete;

    // Find the index of the item with the given ID
    int indexToDelete = -1;
    for (int i = 0; i < getSize(); i++) {
        if (getMenuItem(i).getId() == idToDelete) {
            indexToDelete = i;
            break;
        }
    }

    // If no item with the given ID was found
    if (indexToDelete == -1) {
        cout << "Menu item with ID " << idToDelete << " not found." << endl;
        return;
    }

    // Delete the item by calling the remove method from DynamicArrayList
    remove(indexToDelete);
    cout << "Menu item with ID " << idToDelete << " has been deleted." << endl;
    saveMenu();
}


void DynamicArrayList::resetMenu() {
    // Reset the size of the menu to 0
    clear();
    cout << "Menu has been reset successfully!" << endl;
    FileHandler fileHandler("menu.txt");
    fileHandler.clear();
}


void DynamicArrayList::clear() {
    // Reset the size to 0
    size = 0;


    for (int i = 0; i < capacity; i++) {
        menuItem[i] = MenuItem(); // Reset each menu item to the default constructor
    }

    cout << "Menu has been cleared!" << endl;
}
