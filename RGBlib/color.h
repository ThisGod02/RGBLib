#pragma once
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

class color {
private:
    int _red, _green, _blue, _alpha;
    static const std::map<std::string, color> _rgb;

    // Сеттеры
    void setRed(int r);
    void setGreen(int g);
    void setBlue(int b);
    void setAlpha(int a);

    // Доп функция для преобразования в HEX
    std::string toHex(int value) const;

public:
    // Конструкторы
    color(int r, int g, int b);
    color(int r, int g, int b, int a);
    color(const std::string& name);

    // Геттеры
    int getRed() const { return _red; }
    int getGreen() const { return _green; }
    int getBlue() const { return _blue; }
    int getAlpha() const { return _alpha; }

    // Строковые представления
    std::string toRGB() const;
    std::string toRGBA() const;
    std::string toHex() const;

    // Перегрузка оператора / для смешивания цветов
    color operator/(const color& other) const;

    // Перегрузка оператора << для вывода цвета
    friend std::ostream& operator<<(std::ostream& os, const color& c);
};
