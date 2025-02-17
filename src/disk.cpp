#include "disk.h"
#include <cmath>

Disk::Disk(double x, double y, double r){
    this->x = x;
    this->y = y;
    this->radius = r;
}

void Disk::move(double dx, double dy){
    this->x += dx;
    this->y += dy;
}

double Disk::distance(Disk& other){

    // Calculate the Euclidean distance
    // The formula is sqrt of [(x1 - x2)^2 + (y1 - y2)^2]

    double diff_x_squared = pow(this->x - other.x, 2);
    double diff_y_squared = pow(this->y - other.y, 2);
    return std::sqrt(diff_x_squared + diff_y_squared);

}