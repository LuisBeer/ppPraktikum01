#pragma once
#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

#include <atomic>
#include <string>

#include "vector2d.h"
#include <cstdint>
#include <iostream>

class BoundingBox{
    //Felder definierencd
    public:
        double x_min;
        double y_min;
        double x_max;
        double y_max;

    //Methoden aus bounding_box.cpp holen (Rückgabe und Name)
    std::string get_string();
    double get_diagonal();
    void plotting_sanity_check();
    BoundingBox get_scaled(std::uint32_t scaling_factor);

    bool contains(const Vector2d<double>& position) const {
        // Überprüfung der X- und Y-Koordinaten
        bool in_x_range = (x_min <= position[0] && position[0] <= x_max) ||
                          (x_max <= position[0] && position[0] <= x_min);

        bool in_y_range = (y_min <= position[1] && position[1] <= y_max) ||
                          (y_max <= position[1] && position[1] <= y_min);

        // Position ist innerhalb, wenn beide Bedingungen erfüllt sind
        return in_x_range && in_y_range;
    }

    BoundingBox get_quadrant (std::uint8_t indexquadrant) { //bekommt den index eines Quadranten als std::uint8_t und gibt den entsprechenden Quadranten als Objekt zurück
        if (indexquadrant > 3 || indexquadrant < 0) { //es gibt nur 4 Quadranten: 0, 1, 2 und 3
            throw std::out_of_range("Invalid quadrant index");
        }
        //Grenzen bzw Mitten der Quadranten berchnen
        double x_middle = (x_min + x_max) / 2;
        double y_middle = (y_min + y_max) / 2;
        switch (indexquadrant) {
            case 0: //Quadrant oben links
                return BoundingBox(x_min, y_middle, x_middle, y_max);
            case 1: //Quadrant oben rechts
                return BoundingBox(x_middle, y_middle, x_max, y_max);
            case 2: //Quadrant unten links
                return BoundingBox(x_min, y_min, x_middle, y_middle);
            case 3: // Quadran unten rechts
                return BoundingBox(x_middle, y_min, x_max, y_middle);
            default:  throw std::logic_error("Unexpected quadrant index");
        }
    }

public:
    BoundingBox(); //Standardkonstruktor
    BoundingBox(double xmingiven, double ymingiven, double xmaxgiven, double ymaxgiven) :
        /*x_min(std::min(xmingiven,xmaxgiven)),
        y_min(std::min(ymingiven,ymaxgiven)),
        x_max(std::max(xmingiven,xmaxgiven)),
        y_max(std::max(ymingiven,ymaxgiven))*/
        x_min(xmingiven), y_min(ymingiven), x_max(xmaxgiven), y_max(ymaxgiven){}

};
#endif