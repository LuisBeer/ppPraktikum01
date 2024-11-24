#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <structures/vector2d.h>
#include <structures/universe.h>

static void save_universe(const std::filesystem::path& save_universe_path, const Universe& universe) {
    // Öffnen der Ausgabedatei
    std::ofstream universe_file(save_universe_path);

    if (!universe_file.is_open()) {
        throw std::invalid_argument("Could not save universe to the given file!");
    }

    // Setzen der Präzision für double-Werte
    universe_file << std::fixed << std::setprecision(6);

    // Schreiben der Anzahl der Himmelskörper
    universe_file << "### Bodies\n";
    universe_file << universe.num_bodies << '\n';

    // Schreiben der Positionen
    universe_file << "### Positions\n";
    for (const auto& position : universe.positions) {
        universe_file << position[0] << " " << position[1] << '\n';
    }

    // Schreiben der Gewichte
    universe_file << "### Weights\n";
    for (const auto& weight : universe.weights) {
        universe_file << weight << '\n';
    }

    // Schreiben der Geschwindigkeiten
    universe_file << "### Velocities\n";
    for (const auto& velocity : universe.velocities) {
        universe_file << velocity[0] << " " << velocity[1] << '\n';
    }

    // Schreiben der Kräfte
    universe_file << "### Forces\n";
    for (const auto& force : universe.forces) {
        universe_file << force[0] << " " << force[1] << '\n';
    }

    // Schließen der Datei
    universe_file.close();
}


/*
static void save_universe(const std::filesystem::path& save_path, const Universe& universe){
    std::ofstream universe_file(save_path);
    if(! universe_file.is_open()){
        throw std::invalid_argument("Could not save universe to given file!");
    }
    universe_file << "# Number of bodies\n" <<universe.num_bodies << "\n";
}
*/
