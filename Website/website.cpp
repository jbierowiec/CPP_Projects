#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Ask the user for their name
    cout << "Enter your name: ";
    string name;
    getline(cin, name);

    // Ask the user for a description
    cout << "Enter a description (a sentence or two): ";
    string description;
    getline(cin, description);

    // Create and open the HTML file
    ofstream htmlFile("index.html");

    // Check if the file is successfully opened
    if (htmlFile.is_open()) {
        // Output the HTML content to the file
        htmlFile << "<html>\n<head>\n</head>\n<body>\n"
                 << "     <center>\n"
                 << "          <h1>" << name << "</h1>\n"
                 << "     </center>\n"
                 << "     <hr/>\n"
                 << "     " << description << "\n"
                 << "     <hr/>\n"
                 << "</body>\n</html>\n";

        // Close the file
        htmlFile.close();

        cout << "File 'index.html' created successfully.\n";
    } else {
        cerr << "Error opening file 'index.html'.\n";
        return 1; // Return an error code
    }

    return 0;
}
