#pragma once
#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <cmath>
#include <stdexcept> // Für std::exception

template <typename T>
class Vector2d {
public:

    // Standardkonstruktor, initialisiert die Komponenten auf 0
    Vector2d() : x(T{}), y(T{}) {}

    // Konstruktor zum direkten Setzen der Komponenten
    Vector2d(T x, T y) : x(x), y(y) {}

    // Methode zum Setzen der Komponenten
    void set(T x, T y) {
        this->x = x;
        this->y = y;
    }

    // Zugriff auf die Komponenten mit dem []-Operator
    T operator[](size_t index) const {
        if (index == 0) {
            return x;
        } else if (index == 1) {
            return y;
        } else {
            throw std::out_of_range("Index out of range for Vector2d");
        }
    }

    // Operatoren-Implementierungen

    // Addition zweier Vektoren
    Vector2d operator+(const Vector2d& other) const {
        return Vector2d(x + other.x, y + other.y);
    }

    // Subtraktion zweier Vektoren
    Vector2d operator-(const Vector2d& other) const {
        return Vector2d(x - other.x, y - other.y);
    }

    // Multiplikation mit einem Skalar
    Vector2d operator*(T scalar) const {
        return Vector2d(x * scalar, y * scalar);
    }

    // Division durch ein Skalar
    Vector2d operator/(T scalar) const {
        if (scalar == T{}) {
            throw std::invalid_argument("Division by zero");
        }
        return Vector2d(x / scalar, y / scalar);
    }

    // Gleichheitsoperator
    bool operator==(const Vector2d& other) const {
        return x == other.x && y == other.y;
    }

    //Vektorbetrag
    double value() {
        return sqrt(x * x + y * y);
    }

private:
    T x; // Komponente 0
    T y; // Komponente 1
};

#endif // VECTOR2D_H

