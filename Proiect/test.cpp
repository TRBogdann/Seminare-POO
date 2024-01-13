#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() {
    // Open the file for reading
    ifstream file("MeniuPrincipal.txt");

    // Read each line of the file and print it to the terminal
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    // Close the file
    file.close();

    // Use std::system() to execute the echo command
    std::system("echo Hello World!");

    return 0;
}