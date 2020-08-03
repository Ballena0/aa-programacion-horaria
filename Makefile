CXX = g++
CXXFLAGS = -std=c++11 -g3 -Wall -fopenmp
MKDIR = mkdir -p

LIBS = -lm

directorios: 
	$(MKDIR) build dist 

main.o: directorios main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

all: clean main.o
	$(CXX) $(CXXFLAGS) -o dist/programacion-horaria build/main.o $(LIBS)

clean: 
	rm -fr *.o a.out core dist build

.DEFAULT_GOAL := all