#pragma once
#ifndef VECTOR2D_H //ifnotdefined bzw if vector2hd not defined (.h sind header-Dateien)
#define VECTOR2D_H

#include <stdexcept> //braucht man um std::exception zu nutzen

template <typename T> //Typparameter
class Vector2d {
public:
    Vector2d() : x(T{}), y(T{}) {} //Standardkonstruktor
    Vector2d(T x, T y) : x(x), y(y) {} //Konstruktor zum direkten Setzen der Komponenten

    T operator[](size_t index) const { //Erwartet index und gibt T zurück Index-Zugriffsoperator []
        //Zugriff auf x und y oder Exception
        if (index == 0) {
            return x;
        } else if (index == 1) {
            return y;
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    void set(T x, T y) { //void Methode nimmt Werte für x und y
        //überschreibt x und y
        this->x = x;
        this->y = y;
    }

    //Addition zweier Vektoren
    Vector2d<T> operator+(const Vector2d<T>& other) const {
        return Vector2d<T>(x + other.x, y + other.y); //addiert x und y Komponente vom Vektor other zu x und y
    }

    //Subtraktion zweier Vektoren
    Vector2d<T> operator-(const Vector2d<T>& other) const {
        return Vector2d<T>(x - other.x, y - other.y); //subtrahiert x und y Komponente vom Vektor other von x und y
    }

    //Multiplikation des Vektors mit einem Skalar
    Vector2d<T> operator*(T multi) const {
        return Vector2d<T>(x * multi, y * multi); //multipliziert multi mit x und y
    }

    //Division des Vektors durch einen Skalar
    Vector2d<T> operator/(T divi) const {
        if (divi == T{}) {
            throw std::invalid_argument("Division with zero");
        }
        return Vector2d<T>(x / divi, y / divi);
    }

    //Gleichheitsoperator
    bool operator==(const Vector2d<T>& other) const {
        return x == other.x && y == other.y;
    }

private:
    T x;
    T y;
};

#endif

