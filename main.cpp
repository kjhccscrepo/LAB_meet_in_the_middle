#include <iostream>
#include <fstream>
#include "src/IntStack.hpp"

int main() {
    std::string input;
    std::ifstream file_to_open;
    std::string file_name = "../data/";
    while (true) {
        while (true) {
            std::cout << "\nEnter the name of a file to open:\t ";
            std::getline(std::cin, input);
            file_name.append(input);
            file_to_open.open(file_name);
            if (!file_to_open.is_open()) {
                std::cout << "File not found in ";
                std::cout << file_name;
                std::cout << ".\n";
                file_to_open.close();
                file_name = input;
                file_to_open.open(file_name);
            }
            if (!file_to_open.is_open()) {
                std::cout << "File not found in root with name, ";
                std::cout << file_name;
                std::cout << ".\n";
                std::cout << "File not found" << std::endl;
                break;
            }
            IntStack stack(&file_to_open);
            std::cout << stack.getMedian() << std::endl;
            std::cout << stack.getMean() << std::endl;
            file_to_open.close();
            return 0;
        }
    }
    return 0;
}