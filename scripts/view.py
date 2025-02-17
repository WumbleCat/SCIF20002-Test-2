import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import glob
from matplotlib.patches import Circle
import os

# # Get all configurations from the confs folder
# files = glob.glob("../confs/c*")
# # sort them in ascending order
# filenames = sorted(files, key=lambda x: int(x.split("\conf")[1]))
# the lines above here have to be tinkered with since ipynb files handle paths differently from py files
# its usually better to just locate the path and "add" it to your directory (more explained below)

# Get the directory where the script is located (current directory)
script_dir = os.path.dirname(os.path.abspath(__file__))

# Build the absolute path to the confs folder (this assumes confs is one level up from scripts)
confs_dir = os.path.join(script_dir, "..", "confs")

# Use the absolute path in glob instead
files = glob.glob(os.path.join(confs_dir, "conf*"))

# Now run the original code given below

filenames = sorted(files, key=lambda x: int(os.path.basename(x)[len("conf"):]))

# Create a new figure
fig, ax = plt.subplots()
ax.set(xlim=(0, 20), ylim=(0, 20), aspect='equal')

# List to hold the circle patches (assume number of circles remains constant)
circles = []

# Initialize the first frame
data = np.loadtxt(filenames[0], skiprows=2, usecols=[1,2,3])
for x, y, r in data:
    circle = Circle((x, y), r, edgecolor='b', facecolor='none')
    circles.append(circle)
    ax.add_patch(circle)

# Reccurent update of the figure 
def update(frame):
    # Load new data for the frame
    data = np.loadtxt(filenames[frame], skiprows=2, usecols=[1,2,3])
    for patch, (x, y, r) in zip(circles, data):
        # Update circle position and radius
        patch.center = (x, y)
        patch.set_radius(r)
    return circles

ani = FuncAnimation(fig, update, frames=len(filenames), blit=True, interval=200)

# Define the output directory path like previously done and make sure it exists
output_dir = os.path.join(script_dir, "..", "output")
os.makedirs(output_dir, exist_ok=True)

# Save animation inside the output directory
gif_path = os.path.join(output_dir, "animation.gif")
ani.save(gif_path, writer="pillow")

plt.show()
