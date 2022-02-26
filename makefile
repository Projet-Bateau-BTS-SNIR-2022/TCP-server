# the compiler: define as g++ for C++
COMPILTATEUR = g++

	# compiler flags:
	#  -g    adds debugging information to the executable file
	#  -Wall turns on most, but not all, compiler warnings
	#  -O    optimizes the program for speed
	#  -o    specifies the name of the executable file
FLAGS_COMPILE = -g -Wall -O -c
FLAGS_NAME = -o
#program name
PROGRAM_FINAL_MAIN = tcp_server
all:
	make clean
	make compile
	make linking
	make run
	
linking:
	@echo "Assembling all the files..."
	@$(COMPILTATEUR) *.o $(FLAGS_NAME) $(PROGRAM_FINAL_MAIN)

compile: 
	@echo "Compiling  all .Cpp files to.o"
	@$(COMPILTATEUR) $(FLAGS_COMPILE) *.cpp
	

run:
	@./$(PROGRAM_FINAL_MAIN)

clean:
	@echo "Removing all the files with .o extension and the executable file"
	@rm -f *.o $(PROGRAM_FINAL_MAIN)