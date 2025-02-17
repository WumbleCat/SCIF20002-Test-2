#include "disk.h"
#include <cmath>

// Constructs a Disk object with a specified position and radius parameters
Disk::Disk(double x, double y, double r){
    this->x = x;
    this->y = y;
    this->radius = r;
}

// Moves the disk by a given distance in x and y directions
void Disk::move(double dx, double dy){
    this->x += dx;
    this->y += dy;
}

// Computes the Euclidean distance between this disk and another
double Disk::distance(Disk& other){
    double diff_x_squared = pow(this->x - other.x, 2);
    double diff_y_squared = pow(this->y - other.y, 2);
    return std::sqrt(diff_x_squared + diff_y_squared);
}

// Getter functions for private attributes.
double Disk::getX(){ 
    return x; 
}
double Disk::getY(){ 
    return y; 
}
double Disk::getRadius(){ 
    return radius; 
}

// Setter functions for private attributes.
void Disk::setX(double newX){ 
    x = newX; 
}
void Disk::setY(double newY) { 
    y = newY; 
}
void Disk::setRadius(double newRadius) { 
    radius = newRadius; 
}