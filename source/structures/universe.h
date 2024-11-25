#pragma once
#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <vector>
#include <cstdint>
#include "structures/vector2d.h"
#include "bounding_box.h"

class Universe {
    //Felder definieren
    public: //public damit ich in Simulation auf die Werte zugreifen kann. Oder get und set Methoden schreiben
        std::uint32_t num_bodies;
        std::uint32_t current_simulation_epoch;
        std::vector<double> weights;
        std::vector<Vector2d<double>> forces;
        std::vector<Vector2d<double>> velocities;
        std::vector<Vector2d<double>> positions;
    // diese Werte müssen in std::vector gespeichert werden, das ist wie nen Array mit dynamischer Länge. Jedes Feld bezieht sich dabei auf einen Himmelskörper.
    // die Reihenfolge der Himmelskörper muss in jedem Array gleich sein (Weights[1] und Velocities[1] solle beide jeweils die Werte von Himmelskörper 1 enthalten)
    // Entsprechend Boundingboxes anpassen

    BoundingBox get_bounding_box() { //Methode gibt ein Objekt vom Typ Boundingbox zurück und nimmt keine Argumente an
        double x_min = positions[0][0];
        double x_max = positions[0][0];
        double y_min = positions[0][1];
        double y_max = positions[0][1];
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

    //Nächste Simulations-Epoche
};
#endif