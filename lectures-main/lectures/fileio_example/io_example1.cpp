#include <iostream> // std::cout, std::endl, std::cerr
#include <fstream>  // std::ifstream
#include <string>   // std::string

int main() {
    std::ifstream inputFile;
    inputFile.open("example.txt");

    if (!inputFile) {
        std::cerr << "Unable to open file!" << std::endl;
        // Exit the main function, thereby stopping the program execution
        return 1;
    }

    std::string line;
    // Read a line from the file as a string using getline
    // Returns 0 when the end of file is reached, which is interpreted as false
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }

    inputFile.close();
    return 0;
}