#include "type.h"
#include "parser.h"
#include "environment.h"
#include "evaluator.h"

int main() {
    Environment env;
    Parser parser;
    Evaluator evaluator;

    // Definir algunas expresiones
    std::string expr1 = "(+ 1 2 3)";
    std::string expr2 = "(- 10 4 1)";

    try {
        // Parse y evalúa la primera expresión
        VariantPtr parsed_expr1 = parser.parse(expr1);
        VariantPtr result1 = evaluator.eval(parsed_expr1, env);
        std::cout << "Resultado de " << expr1 << " es: " << std::get<int>(*result1) << std::endl;

        // Parse y evalúa la segunda expresión
        VariantPtr parsed_expr2 = parser.parse(expr2);
        VariantPtr result2 = evaluator.eval(parsed_expr2, env);
        std::cout << "Resultado de " << expr2 << " es: " << std::get<int>(*result2) << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
