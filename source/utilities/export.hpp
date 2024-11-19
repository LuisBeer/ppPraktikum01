#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector2d.h>
#include <universe.h>

static void save_universe(const std::filesystem::path& save_path, const Universe& universe){
    std::ofstream universe_file(save_path);
    if(! universe_file.is_open()){
        throw std::invalid_argument("Could not save universe to given file!");
    }
    universe_file << "# Number of bodies\n" <<universe.num_bodies << "\n";
}


