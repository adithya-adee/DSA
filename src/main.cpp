#include "../include/graph.hpp"
#include "../include/binary_tree.hpp"
#include <fstream>
#include <iostream>

int main()
{
    // Open input and output files
    std::ifstream inFile("/home/adithya/glitchy_moon/github_repo/DSA/data/input.txt");
    std::ofstream outFile("/home/adithya/glitchy_moon/github_repo/DSA/data/output.txt");

    if (!inFile || !outFile)
    {
        std::cerr << "Error opening input.txt or output.txt!" << std::endl;
        return 1;
    }

    int num1, num2;
    inFile >> num1 >> num2;

    // Write formatted output to file
    outFile << "First number: " << num1 << std::endl;
    outFile << "Second number: " << num2 << std::endl;
    outFile << "Sum: " << num1 + num2 << std::endl;
    outFile << "Product: " << num1 * num2 << std::endl;

    // Close files
    inFile.close();
    outFile.close();

    std::cout << "Processing complete. Check output.txt for results." << std::endl;
    return 0;
}