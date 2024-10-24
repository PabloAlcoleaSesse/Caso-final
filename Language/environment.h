#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "type.h"

// Environment: Almacena variables y funciones en un entorno (scope).
class Environment {
public:
    std::map<std::string, Variant> variables;

    // Define una nueva variable o función en el entorno
    void define(const std::string& symbol, const Variant& value) {
        variables[symbol] = value;
    }

    // Busca el valor de una variable
    Variant get(const std::string& symbol) const {
        if (variables.find(symbol) != variables.end()) {
            return variables.at(symbol);
        } else {
            throw std::runtime_error("Variable no definida: " + symbol);
        }
    }
};

#endif
