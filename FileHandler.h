#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <string>
using namespace std;

/*------------------------------------------------------------------------*
 *  FileHandler                                                            *
 *  A class that handles reading, writing, appending, and clearing content *
 *  in a file.                                                             *
 *------------------------------------------------------------------------*/
class FileHandler {

private:
    string fileName;    // Name of the file to operate on
    string* lines;      // Pointer to a dynamic array that stores file content
    int size;           // The number of lines in the file

public:
    /*------------------------------------------------------------------------*
     *  FileHandler                                                           *
     *  Constructor that initializes the file name and prepares for file      *
     *  operations.                                                           *
     *                                                                        *
     *  Precondition: fileName is a valid file path.                          *
     *  Postcondition: The FileHandler object is initialized with the given  *
     *                 file name and prepares for further file operations.   *
     *------------------------------------------------------------------------*/
    FileHandler(const string& fileName);

    /*------------------------------------------------------------------------*
     *  write                                                                 *
     *  Overwrites the content of the file with the given string.             *
     *                                                                        *
     *  Precondition: content is the new text to write to the file.           *
     *  Postcondition: The file is overwritten with the provided content.    *
     *------------------------------------------------------------------------*/
    void write(const string& content);

    /*------------------------------------------------------------------------*
     *  append                                                                *
     *  Appends the given string to the end of the file.                      *
     *                                                                        *
     *  Precondition: content is the text to append to the file.              *
     *  Postcondition: The content is added to the end of the file.           *
     *------------------------------------------------------------------------*/
    void append(const string& content);

    /*------------------------------------------------------------------------*
     *  read                                                                  *
     *  Reads the content of the file and stores each line into a dynamic    *
     *  array.                                                                *
     *                                                                        *
     *  Precondition: The file exists and is accessible for reading.          *
     *  Postcondition: The file content is read and stored in the lines array.*
     *------------------------------------------------------------------------*/
    void read();

    /*------------------------------------------------------------------------*
     *  clear                                                                 *
     *  Clears the content of the file, making it empty.                      *
     *                                                                        *
     *  Precondition: None.                                                   *
     *  Postcondition: The file is emptied, and all previous content is lost.*
     *------------------------------------------------------------------------*/
    void clear();

    /*------------------------------------------------------------------------*
     *  display                                                               *
     *  Displays the content of the file on the console.                      *
     *                                                                        *
     *  Precondition: The file has been read and lines are stored.            *
     *  Postcondition: The file's content is printed to the console.          *
     *------------------------------------------------------------------------*/
    void display();

    /*------------------------------------------------------------------------*
     *  getLines                                                              *
     *  Returns the dynamic array of lines read from the file.                *
     *                                                                        *
     *  Precondition: The file has been read.                                 *
     *  Postcondition: Returns a pointer to the array holding the file's lines.*
     *------------------------------------------------------------------------*/
    string* getLines();

    /*------------------------------------------------------------------------*
     *  getSize                                                               *
     *  Returns the number of lines in the file.                              *
     *                                                                        *
     *  Precondition: The file has been read.                                 *
     *  Postcondition: Returns the number of lines stored in the array.       *
     *------------------------------------------------------------------------*/
    int getSize() const;
};

#endif
