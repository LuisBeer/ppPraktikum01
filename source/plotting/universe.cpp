#include "plotting/plotter.h"
void Plotter::add_bodies_to_image(Universe& universe){
    for(int i = 0; i < universe.num_bodies; i++){
        Vector2d<double> position = universe.positions[i];
        //Cheecken ob die Position im PLot liegt
        if (position[0] >= plot_bounding_box.x_min && position[0] <= plot_bounding_box.x_max &&
                position[1] >= plot_bounding_box.y_min && position[1] <= plot_bounding_box.y_max) {
            //Umrechnung der Position im Universum in Pixelkoordinaten
            double scale_x = static_cast<double>(plot_width) / (plot_bounding_box.x_max - plot_bounding_box.x_min);
            double scale_y = static_cast<double>(plot_height) / (plot_bounding_box.y_max - plot_bounding_box.y_min);
            std::uint32_t x = static_cast<std::uint32_t>((position[0] - plot_bounding_box.x_min) * scale_x);
            std::uint32_t y = static_cast<std::uint32_t>((position[1] - plot_bounding_box.y_min) * scale_y);

            // Pixel markieren
            mark_pixel(x, y, 255, 255, 255);
        }
    }
}

void Plotter::highlight_position(Vector2d<double> position, std::uint8_t red, std::uint8_t green, std::uint8_t blue) {
    //Cheecken ob die Position im Bild liegt
    if (position[0] < plot_bounding_box.x_min || position[0] > plot_bounding_box.x_max ||
          position[1] < plot_bounding_box.y_min || position[1] > plot_bounding_box.y_max) {
        return; // Keine Änderung am Bild
          }
    //Umrechnung der Position im Universum in Pixelkoordinaten
    double scale_x = static_cast<double>(plot_width) / (plot_bounding_box.x_max - plot_bounding_box.x_min);
    double scale_y = static_cast<double>(plot_height) / (plot_bounding_box.y_max - plot_bounding_box.y_min);
    std::uint32_t x = static_cast<std::uint32_t>((position[0] - plot_bounding_box.x_min) * scale_x);
    std::uint32_t y = static_cast<std::uint32_t>((position[1]- plot_bounding_box.y_min) * scale_y);

    //Kreuz malen
    //Horizontale Linie
    for (int dx = -5; dx <= 5; ++dx) {
        if (x + dx < plot_width && x + dx >= 0) {
            mark_pixel(x + dx, y, red, green, blue);
        }
    }
    //Vertikale Linie
    for (int dy = -5; dy <= 5; ++dy) {
        if (y + dy < plot_height && y + dy >= 0) {
            mark_pixel(x, y + dy, red, green, blue);
        }
    }
}