#include "simulation/naive_sequential_simulation.h"
#include "simulation/constants.h"
//#include "structures/vector2d.h"
//#include "structures/universe.h"
#include "plotting/plotter.h"
#include "physics/gravitation.h"
#include "physics/mechanics.h"

#include <cmath>

void NaiveSequentialSimulation::calculate_forces(Universe &universe) {
    for(int i = 0; i<universe.num_bodies; i++) { //gehe ale Körper durch
        Vector2d<double> f;

        for (int j = 0; j<universe.num_bodies; j++) {
            //gehe alle andern körper durch
            if(j==i) continue;                          // der i-te körper ist der aktuell betrachtete, dieser wird ausgelassen, da die eigenabhängigkeit physikalisch keinen sinn ergibt
            Vector2d<double> connect = universe.positions[j]-(universe.positions[i]);
            double d = connect.value(); //verbindungsvektor muss noch betrag berechnen
            f = f + connect / d * gravitational_force(universe.weights[i], universe.weights[j], d); //verbindungsvektor durch Betrag ist verbindungseinheitsvektor mal Kraft ist der Kraft richtungsvektor
        }
        universe.forces[i] = f;
    }
}

void NaiveSequentialSimulation::calculate_velocities(Universe &universe) {
    calculate_forces(universe);
    for(int i = 0; i<universe.num_bodies; i++) {//gehe ale Körper durch
        Vector2d<double> a = calculate_acceleration(universe.forces[i], universe.weights[i]);
        universe.velocities[i] = calculate_velocity(a, universe.velocities[i], epoch_in_seconds);
    }
}

void NaiveSequentialSimulation::calculate_positions(Universe &universe) {
    calculate_velocities(universe);
    for(int i = 0; i<universe.num_bodies; i++) {//gehe ale Körper durch
        Vector2d<double> ds = universe.velocities[i]*epoch_in_seconds;
        universe.positions[i] = universe.positions[i] + ds;
    }
}

void NaiveSequentialSimulation::simulate_epoch(Plotter& plotter, Universe& universe, bool create_intermediate_plots, std::uint32_t plot_intermediate_epochs){
    calculate_positions(universe);
    universe.current_simulation_epoch += 1;

    //auto *plt = new Plotter(universe.get_bounding_box(), "output", 500, 500);

    if(universe.current_simulation_epoch%plot_intermediate_epochs==0 && create_intermediate_plots) {
        plotter.write_and_clear();
    }
}

 void NaiveSequentialSimulation::simulate_epochs(Plotter& plotter, Universe& universe, std::uint32_t num_epochs, bool create_intermediate_plots, std::uint32_t plot_intermediate_epochs){
    // Simuliert die angegebenen Epochen
    for (uint32_t i = 0; i < num_epochs; ++i) {
        simulate_epoch(plotter, universe, create_intermediate_plots, plot_intermediate_epochs);
    }
}




