#include "FileHandler.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/*------------------------------------------------------------------------*
 *  FileHandler                                                           *
 *  A class that handles reading, writing, appending, and clearing content *
 *  in a file.                                                             *
 *------------------------------------------------------------------------*/

 // Constructor
 // Initializes the FileHandler object with the given file name
 // and prepares it for file operations. Also initializes `lines` to nullptr
 // and `size` to 0.
FileHandler::FileHandler(const string& fileName) {
    this->fileName = fileName;  // Set the file name to the provided argument
    lines = nullptr;            // Initialize lines to nullptr
    size = 0;                   // Initialize size to 0
}

// write
// This method overwrites the content of the file with the provided string.
// It opens the file in truncate mode and writes the content.
void FileHandler::write(const string& content) {
    ofstream outFile(fileName, ios::trunc);  // Open file in truncate mode to overwrite
    if (outFile.is_open()) {                 // Check if the file was successfully opened
        outFile << content << "\n";          // Write the content to the file
        outFile.close();                     // Close the file after writing
    }
    else {
        cerr << "Unable to open file for writing.\n";  // Error message if the file can't be opened
    }
}

// append
// Appends the given content to the end of the file.
// It opens the file in append mode and writes the content.
void FileHandler::append(const string& content) {
    ofstream outFile(fileName, ios::app);  // Open file in append mode
    if (outFile.is_open()) {               // Check if the file was successfully opened
        outFile << content << "\n";        // Append the content to the file
        outFile.close();                   // Close the file after appending
    }
    else {
        cerr << "Unable to open file for appending.\n";  // Error message if the file can't be opened
    }
}

// read
// Reads the content of the file and stores each line in a dynamic array.
// If the file is empty, it prints an error message.
void FileHandler::read() {
    ifstream inFile(fileName);  // Open file for reading
    if (!inFile.is_open()) {    // Check if the file was successfully opened
        cerr << "Unable to open file for reading.\n";  // Error message if the file can't be opened
        return;
    }

    string line;
    size = 0;  // Reset size before counting lines
    while (getline(inFile, line)) {  // Count the number of lines in the file
        size++;
    }

    if (size == 0) {  // If the file is empty, print a message and return
        cerr << "File is empty.\n";
        inFile.close();
        return;
    }

    // Allocate memory for storing lines
    lines = new string[size];

    // Reset file pointer to the beginning
    inFile.clear();
    inFile.seekg(0, ios::beg);

    // Read each line into the dynamic array
    int index = 0;
    while (getline(inFile, line)) {
        lines[index++] = line;  // Store each line in the lines array
    }

    inFile.close();  // Close the file after reading
}

// clear
// Clears the content of the file by opening it in truncate mode.
// This effectively deletes all content in the file.
void FileHandler::clear() {
    ofstream outFile(fileName, ios::trunc);  // Open file in truncate mode
    if (!outFile.is_open()) {  // If unable to open the file, print an error message
        cerr << "Unable to open file for clearing.\n";
    }
    outFile.close();  // Close the file after clearing
}

// display
// Displays the content of the file line by line.
// It prints an error message if there is no data to display.
void FileHandler::display() {
    if (lines == nullptr || size == 0) {  // Check if the lines array is empty
        cerr << "No data to display.\n";   // Error message if there's no content to display
        return;
    }

    // Display each line in the file
    for (int i = 0; i < size; i++) {
        cout << lines[i] << endl;
    }
}

// getLines
// Returns a pointer to the dynamic array containing the file's lines.
string* FileHandler::getLines() {
    return lines;  // Return the pointer to the array of lines
}

// getSize
// Returns the number of lines in the file (size of the dynamic array).
int FileHandler::getSize() const {
    return size;  // Return the number of lines
}
