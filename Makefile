# test  "& fg" after ./exe in run section
# Define the C++ compiler and flags
CXX = clang++
CXXFLAGS = -std=c++20 -Wall

# Define the directory where the compiled executable will be placed
BIN_DIR = bin

# Define the path of the compiled executable
EXECUTABLE = $(BIN_DIR)/test

# Define a debug flag to be used in the "runbug" target
DEBUG_FLAG = -g
DEBUG_TUNE = -glldb

# If the user hasn't specified a source file in the FILE variable,
# default to "default.cpp"
ifndef FILE
    FILE = main.cpp
endif

# Target: "all"
# This target is executed when running "make all"
all: $(EXECUTABLE)
	@echo "Build completed: $(EXECUTABLE)"

# Target: "run"
# This target is executed when running "make run"
run: $(FILE)
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $< -o $(EXECUTABLE)
	@echo
#@gtime -v ./$(EXECUTABLE)
	@env time --format="Command '%C' ran for '%E' (%e seconds)" ./$(EXECUTABLE)
	@echo

# Target: "runbug"
# This target is executed when running "make iprunbug"
iprunbug: $(FILE)
# Create the bin directory if it doesn't exist
	mkdir -p $(BIN_DIR)
# Compile the specified source file with the --debug flag and place the executable in the bin directory
	$(CXX) $(CXXFLAGS) $(DEBUG_FLAG) $< -o $(EXECUTABLE)
	@echo
# Run the compiled executable with input from input.txt and write output to output.txt
	@echo "Running $(EXECUTABLE) with input from input.txt (debug mode)..."
	@echo
	{ time -v ./$(EXECUTABLE) < input.txt > output.txt; } 2>&1 | grep "real" > /dev/null
	@echo

# Target: "runbug"
# This target is executed when running "make runbug"
runbug: $(FILE)
# Create the bin directory if it doesn't exist
	mkdir -p $(BIN_DIR)
# Compile the specified source file with the --debug flag and place the executable in the bin directory
	$(CXX) $(CXXFLAGS) $(DEBUG_FLAG) $(DEBUG_TUNE) $< -o $(EXECUTABLE)
	@echo
# Run the compiled executable in interactive debug mode
	@echo "Running $(EXECUTABLE) in interactive debug mode..."
	@echo
	@./$(EXECUTABLE)
	@echo

# Target: "clean"
# This target is executed when running "make clean"
clean:
# Remove the compiled executable
	rm -f $(EXECUTABLE)

# Specify that these targets don't correspond to actual files
.PHONY: all run iprunbug runbug clean
