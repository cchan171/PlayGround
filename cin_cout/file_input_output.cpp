/**
@file file_input_output.cpp

@brief
    Files, Streams and I/O
        Input Device ===> Input Stream ===> Program ===> Output Stream ===> Output Device

@par 
    Common Header Files:
        <fstream>: Provides definitions for formatted input and output from/to file streams
    Common Stream:
        std::ios -> Provides basic support for formatted and unformatted I/O operations.
        std::ifstream -> Provides for high-level input operations on file based streams.
        std::ofstream -> Provides for high-level output operations on file based streams.
        std::fstream -> Provides for high-level I/O operations on file based streams. Derived from std::ofstream and std::ifstream.
        std::stringstream -> Provides for high-level I/O operations on memory based strings. Derived from std::istringstream, std::ostringstream.
    Input File Steps:
        1. #include <fstream>.
        2. Declare an fstream or ifstream object.
        3. Connect it to a file on your file system (opens it for reading).
        4. Read data from the file via the stream.
        5. Close the stream.
    Output File Steps:
        1. #include <fstream>.
        2. Declare an fstream or ofstream object.
        3. Connect it to a file on your file system (opens it for writing).
        4. Write data to the file via the stream.
        5. Close the stream.
    Output Files:
        * Output files will be created if they don't exist.
        * Output files will be overwritten (truncated) by default.
        * Can be opened so that new writes append.
        * Can be open in text or binary modes.
    Using String Streams:
        1. #include <sstream>
        2. Declare an stringstream, istringstream, ostringstream object.
        3. Connect it to a std::string
        4. Read/Write data from/to the string stream using formatted I/O.

$Author: $

$Date: Feb. 22, 2024$

$Revision: A0-1$

$Source: $

@par history:
    $Log: $

*/
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main() {
    /* Open a file for reading with fstream */
    std::fstream in_file {"../myfile.txt"};
    // std::fstream in_file {"../myfile.txt", std::ios::in | std::ios::binary}; // binary mode
    
    /* Open a file for reading with ifstream */
    std::ifstream in_file {"../myfile.txt", std::ios::in};
    // std::ifstream in_file {"../myfile.txt"};     // it gets the same effect with or without std::ios::in
    // std::ifstream in_file {"../myfile.txt", std::ios::binary};   // binary mode

    /* Open a file for reading with open */
    std::ifstream in_file;
    std::string filename;
    std::cin >> filename;       // get the filename
    in_file.open(filename);
    // in_file.open(filename, std::ios::binary);

    /* Check if file opened successfully is_open */
    if (in_file.is_open()) {
        // read from it
    } else {
        // file could not be opened
        // does it exist?
        // should the program terminate?
    }
    if (in_file) {  // just check the object
        // read from it
    } else {
        // file could not be opened
        // does it exist?
        // should the program terminate?
    }

    /* Closing a file */
    in_file.close();

    /* Reading from files using >> */
    // We can use the extraction operator for formatted read
    // Same way we used it with cin
    int num {};             // 100
    double total {};        // 255.67
    std::string name {};    // Larry
    in_file >> num;
    in_file >> total >> name;

    /* Reading from files using getline */
    std::string line{};                         // This is a line
    std::getline(in_file, line);

    /* Reading text file one line at a time */
    std::ifstream in_file {"../myfile.txt"};    // open file
    std::string line {};
    if (!in_file) {                             // check if file is open
        std::cerr << "File open error" << std::endl;
        return 1;                               // exit the program (main)
    }
    while (!in_file.eof()) {                    // while not at the end
        std::getline(in_file, line);            // read a line
        std::cout << line << std::endl;         // display the line
    }
    in_file.close();                            // close the file

    /* Reading text file one line at a time */
    std::ifstream in_file {"../myfile.txt"};    // open file
    std::string line {};
    if (!in_file) {                             // check if file is open
        std::cerr << "File open error" << std::endl;
        return 1;                               // exit the program (main)
    }
    while (std::getline(in_file, line))         // read a line
        std::cout << line << std::endl;
    in_file.close();                            // close a file

    /* Reading text file one character at a time (get) */
    std::ifstream in_file {"../myfile.txt"};    // open file
    char c;                                     // unformatted manner 1 char @ a time
    if (!in_file) {                             // check if file is open
        std::cerr << "File open error" << std::endl;
        return 1;                               // exit the program (main)
    }
    while (in_file.get(c))                      // read a character
        std::cout << c;                         // display the character
    in_file.close();                            // close a file

    /* Open a file for writing with fstream */
    std::fstream out_file {"../myfile.txt", std::ios::out};
    // std::fstream out_file {"../myfile.txt", std::ios::out | std::ios::binary};   // binary mode

    /* Open a file for writing with ofstream */
    std::ofstream out_file {"../myfile.txt", std::ios::out};
    // std::ofstream out_file {"../myfile.txt"};   // by default in ofstream
    // std::ofstream out_file {"../myfile.txt", std::ios::binary};
    // truncate/discard contents when opening
    std::ofstream out_file {"../myfile.txt", std::ios::trunc};
    // append on each write
    std::ofstream out_file {"../myfile.txt", std::ios::app};
    // seek to end of stream when opening
    std::ofstream out_file {"../myfile.txt", std::ios::ate};

    /* Opening a file for writing with open */
    std::ofstream out_file;
    std::string filename;
    std::cin >> filename;                           // get the filename
    out_file.open(filename);
    // out_file.open(filename, std::ios::binary);   // binary mode

    /* Check if file opened successfully (is_open) */
    if (out_file.is_open()) {
        // read from it
    } else {
        // file could not be created or opened
        // does it exist?
        // should the program terminate?
    }

    /* Check if file opened successfully - test the stream object */
    if (out_file) {                                 // just check the object
        // read from it
    } else {
        // file could not be opened
        // does it exist?
        // should the program terminate?
    }

    /* Closing a file */
    // Alwasy close any open files to flush out any unwritten data
    out_file.close();

    /* Writing to files using << */
    int num {100}; 
    double total {255.67};
    std::string name {"Larry"};
    out_file << num     << "\n"
             << total   << "\n"
             << name    << std::endl;

    /* Copying a text file one line at a time */
    std::ifstream in_file {"../myfile.txt"};        // open file
    std::ofstream out_file {"../copy.txt"};
    if (!in_file) {                                 // check if file is open
        std::cerr << "File open error" << std::endl;
        return 1;                                   // exit the program (main)
    }
    if (!out_file) {                                // check if file is open
        std::cerr << "File open error" << std::endl;
        return 1;                                   // exit the program (main)
    }

    /* Copy a text file one line at a time */
    std::string line {};
    while (std::getline(in_file, line))             // read a line
        out_file << line << std::endl;              // write a line
    in_file.close();                                // close the files
    out_file.close();

    /* Copy a text file one line at a time (get/put) */
    std::ifstream in_file {"../myfile.txt"};
    std::ofstream out_file {"../copy.txt"};
    if (!in_file) {                                 // check if file is open
        std::cerr << "File open error" << std::endl;
        return 1;                                   // exit the program (main)
    }
    if (!out_file) {
        std::cerr << "File create error" << std::endl;
        return 1;
    }

    /* Copy a text file one line at a time (get/put) */
    char c;
    while (in_file.get(c))                          // read a character
        out_file.put(c);                            // write the character
    in_file.close();                                // close the files
    out_file.close();

    /* Reading from a stringstream */
    int num {};
    double total {};
    std::string name {};
    std::string info {"Moe 100 1234.5"};

    std::istringstream iss {info};
    iss >> name >> num >> total;

    /* Writing to a stringstream */
    int num {100};
    double total {1234.5};
    std::string name {"Moe"};
    std::ostringstream oss {};
    oss << name << " " << num << " " << total;      // write to sstream object
    std::cout << oss.str() << std::endl;            // could link to the string object but here we use string stream buffer for internal use.

    /* Validating input with stringstream */
    int value {};
    std::string input {};
    std::cout << "Enter an integer: ";
    std::cin >> input;
    std::stringstream ss {input};
    if (ss >> value) {
        std::cout << "An integer was entered";
    } else {
        std::cout << "An integer was NOT entered";
    }
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max());    // ignore the given size of stream buffer (which is mximum)

    return 0;
}