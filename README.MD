# Programming and Data Analysis for Scientists Test 2

##  Table of Contents
- [Outline](#brief-outline)
- [Installation](#installation)
- [Modifications & Reconstruction](#modifications--reconstruction)
- [Project Structure](#project-structure)
- [Usage](#usage)
- [References](#References)



## Brief Outline
This project from my coursework simulates the **random motion of hard disks** inside a box. Each single disk will move randomly, but they cannot overlap with eaech other. The goal of this project was to **restore** the broken C++ code and header files using the provided `refman.pdf` and implement any parts that were missing.

---

## Installation
1. Clone the repository:
```bash
 git clone https://github.com/WumbleCat/SCIF20002-Test-2.git
```

2. Install dependencies:
```bash
 pip install numpy matplotlib
 ```

## **Modifications & Reconstruction**
Since the original code was both corrupted and missing, theses changes were made:

### **Reconstructed Header Files (`disk.h` and `system.h`)**
- Created class attributes and functions according to instructions on `refman.pdf`

### **Fixed Missing C++ Implementations (`disk.cpp`, `system.cpp`)**
- Created **Disk** and **System** class and restored its functions
- Implemented encapsulation by adding private attributes and setter/getter functions

### **Compiled and Tested the Program**
- Created a **Makefile** to compile the program in one command (`mingw32-make`)
- Tested to see that the program outputted the correct code (each conf file was different and random)
- Fixed the view python files (`/scripts/view.py` and `/scripts/view.ipynb`) to get correct file path
- Created a python wrapper to easily run the executable with the specified parameters in the file (`/scripts/wrapper.py`)

### **Git Version Control**
- Created git repository and push to github
- Created at least 5 commits 
- Created branches to track feature implementation
- Used .gitignore to exclude directories like
    - `confs/` (simulation outputs)
    - `bin/` (compiled executables)
---

## **Project Structure**
```bash
project_root/
│── bin/     # contains the executable file
│── confs/     # stores the x and y position of each disk
│── output/     # stores the generated gif that represents the simulation
│── scripts/     # contains the Python files used for execution and visualization 
│   ├── wrapper.py
│   ├── view.py
│   ├── view.ipynb
│── src/     # stores all the cpp source files that gets compiled 
│   ├── disk.cpp
│   ├── main.cpp
│   ├── system.cpp
│── include/     # stores all the C++ source files that get compiled
│   ├── disk.h
│   ├── system.h
│── makefile     #contains the instructions for compiling the program
│── README.md
│── refman.pdf
│── .gitignore   # lists all the files and directories that should not be committed to the repository
```
- `bin/` contains the executable file
- `confs/` stores the x and y position of each disk
- `output/` stores the generated gif that represents the simulation
- `scripts/` contains the Python files used for execution and visualization 
- `src/` stores all the cpp source files that gets compiled 
- `include/` stores all the C++ source files that get compiled
- `makefile` contains the instructions for compiling the program
- `.gitignore` lists all the files and directories that should not be committed to the repository

Separate branches were created to test out new feautres before adding them to the master branch. This was to ensure that if there is an error, people can just go to the previous commit. 
- The `create/` part of the branches specifiy the intial addition in its most basic form with no advanced features
- Used for the initial creation of the `disk`, `system`, and `Makefile`
- The `modify/` part of the branches specifies the addition of further improvements to a current feature. This helps with organizing the structure of the codebase and upgrades usability (encapsulation)

There are a total of 4 tags. One for each major upgrade from the previous 
- v0.1 is the intial file that was provided 
- v0.2 is the first working version, with basic features
- v0.3 introduces encapsulation and better code structure with comments
- v0.4 adds supporting files to help with compilation and execution of the program like the `wrapper.py` and `makefile`
- v1.0 is the final working project file with 
    - In-depth documentation
    - Encapsulation
    - Python wrapping for easy execution
    - Makefile for easy compilation
- v1.1 added references in the bottom of the 

## Usage
### **Compile and Running the Code**
1. Run the following command to **compile** the C++ program:
```bash
mingw32-make
```
#### **It does not have to be `mingw32-make`, it depends on what you set your `make` command as**

2. After compiling the program, run the generated executable file in (`/scripts/wrapper.py`) and specify your desired parameters. This will generate the confs files that contains all the information of all the particles

3. After generating the confs files, run (`/scripts/view.py`) in order to generate the simulation of the disks and save it as a gif.


Or in **step 2** if you want to run it manually without using a wrapper, you can use
```bash
bin/main <N> <maxDisplacement> <radius> <boxSize> <iterations>
```

for example
```bash
bin/main 20 0.6 0.5 20 100
```

To have a hard reset and clean everything, run the command
```bash
mingw32-make clean
```
This will clear all confs files, output folder (for gif), and object folder(for c++ objects).

### **Instructions for Navigating the Commits and Tags**

1. How to Checkout a Branch 

To see all available branches:
```bash
git branch -a
```

To switch to a different branch:
```bash
git checkout <branch_name>
```

for example
```bash
git checkout modify/encapsulate-system
```


2. How to Checkout a Tag
To list all available tags:
```bash
git tag
```

To checkout to a specific tag:
```bash
git checkout <name of tag>
```

for example,
```bash
git checkout v0.4
```


## References
List of useful references that helped me with this project:

- **Python Subprocess Module** – [DataCamp: Python Subprocess](https://www.datacamp.com/tutorial/python-subprocess)  

- **C++ Project Structure** –  [Medium: C++ Application Development - Project Structure](https://medium.com/heuristics/c-application-development-part-1-project-structure-454b00f9eddc)  

- **Encapsulation in C++** – [W3Schools: C++ Encapsulation](https://www.w3schools.com/cpp/cpp_encapsulation.asp)  

- **How to Write a Good README** – https://www.makeareadme.com/