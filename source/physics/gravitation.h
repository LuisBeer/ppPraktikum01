#pragma once

#include <cmath>

static const double gravitational_constant = 6.67430e-11; //Gravitationskonstante

//berechnen der Anziehungskraft zwischen zwei Körpern
static double gravitational_force(double m1, double m2, double d) {
    return gravitational_constant * m1 * m2 / pow(d, 2);
}
