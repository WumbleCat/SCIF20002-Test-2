#ifndef SYSTEM_H
#define SYSTEM_H
#include <string>
#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include "disk.h"

class System {
    public:
        double boxSize;
        std::vector<Disk> disks;  
        double displacement;      
        std::uniform_real_distribution<double> dist;  
        std::mt19937 gen;          

        System(int N, double displacement, double radius, double box_size, int seed);
        void enforceBoundaries(Disk& disk);
        bool overlap(int i);
        void save(const std::string& filename);
        void step();
        double uniform(double min, double max);
};

#endif