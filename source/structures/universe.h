#pragma once
#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <vector>
#include <cstdint>
#include "structures/vector2d.h"
#include "input_generator/input_generator.h"


class Universe {
    //Felder definieren
    std::uint32_t num_bodies;
    std::uint32_t current_simulation_epoch;
    double weights;
    Vector2d<double> forces;
    Vector2d<double> velocities;
    Vector2d<double> positions;
public: //Standardkonstruktor erzeugt leeres Universum
    Universe()
        : num_bodies(0),
          current_simulation_epoch(0),
          weights(0),
          forces(),
          velocities(),
          positions() {}
};
#endif