
#ifndef COLOR_MANAGER_H
#define CO
OR

ANAGER_H

#include <string>
#include <sstream>
#include <iomanip>

class ColorManager {
public:
    // Convierte valores RGB a un formato hexadecimal
    static std::string rgbToHex(int r, int g, int b) {
        std::stringstream ss;
        ss << "#" << std::hex << std::setw(2) << std::setfill('0') << (r & 0xFF)
           << std::setw(2) << std::setfill('0') << (g & 0xFF)
           << std::setw(2) << std::setfill('0') << (b & 0xFF);
        return ss.str();
    }

    // Convierte un color hexadecimal a valores RGB
    static void hexToRgb(const std::string& hex, int& r, int& g, int& b) {
        if (hex[0] == '#') {
            std::stringstream ss;
            ss << std::hex << hex.substr(1);
            int color;
            ss >> color;
            r = (color >> 16) & 0xFF;
            g = (color >> 8) & 0xFF;
            b = color & 0xFF;
        }
    }
};

#endif
