// Modules/ModuleManager.h

#ifndef MODULEMANAGER_H
#define MODULEMANAGER_H

#include "Module.h"
#include <unordered_map>
#include <memory>
#include <stdexcept>

class ModuleManager {
private:
    std::unordered_map<std::string, std::shared_ptr<Module>> modules;

public:
    // Registrar un módulo
    void registerModule(std::shared_ptr<Module> module) {
        modules[module->getName()] = module;
    }

    // Ejecutar un comando en el módulo correspondiente
    std::string execute(const std::string& moduleName, const std::vector<std::string>& args) {
        if (modules.find(moduleName) != modules.end()) {
            return modules[moduleName]->execute(args);
        }
        throw std::runtime_error("Module not found: " + moduleName);
    }
};

#endif // MODULEMANAGER_H
