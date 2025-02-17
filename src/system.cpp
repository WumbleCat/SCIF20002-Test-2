#include <fstream>
#include "system.h"
#include "disk.h"

// Constructs a System with specified parameters
System::System(int N, double displacement,double radius, double boxSize, int seed) {
        this->boxSize= boxSize;
        this->  dist = std::uniform_real_distribution<double>(0, 1);
        this->displacement=displacement;
        gen = std::mt19937(seed);
        
        int nSide = static_cast<int>(boxSize/ (2*radius));
        size_t N_unsigned = static_cast<size_t>(N);  

        // disks.size returns an unsigned int while, N is a signed int
        // thus, N_size needs to converted to unsigned int for the proper comparison
        for (int i = 0; i < nSide && disks.size() < N_unsigned; ++i) {
            for (int j = 0; j < nSide && disks.size() < N_unsigned; ++j) {
                disks.push_back(Disk(i * 2*radius, j * 2*radius, radius));
            }
        }
    }   

// Checks if a disk overlaps with any other disk
bool System::overlap(int i){
    // convert signed int j to an unsigned int as well
    size_t i_unsigned = static_cast<size_t>(i); 
    for (size_t j = 0; j < disks.size(); ++j) {
        if (i_unsigned!=j && disks[i].distance(disks[j]) < (disks[i].getRadius() + disks[j].getRadius()) ) {
            return true;
        }
    }
    return false;
}

// Moves a disk in the system
void System::step() {
    for (size_t i = 0; i<disks.size(); ++i) 
    {
        int selected_disk = std::rand() % disks.size();
        double oldX = disks[selected_disk].getX();
        double oldY = disks[selected_disk].getY();
        double dx = uniform(-displacement, displacement);
        double dy = uniform(-displacement, displacement);
        this->disks[selected_disk].move(dx, dy);
        
        enforceBoundaries(disks[selected_disk]);

        if (overlap(selected_disk)){
            disks[selected_disk].setX(oldX);
            disks[selected_disk].setY(oldY);
        }
       
    }
}

// checks to see if the disks are in the boundaries
void System::enforceBoundaries(Disk & disk) {
        if (disk.getX() < 0) disk.setX(0);
        if (disk.getX() > boxSize) disk.setX(boxSize);
        if (disk.getY() < 0) disk.setY(0);
        if (disk.getY() > boxSize) disk.setY(boxSize);
    }

// Saves the current location to a file
void System::save(const std::string &filename){
    // save state of disks to file
    std::ofstream outFile(filename);
    outFile<<disks.size()<<std::endl;
    outFile<<"Comment"<<std::endl;
    for (Disk& disk : disks) {
      outFile<<"A "<<disk.getX()<<" "<<disk.getY()<<" "<<disk.getRadius()<<std::endl;
    }
    outFile.close();
    
}

// Generates a random number within range of min and max
double System::uniform(double min,double max) {
    return std::uniform_real_distribution<double>(min, max)(gen);
}