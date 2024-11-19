#pragma once
#include "structures/vector2d.h"

//Berechne Beschleunigungsvektor aus Kraftvektor und Masse
template <typename T>
Vector2d<T> calculate_acceleration(Vector2d<T> f, double m) {
    return f.operator/(m);
}

//Berechne Geschwindigkeitsvektor aus Beschleunigungsvektor, Zeitintervall und Startgeschwindigkeitsvektor
template <typename T>
Vector2d<T> calculate_velocity(Vector2d<T> a, Vector2d<T> v0,double t) {
    return v0.operator+(a.operator*(t));
}

