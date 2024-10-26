//
// Created by esteb on 22/10/2024
//

// tiny_lisp.cpp

#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cmath> // Para operaciones matemáticas avanzadas como pow
#include <limits> // Para valores máximos y mínimos
#include <algorithm>
#include <unordered_map>
#include <functional>

//Definir tokens como un vector de strings, en ellos se almacenaran los tokens de la entrada
typedef std::vector<std::string> Tokens;
//Definir variables como un mapa no ordenado de strings y doubles, en ellos se almacenaran las variables y sus valores
std::unordered_map<std::string, double> variables;
//Definir funciones como un mapa no ordenado de strings y pares de enteros y funciones, en ellos se almacenaran las funciones y sus argumentos
std::unordered_map<std::string, std::pair<int, std::function<double(const std::vector<double>&)>>>functions;


//Tokenizar la entrada, convirtiendo el string de entrada en un vector de tokens
Tokens tokenize(const std::string& input) {
    Tokens tokens;
    std::istringstream stream(input);
    std::string token;
    while (stream >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

//Evaluar la expresión dada en notación postfija
//Utiliza una pila para manejar los operandos y operadores
double evaluate(Tokens& tokens) {
    std::stack<int> stack;

    while (!tokens.empty()) {
        std::string token = tokens.front();
        tokens.erase(tokens.begin());


        //Operadores aritmeticos
        /* Esta condicion nos permite verificar si hay suficientes valores en la pila para realizar la operacion, si no los hay se lanza un mensaje de error:
            if (stack.size() < 2){
                throw std::runtime_error("Valores insuficientes para realizar la (operacion en cuestion)");
            }
        */
        //Suma
        if (token == "+") {
            if (stack.size() < 2) {
                throw std::runtime_error("Valores insuficientes para realizar la suma");
            }
            double a = stack.top();
            stack.pop();
            double b = stack.top();
            stack.pop();
            stack.push(a + b);
        }
            //Resta
        else if (token == "-") {
            if (stack.size() < 2) {
                throw std::runtime_error("Valores insuficientes para realizar la resta");
            }
            double a = stack.top();
            stack.pop();
            double b = stack.top();
            stack.pop();
            stack.push(a - b);
        }
            //Multiplicacion
        else if (token == "*") {
            if (stack.size() < 2) {
                throw std::runtime_error("Valores insuficientes para realizar la multiplicacion");
            }
            double a = stack.top();
            stack.pop();
            double b = stack.top();
            stack.pop();
            stack.push(a * b);
        }
            //Division
            //Si b = 0, se lanza un mensaje de error informando que no se puede dividir por cero
        else if (token == "/") {
            if (stack.size() < 2) {
                throw std::runtime_error("Valores insuficientes para realizar la division");
            }
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
            if (b == 0) {
                throw std::runtime_error("Division por cero");
            }
            stack.push(a / b);
        }
        else if (token == "%") { // Módulo
            if (stack.size() < 2){
                throw std::runtime_error("Valores insuficientes para realizar el modulo");
            }
            double a = stack.top(); stack.pop();
            double b = stack.top(); stack.pop();
            stack.push(fmod(a, b));
        } else if (token == "^") { // Potencia
            if (stack.size() < 2){
                throw std::runtime_error("Valores insuficientes para realizar la potencia");
            }
            double a = stack.top(); stack.pop();
            double b = stack.top(); stack.pop();
            stack.push(pow(a, b));
        }
        //Valor absoluto
        else if (token == "abs") {
            if (stack.size() < 1){
                throw std::runtime_error("Valores insuficientes para realizar el valor absoluto");
            }
            double a = stack.top(); stack.pop();
            stack.push(abs(a));
        }
        //Operadores trigonometricos

        //Operadores logicos
        else if (token == "min") { // Mínimo con múltiples argumentos
            if (stack.size() < 2){
                throw std::runtime_error("Valores insuficientes para realizar el minimo");
            }
            double min_val = std::numeric_limits<double>::max();
            while (!tokens.empty() && tokens.back() != "(") {
                double a = std::stoi(tokens.back());
                tokens.pop_back();
                min_val = std::min(min_val, a);
            }
            stack.push(min_val);
        } else if (token == "max") { // Máximo con múltiples argumentos
            double max_val = std::numeric_limits<int>::min();
            while (!tokens.empty() && tokens.back() != "(") {
                double a = std::stoi(tokens.back());
                tokens.pop_back();
                max_val = std::max(max_val, a);
            }
            stack.push(max_val);
        } else {
            stack.push(std::stoi(token));
        }
    }

    return stack.top();
}

int main() {
    std::string input;
    while (true){
        std::cout << "->";
        std::getline(std::cin, input);
        if (input == "exit") break;
        try {
            Tokens tokens = tokenize(input);
            std::cout << evaluate(tokens) << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}
