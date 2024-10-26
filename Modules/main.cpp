// main.cpp

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Modules/ModuleManager.h"
#include "Modules/MathModule.h"
#include "Modules/DBModule.h"

// Función para dividir la entrada del usuario en tokens
std::vector<std::string> tokenize(const std::string& input) {
    std::istringstream stream(input);
    std::vector<std::string> tokens;
    std::string token;
    while (stream >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    ModuleManager manager;

    // Registrar módulos
    manager.registerModule(std::make_shared<MathModule>());
    manager.registerModule(std::make_shared<DBModule>());

    std::string input;
    while (std::getline(std::cin, input)) {
        std::vector<std::string> tokens = tokenize(input);
        if (tokens.size() < 2) {
            std::cerr << "Error: invalid command format" << std::endl;
            continue;
        }

        std::string moduleName = tokens[0];
        std::vector<std::string> args(tokens.begin() + 1, tokens.end());

        try {
            std::string result = manager.execute(moduleName, args);
            std::cout << "Resultado: " << result << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}
