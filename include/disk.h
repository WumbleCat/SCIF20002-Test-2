#ifndef DISK_H
#define DISK_H

/**
 * @brief This represents a moving disk in the simulation.
 */
class Disk {
    private:
        double x;  // x position of the disk
        double y;   // y position of the disk
        double radius;    // radius position of the disk
    
    public:
        // Disk object constructor
        Disk(double x, double y, double r);

        /**
         * @brief Moves the disk by a given distance in x and y directions
         * @param dx reprsents change in x position
         * @param dy reprsents change in y position
         */
        void move(double dx, double dy);

        /**
         * @brief Computes the Euclidean distance between this disk and another
         * The formula is sqrt of [(x1 - x2)^2 + (y1 - y2)^2]
         * @param other Pass by reference to another Disk object
         * @return The Euclidean distance between the two disks
         */
        double distance(Disk &d);   

        // Getter functions for private variables
        double getX();
        double getY();
        double getRadius();

        // Setter functions
        void setX(double newX);
        void setY(double newY);
        void setRadius(double newRadius);
};

#endif