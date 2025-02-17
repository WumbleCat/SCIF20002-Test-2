import subprocess
import os
import glob

# create the class for the simulation
class DiskSimulation:
    # initialize the object like how you'd call the exe file (like ./main <> <> <> <> <>) accurately
    def __init__(self, N, displacement, radius, box_size, iterations, bin_dir="../bin"):
        # connect the current working directory with the bin file 
        script_dir = os.path.dirname(os.path.abspath(__file__))
        self.executable = os.path.join(script_dir, "..", "bin", "main.exe")

        # initialize attributes
        self.N = N
        self.displacement = displacement
        self.radius = radius
        self.box_size = box_size
        self.iterations = iterations

    # run the exe file with the specified variables
    def run(self):
        command = [
            self.executable,
            str(self.N),
            str(self.displacement),
            str(self.radius),
            str(self.box_size),
            str(self.iterations)
        ]
        result = subprocess.run(command, capture_output=True, text=True)

        return result.stdout

simulation = DiskSimulation(20, 0.6, 0.5, 20, 100)
output = simulation.run()