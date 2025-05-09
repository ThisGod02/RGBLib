#include "color.h"
#include <iostream>

int main() {
    // Демонстрация конструкторов
    try {
        color c("blue"); // По имени
        color c1("red");

        // Вывод цветов
        std::cout << "color (with blue): " << c << std::endl;

        // Демонстрация геттеров
        std::cout << "Color with Red: Red: " << c1.getRed() << ", Green : " << c1.getGreen()
            << ", Blue: " << c1.getBlue() << ", Alpha: " << c1.getAlpha() << std::endl;

        // Демонстрация строковых представлений
        std::cout << "c1 RGB: " << c1.toRGB() << std::endl;
        std::cout << "c1 RGBA: " << c1.toRGBA() << std::endl;
        std::cout << "c1 HEX: " << c1.toHex() << std::endl;

        // Демонстрация смешивания цветов
        color mixed = c / c1;
        std::cout << "mix (c / c1): " << mixed << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

}