// Modules/Module.h

#ifndef MODULE_H
#define MODULE_H

#include <string>
#include <vector>

class Module {
public:
    virtual ~Module() = default;

    // El método que cada módulo especializado debe implementar
    virtual std::string execute(const std::vector<std::string>& args) = 0;

    // Nombre del módulo
    virtual std::string getName() const = 0;
};

#endif // MODULE_H
