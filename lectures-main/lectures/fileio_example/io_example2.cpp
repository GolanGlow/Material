#include <iostream>  // std::cout, std::endl
#include <fstream>   // std::ifstream
#include <string>    // std::stream

int main() {
    std::ofstream outputFile;
    outputFile.open("output.txt");

    if (!outputFile) {
        std::cerr << "Unable to create file!" << std::endl;
        return 1;
    }

    outputFile << "Hello, world!" << std::endl;
    outputFile << "This is a sample text." << std::endl;

    outputFile.close();

    std::ifstream inputFile;
    inputFile.open("output.txt");
    
    std::string line;
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }

    inputFile.close();

    return 0;
}