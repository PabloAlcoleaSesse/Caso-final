#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

class FileManager {
public:
    // Leer el contenido de un archivo
    static std::string readFile(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            throw std::runtime_error("No se pudo abrir el archivo: " + filePath);
        }

        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }

    // Escribir contenido en un archivo
    static void writeFile(const std::string& filePath, const std::string& content) {
        std::ofstream file(filePath);
        if (!file.is_open()) {
            throw std::runtime_error("No se pudo abrir el archivo para escribir: " + filePath);
        }
        file << content;
        file.close();
    }
};

#endif
