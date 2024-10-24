#ifndef PARSER_H
#define PARSER_H

#include "type.h"
#include "environment.h"
#include <sstream>
#include <stdexcept>

// Parser: Convierte una cadena de entrada en una estructura Variant (AST)
class Parser {
public:
    VariantPtr parse(const std::string& input) {
        std::istringstream iss(input);
        return parse_expression(iss);
    }

private:
    // Parse una expresión desde un stream de entrada
    VariantPtr parse_expression(std::istringstream& iss) {
        char c;
        iss >> c;

        if (c == '(') { // Inicio de una lista
            std::vector<VariantPtr> elements;
            while (iss.peek() != ')') {
                elements.push_back(parse_expression(iss));
            }
            iss.get(); // consumir el ')'
            return make_list(elements);
        } else if (isdigit(c) || (c == '-' && isdigit(iss.peek()))) { // Parse número
            iss.putback(c);
            int number;
            iss >> number;
            return make_int(number);
        } else { // Parse símbolo (nombre de función o variable)
            std::string symbol;
            iss.putback(c);
            iss >> symbol;
            return make_symbol(symbol);
        }
    }
};

#endif
