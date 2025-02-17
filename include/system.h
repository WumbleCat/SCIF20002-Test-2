#ifndef SYSTEM_H
#define SYSTEM_H
#include <string>
#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include "disk.h"

class System {
    private:
        std::vector<Disk> disks;  // Vector to store all the disks
        double boxSize;           // Size of the box in the simulation
        double displacement;      // Maximum displacement per step
        std::mt19937 gen;         // Random number generator
        std::uniform_real_distribution<double> dist; // Uniform distribution for randomness

    public:  
        /**
         * @brief Constructs a System with specified parameters
         * @param N Number of disks
         * @param displacement Maximum displacement per step
         * @param radius Radius of each disk
         * @param boxSize Size of the box in the simulation
         * @param seed Random seed for reproducibility
         */
        System(int N, double displacement, double radius, double boxSize, int seed);

        /**
         * @brief checks to see if the disks are in the boundaries
         * @param disk (passed by reference) the disk that needs to be adjusted
         */
        void enforceBoundaries(Disk& disk);

        /**
         * @brief Checks if a disk overlaps with any other disk
         * @param i Index of the disk to check
         * @return Returns True if the disk overlaps, False if there is no overlap
         */
        bool overlap(int i);

        /**
         * @brief Saves the current location to a file
         * @param filename Name of the file
         */
        void save(const std::string& filename);

        /**
         * @brief Moves a disk in the system
         */
        void step();

        /**
         * @brief Generates a random number within range of min and max
         * @param min Minimum value
         * @param max Maximum value
         * @return A random value within the specified range
         */
        double uniform(double min, double max);
};

#endif