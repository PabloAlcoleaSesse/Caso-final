//
// Created by esteb on 22/10/2024.
//

// tiny_lisp.cpp
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <cmath> // Para operaciones matemáticas avanzadas como pow

typedef std::vector<std::string> Tokens;

Tokens tokenize(const std::string& input) {
    Tokens tokens;
    std::string token;
    std::istringstream stream(input);

    while (stream >> token) {
        tokens.push_back(token);
    }

    return tokens;
}

int evaluate(Tokens& tokens) {
    std::stack<int> stack;

    while (!tokens.empty()) {
        std::string token = tokens.back();
        tokens.pop_back();

        if (token == "+") {
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(a + b);
        } else if (token == "-") {
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(a - b);
        } else if (token == "*") {
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(a * b);
        } else if (token == "/") {
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            if (b != 0) {
                stack.push(a / b);
            } else {
                std::cerr << "Error: División por cero" << std::endl;
                return 0;
            }
        } else if (token == "%") { // Módulo
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(a % b);
        } else if (token == "^") { // Potencia
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(pow(a, b));
        } else if (token == "min") { // Mínimo
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(std::min(a, b));
        } else if (token == "max") { // Máximo
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(std::max(a, b));
        } else {
            stack.push(std::stoi(token));
        }
    }

    return stack.top();
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    Tokens tokens = tokenize(input);
    std::cout << evaluate(tokens) << std::endl;
    return 0;
}
