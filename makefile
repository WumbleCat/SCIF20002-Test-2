# Set compiler to g++, obviously
CXX = g++

# Set compiler flags
# -std=c++17 sets the C++ version
# -Wall enables warnings to catch potential issues
# -Iinclude ensures the compiler looks in the include/ directory
# -O3 enables optimisations (loop unrolling, vectorisation, etc.)
# -march=native optimises the program for the specific CPU
# -flto enables link-time optimisation
CXXFLAGS = -std=c++11 -Wall -Iinclude -O3 -march=native -flto 

# Set directory names
SRC_DIR = src
OBJ_DIR = build
CONF_DIR = confs
BIN_DIR = bin

# Find source files in src/ folder
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# Set executable name to main
TARGET = $(BIN_DIR)/main

# Set the default build rule (basically g++ <cpp files> -o <exe files>)
all: $(TARGET)

# Set the rule to compile and link with previously defined directories
$(TARGET): $(OBJ_DIR) $(CONF_DIR) $(OBJECTS)
	@mkdir -p $(BIN_DIR)  # Ensure bin/ exists
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Check to see if the build directory exists and creates build directory if it doesn't exist
$(OBJ_DIR):
	# mkdir = creates a directory
	@mkdir -p $(OBJ_DIR)  

# Check to see if confs directory exists and creates confs directory if it doesn't exist
$(CONF_DIR):
	@mkdir -p $(CONF_DIR) 

# Set rule to compile .cpp files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Set cleaning rule (For both Windows & Linux)
clean:
	# rm = remove
	# -r = deletes directories and its contents
	# 2> /dev/null = just prevents errors from being displayed
	# || true = makes sure that if the directories don't exist, the command will still go through
	@rm -r $(OBJ_DIR) $(BIN_DIR) 2> /dev/null || true 
	@rm -f $(CONF_DIR)/* 2> /dev/null || true  