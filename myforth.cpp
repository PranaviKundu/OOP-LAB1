// Write a C++ program that creates an output file, writes information to it, closes the file, open
// it again as an input file and read the information from the file.


#include <iostream>  // Include the input/output stream library
#include <fstream>   // Include the file stream library for file operations
#include <string>    // Include the string library for string handling

using namespace std; // Use the standard namespace to avoid prefixing std::

int main() {
    // Define the name of the file to be created/used
    const string filename = "example.txt";

    // Create an output file stream to write to the file
    {
        ofstream outFile(filename); // Open the file in write mode
        if (!outFile) { // Check if the file opened successfully
            cerr << "Error opening file for writing." << endl; // Print an error message
            return 1; // Return a non-zero value to indicate failure
        }

        // Write information to the file using the output stream
        outFile << "Hello, World!" << endl; // Write the first line
        outFile << "This is a simple C++ program." << endl; // Write the second line
        outFile << "Goodbye!" << endl; // Write the third line

        // Close the output file to ensure all data is saved
        outFile.close();
    }

    // Create an input file stream to read from the file
    {
        ifstream inFile(filename); // Open the file in read mode
        if (!inFile) { // Check if the file opened successfully
            cerr << "Error opening file for reading." << endl; // Print an error message
            return 1; // Return a non-zero value to indicate failure
        }

        string line; // Declare a string variable to hold each line read from the file
        // Read and display each line from the file until the end is reached
        while (getline(inFile, line)) { // Read a line from the file
            cout << line << endl; // Output the line to the console
        }

        // Close the input file to free up resources
        inFile.close();
    }

    return 0; // Return 0 to indicate successful execution
}
