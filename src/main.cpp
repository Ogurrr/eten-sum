#include <iostream>
#include <fstream>
#include <vector>

#include <stdexcept>
#include "../libs/eten-algorithm/eten-cpu/eten.h"
#include "../libs/eten-algorithm/eten-cpu/caesar.h"

// Function to read the content of a file
std::string readFile(const std::string& filePath) {
    std::ifstream file(filePath, std::ios::binary);
    
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filePath);
    }
    
    // Pobierz długość pliku
    file.seekg(0, std::ios::end);
    std::streampos fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // Zarezerwuj pamięć dla całej zawartości pliku
    std::string content;
    content.resize(fileSize);

    // Odczytaj zawartość pliku
    file.read(&content[0], fileSize);

    file.close();
    
    return content;
}
int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Syntax: eten-sum {file path}" << std::endl;
        return 1;
    }
    
    std::string filePath = argv[1];
    std::string fileContent;
    int size = std::stoi(argv[2]);
    
    try {
        fileContent = readFile(filePath);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    std::string caesarResult = caesarEncrypt(fileContent, 2);
    std::string result = etenCalc(fileContent, caesarResult, 1,size);
    std::cout << result << std::endl;
    
    return 0;
}
