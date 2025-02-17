# Set compiler to g++, obviously
CXX = g++

# Set compiler flags
# -std=c++17 sets the C++ version
# -Wall enables warnings to catch potential issues
# -Iinclude ensures the compiler looks in the include/ directory
# -O3 enables optimisations (loop unrolling, vectorisation, etc.)
# -march=native optimises the program for the specific CPU
# -flto enables link-time optimisation
CXXFLAGS = -std=c++11 -Wall -Iinclude -O3 -march=native -flto -fno-strict-aliasing


# Set directory names
SRC_DIR = src
OBJ_DIR = build
CONF_DIR = confs
BIN_DIR = bin

# Find source files in src/
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# Set executable name
TARGET = $(BIN_DIR)/main

# Set the default build rule
all: $(TARGET)

# Set the rule to compile and link
$(TARGET): $(OBJ_DIR) $(CONF_DIR) $(OBJECTS)
	@mkdir -p $(BIN_DIR) 2> NUL || true  # Ensure bin/ exists (Windows/Linux)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Check to see if the build directory exists
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR) 2> NUL || true  # Windows/Linux safe

# Check to see if confs directory exists
$(CONF_DIR):
	@mkdir -p $(CONF_DIR) 2> NUL || true  # Windows/Linux safe

# Set rule to compile .cpp files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Set cleaning rule (For both Windows & Linux)
clean:
	@rm -rf $(OBJ_DIR) $(BIN_DIR) 2> NUL || rmdir /S /Q $(OBJ_DIR) 2> NUL
	@rm -f $(CONF_DIR)/* 2> NUL || del /S /Q $(CONF_DIR)\* 2> NUL
