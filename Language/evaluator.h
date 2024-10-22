#ifndef EVALUATOR_H
#define EVALUATOR_H
#include <string>
#include "parser.h"

// Evaluator: Ejecuta una expresión LISP en un Environment dado.
class Evaluator {
public:
    VariantPtr eval(VariantPtr expr, Environment& env) {
        if (std::holds_alternative<int>(*expr)) {
            return expr; // Si es un número, simplemente retorna el número.
        }

        if (std::holds_alternative<std::string>(*expr)) {
            // Si es un símbolo, busca su valor en el entorno
            std::string symbol = std::get<std::string>(*expr);
            return std::make_shared<Variant>(env.get(symbol));
        }

        if (std::holds_alternative<std::vector<VariantPtr>>(*expr)) {
            // Evaluamos una lista de expresiones
            auto expr_list = std::get<std::vector<VariantPtr>>(*expr);
            if (expr_list.empty()) {
                throw std::runtime_error("Lista vacía");
            }

            std::string first = std::get<std::string>(*expr_list[0]); // Función o operador
            if (first == "+") {
                int result = 0;
                for (size_t i = 1; i < expr_list.size(); ++i) {
                    result += std::get<int>(*eval(expr_list[i], env));
                }
                return make_int(result);
            } else if (first == "-") {
                int result = std::get<int>(*eval(expr_list[1], env));
                for (size_t i = 2; i < expr_list.size(); ++i) {
                    result -= std::get<int>(*eval(expr_list[i], env));
                }
                return make_int(result);
            } else {
                throw std::runtime_error("Función desconocida: " + first);
            }
        }

        throw std::runtime_error("Expresión no válida");
    }
};

#endif
