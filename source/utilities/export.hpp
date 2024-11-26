#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <structures/vector2d.h>
#include <structures/universe.h>



static void save_universe(const std::filesystem::path& save_path, const Universe& universe){
    std::ofstream universe_file(save_path);
    if(! universe_file.is_open()){
        throw std::invalid_argument("Could not save universe to given file!");
    }

    //Double werte auf 6 nachkommastellen runden
    universe_file << std::fixed << std::setprecision(6);


    //Anzahl der Körper
    universe_file << "###Bodies\n" << universe.num_bodies <<"\n";
    // Speichern der Positionen
    universe_file << "###Positions\n";
    for (const auto& position : universe.positions) {
        universe_file << position[0] << " " << position[1] <<"\n";
    }
    // Speichern der Gewichte
    universe_file << "###Weights\n";
    for (const auto& weight : universe.weights) {
        universe_file << weight <<"\n";
    }
    // Speichern der Geschwindigkeiten
    universe_file << "###Velocities\n";
    for (const auto& velocity : universe.velocities) {
        universe_file << velocity[0] << " " << velocity[1] <<"\n";
    }
    // Speichern der Kräfte
    universe_file << "###Forces\n";
    for (const auto& force : universe.forces) {
        universe_file << force[0] << " " << force[1] <<"\n";
    }
    universe_file.close();


}

