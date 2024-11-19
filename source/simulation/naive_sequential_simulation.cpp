#include "simulation/naive_sequential_simulation.h"
#include "simulation/constants.h"
//#include "structures/vector2d.h"
#include "physics/gravitation.h"
#include "physics/mechanics.h"

#include <cmath>

void calculate_forces(Universe universe) {
    for(int i = 0; i<universe.num_bodies; i++) { //gehe ale Körper durch
        Vector2d<double> *f = new Vector2d<double>(); //ist nen pointer geht das auch ohne ? also ohne *

        for (int j = 0; j<universe.num_bodies; j++) {
            //gehe alle andern körper durch
            if(j==i) continue;                          // der i-te körper ist der aktuell betrachtete, dieser wird ausgelassen, da die eigenabhängigkeit physikalisch keinen sinn ergibt
            double d = universe.positions[i]-(universe.positions[j]).betrag; //verbindungsvektor muss noch betrag berechnen
            f = f+gravitational_force(universe.weights[i], universe.weights[j], d); //irgendwie plus rechnen aber ist nen pointer kp wie rausfinden
        }

        universe.forces[i] = f;
    }
}


