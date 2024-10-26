// Modules/DBModule.h

#ifndef DBMODULE_H
#define DBMODULE_H

#include "Module.h"
#include <unordered_map>
#include <stdexcept>

class DBModule : public Module {
private:
    std::unordered_map<std::string, std::string> db;

public:
    std::string execute(const std::vector<std::string>& args) override {
        if (args.empty()) {
            throw std::runtime_error("No arguments provided for DBModule.");
        }

        std::string operation = args[0];

        if (operation == "set") {
            if (args.size() != 3) {
                throw std::runtime_error("Invalid number of arguments for set.");
            }
            db[args[1]] = args[2];
            return "OK";
        } else if (operation == "get") {
            if (args.size() != 2) {
                throw std::runtime_error("Invalid number of arguments for get.");
            }
            if (db.find(args[1]) != db.end()) {
                return db[args[1]];
            } else {
                return "Key not found";
            }
        }

        throw std::runtime_error("Operation not supported in DBModule.");
    }

    std::string getName() const override {
        return "DBModule";
    }
};

#endif // DBMODULE_H
