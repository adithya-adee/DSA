# Compiler and flags
CXX = g++
CXXFLAGS = -g -Wall -std=c++17

# The name of your final executable
TARGET = main

# List all the .cpp source files your program needs
SRCS = main.cpp \
       sorting_algorithms/bubble_sort.cpp	\
       sorting_algorithms/insertion_sort.cpp\
       sorting_algorithms/selection_sort.cpp\
       sorting_algorithms/merge_sort.cpp\
       sorting_algorithms/quick_sort.cpp\

# Default rule, executed when you just type "make"
all: $(TARGET)

# Rule to build the target executable
# This compiles and links all source files in a single command.
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Rule to run the program
run: all
	./$(TARGET)

# Rule to clean up compiled files
clean:
	rm -f $(TARGET)
