#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <cmath> // For pow function
#include <limits> // For std::numeric_limits

typedef std::vector<std::string> Tokens;
std::unordered_map<std::string, int> variables;

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
        } else if (token == "=") {
            std::string varName = tokens.back();
            tokens.pop_back();
            int value = stack.top();
            stack.pop();
            variables[varName] = value;
        } else if (variables.find(token) != variables.end()) {
            stack.push(variables[token]);
        } else if (token == "%") {
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(a % b);
        } else if (token == "^") {
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(pow(a, b));
        } else if (token == "min") {
            int min_val = std::numeric_limits<int>::max();
            while (!tokens.empty() && tokens.back() != "(") {
                int a = std::stoi(tokens.back());
                tokens.pop_back();
                min_val = std::min(min_val, a);
            }
            stack.push(min_val);
        } else if (token == "max") {
            int max_val = std::numeric_limits<int>::min();
            while (!tokens.empty() && tokens.back() != "(") {
                int a = std::stoi(tokens.back());
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
    std::getline(std::cin, input);
    Tokens tokens = tokenize(input);
    std::cout << evaluate(tokens) << std::endl;
    return 0;
}