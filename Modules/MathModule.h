// Modules/MathModule.h

#ifndef MATHMODULE_H
#define MATHMODULE_H

#include "Module.h"
#include <stdexcept>
#include <sstream>

class MathModule : public Module {
public:
    // Implementación del método execute para operaciones matemáticas
    std::string execute(const std::vector<std::string>& args) override {
        if (args.empty()) {
            throw std::runtime_error("No arguments provided for MathModule.");
        }

        std::string operation = args[0];
        if (operation == "add") {
            if (args.size() != 3) {
                throw std::runtime_error("Invalid number of arguments for add.");
            }
            int a = std::stoi(args[1]);
            int b = std::stoi(args[2]);
            return std::to_string(a + b);
        } else if (operation == "mul") {
            if (args.size() != 3) {
                throw std::runtime_error("Invalid number of arguments for mul.");
            }
            int a = std::stoi(args[1]);
            int b = std::stoi(args[2]);
            return std::to_string(a * b);
        }

        throw std::runtime_error("Operation not supported in MathModule.");
    }

    // El nombre del módulo
    std::string getName() const override {
        return "MathModule";
    }
};

#endif // MATHMODULE_H
