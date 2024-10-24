#ifndef TYPE_H
#define TYPE_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <variant>
#include <memory>


class Environment; // Forward declaration

// Variant: Contendrá números, strings (símbolos) o listas de otros Variant.
using Variant = std::variant<int, std::string, std::vector<std::shared_ptr<Variant>>>;

// Para facilitar el manejo de listas
using VariantPtr = std::shared_ptr<Variant>;

// Helpers para crear nuevos tipos de datos
VariantPtr make_int(int x) { return std::make_shared<Variant>(x); }
VariantPtr make_symbol(const std::string& x) { return std::make_shared<Variant>(x); }
VariantPtr make_list(const std::vector<VariantPtr>& x) { return std::make_shared<Variant>(x); }

#endif
