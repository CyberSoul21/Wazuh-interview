#Makefile to compile and execute Monty hall simulation in c++
# (c) Wilson Almario <wilson.jar21@gmail.com>

#GCC = /usr/bin/g++


# Define compiler and compiler flags
CXX = g++-11
CXXFLAGS = -I../include  -pthread # Add -I to include path
LDFLAGS = -pthread  # Add -pthread here for linking

# Define the source files and object files
SRC = main.cpp monty_hall.cpp
OBJ = $(SRC:.cpp=.o)

# Define the name of the final executable and the output folder
EXEC = monty_hall_game

help:
	@echo "************************************************"
	@echo "Compile source files: "
	@echo ">make all"
	@echo "------------------------------------------------"
	@echo "Delete all generated files"
	@echo ">make clean"
	@echo "------------------------------------------------"
	@echo "Run ther executable with arguments, example:"
	@echo ">make run ARGS=\"stay 100\""
	@echo "Flags first argument:"
	@echo "-stay:   run only stay strategy "
	@echo "-switch: run only switch strategy "
	@echo "-both:   run both strategies "
	@echo "Second argument:"
	@echo "-Number of simulation to run for each strategy"
	@echo "------------------------------------------------"

# Default rule to build the executable
all:$(EXEC)

# Rule to link object files into an executable
# Use LDFLAGS for linking
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC) $(LDFLAGS)  

	@echo "Done"
# Clean up generated files (object files and executable)
clean:
	rm -f $(OBJ) $(EXEC)
	@echo "Clean complete"	

# Run the executable with passed arguments (optional)
run: $(EXEC)
	@echo "Running the program with arguments: $(ARGS)"
	./$(EXEC) $(ARGS)	