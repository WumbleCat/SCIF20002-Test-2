#include <iostream>
#include <string>
#include "system.h"

/**
 * @brief Entry point of the program.
 *
 * This function initializes the program and manages execution.
 */
int main(int argc, char* argv[]) {
    // Ensure correct number of arguments
    if (argc != 6) {
        std::cerr << "Enter your inputs (N) (Max Displacement Per Step) (Radius) (Box Size) (Number of Iterations): " 
        << argv[0] << " <N> <maxDisplacement> <dt> <L> <iterations>\n";
        return 1; // Exit with error if there are not exactly 6 arguments
    }

    int N = std::atoi(argv[1]);          // Number of disks
    double maxDisplacement = std::atof(argv[2]); // Maximum displacement per step
    double dt = std::atof(argv[3]);      // Radius
    double L = std::atof(argv[4]);       // Box size
    int iterations = std::atoi(argv[5]); // Num of iterations

    // Initialise the system
    System system(N, maxDisplacement,dt,L,1234);

    for (int i = 0; i < iterations; ++i) {
        // Move one disk
        system.step();
        // Save a configuration
        system.save("confs/conf"+std::to_string(i));
    }
    return 0;
}