#pragma once
#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <vector>
#include <cstdint>
#include "structures/vector2d.h"
#include "input_generator/input_generator.h"
#include "bounding_box.h"

class Universe {
    //Felder definieren
    std::uint32_t num_bodies;
    std::uint32_t current_simulation_epoch;
    double weights;
    Vector2d<double> forces;
    Vector2d<double> velocities;
    Vector2d<double> positions;

    BoundingBox get_bounding_box() { //Methode gibt ein Objekt vom Typ Boundingbox zurück und nimmt keine Argumente an
        double x_min = positions[0];
        double x_max = positions[0];
        double y_min = positions[1];
        double y_max = positions[1];
        // Durchlaufe alle Positionen und finde neue max Werte
        for (const auto& pos : positions) {
            x_min = std::min(x_min, pos[0]);
            x_max = std::max(x_max, pos[0]);
            y_min = std::min(y_min, pos[1]);
            y_max = std::max(y_max, pos[1]);
        }
        //Erstelle BoundingBox mit entsprechenden Grenzen damit sie so klein wie möglich ist
        return BoundingBox(x_min, x_max, y_min, y_max);
    }

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