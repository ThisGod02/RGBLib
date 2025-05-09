#include "color.h"

// Инициализация статической карты цветов
const std::map<std::string, color> color::_rgb = {
    {"black", color(0, 0, 0)},
    {"silver", color(192, 192, 192)},
    {"gray", color(128, 128, 128)},
    {"white", color(255, 255, 255)},
    {"maroon", color(128, 0, 0)},
    {"red", color(255, 0, 0)},
    {"purple", color(128, 0, 128)},
    {"fuchsia", color(255, 0, 255)},
    {"green", color(0, 128, 0)},
    {"lime", color(0, 255, 0)},
    {"olive", color(128, 128, 0)},
    {"yellow", color(255, 255, 0)},
    {"navy", color(0, 0, 128)},
    {"blue", color(0, 0, 255)},
    {"teal", color(0, 128, 128)},
    {"aqua", color(0, 255, 255)}
};

// Конструктор для RGB
color::color(int r, int g, int b) : _red(0), _green(0), _blue(0), _alpha(255) {
    setRed(r);
    setGreen(g);
    setBlue(b);
}

// Конструктор для RGBA
color::color(int r, int g, int b, int a) : _red(0), _green(0), _blue(0), _alpha(255) {
    setRed(r);
    setGreen(g);
    setBlue(b);
    setAlpha(a);
}

// Конструктор по имени цвета
color::color(const std::string& name) : _red(0), _green(0), _blue(0), _alpha(255) {
    auto it = _rgb.find(name);
    if (it != _rgb.end()) {
        _red = it->second._red;
        _green = it->second._green;
        _blue = it->second._blue;
        _alpha = it->second._alpha;
    }
    else {
        throw std::invalid_argument("Color with name '" + name + "' not found");
    }
}

// Приватные сеттеры с валидацией
void color::setRed(int r) {
    _red = (r < 0) ? 0 : (r > 255) ? 255 : r;
}

void color::setGreen(int g) {
    _green = (g < 0) ? 0 : (g > 255) ? 255 : g;
}

void color::setBlue(int b) {
    _blue = (b < 0) ? 0 : (b > 255) ? 255 : b;
}

void color::setAlpha(int a) {
    _alpha = (a < 0) ? 0 : (a > 255) ? 255 : a;
}

// Преобразование в строку RGB
std::string color::toRGB() const {
    return "RGB(" + std::to_string(_red) + "," + std::to_string(_green) + "," + std::to_string(_blue) + ")";
}

// Преобразование в строку RGBA
std::string color::toRGBA() const {
    return "RGBA(" + std::to_string(_red) + "," + std::to_string(_green) + "," +
        std::to_string(_blue) + "," + std::to_string(_alpha) + ")";
}

// Преобразование в HEX
std::string color::toHex() const {
    return "#" + toHex(_red) + toHex(_green) + toHex(_blue);
}

// Вспомогательная функция для HEX
std::string color::toHex(int value) const {
    std::stringstream ss;
    ss << std::hex << std::setw(2) << std::setfill('0') << value;
    return ss.str();
}

// Оператор смешивания цветов
color color::operator/(const color& other) const {
    int newRed = (_red + other._red) / 2;
    int newGreen = (_green + other._green) / 2;
    int newBlue = (_blue + other._blue) / 2;
    int newAlpha = (_alpha + other._alpha) / 2;
    return color(newRed, newGreen, newBlue, newAlpha);
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, const color& c) {
    os << c.toRGBA();
    return os;
}