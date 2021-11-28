#include <iostream>
#include "Rect.h"
#include "math.h"

Rect::Rect() {
    a = 1;
    b = 1;
}

Rect::Rect(double bok) {
    a = bok;
    b = bok;
}

Rect::Rect(double a, double b) {
    this->a = a;
    this->b = b;
}

double Rect::getA() {
    return a;
}

double Rect::getB() {
    return b;
}

double Rect::getDiagonal() {
    return sqrt(a * a + b * b);
}

double Rect::getArea() const {
    return a * b;
}

void Rect::info() {
    std::cout << "Rect[" << a << "," << b << "]\n";
}

bool Rect::isLargerThan(const Rect& r) {
    if (this->getArea() > r.getArea()) return true;
    return false;
}


