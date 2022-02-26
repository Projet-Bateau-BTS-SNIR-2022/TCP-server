# the compiler: define as g++ for C++
COMPILTATEUR = g++

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
  #  -O    optimizes the program for speed
  #  -o    specifies the name of the executable file
FLAGS = -g -Wall -O -o
#program name
PROGRAM_FINAL_MAIN = tcp_server

build: 
	$(COMPILTATEUR) $(FLAGS) $(PROGRAM_FINAL_MAIN) main.cpp

launch:
	./$(PROGRAM_FINAL_MAIN)