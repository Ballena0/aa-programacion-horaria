CXX = g++
CXXFLAGS = -std=c++11 -g3 -Wall
MKDIR = mkdir -p

LIBS = -lm

directorios: 
	$(MKDIR) build dist 

Carrera.o: directorios src/Carrera.cpp include/Carrera.hpp
	$(CXX) $(CXXFLAGS) -c src/Carrera.cpp -o build/Carrera.o

Aula.o: directorios src/Aula.cpp include/Aula.hpp
	$(CXX) $(CXXFLAGS) -c src/Aula.cpp -o build/Aula.o

Asignatura.o: directorios src/Asignatura.cpp include/Asignatura.hpp
	$(CXX) $(CXXFLAGS) -c src/Asignatura.cpp -o build/Asignatura.o

funciones.o: directorios src/funciones.cpp include/funciones.hpp
	$(CXX) $(CXXFLAGS) -c src/funciones.cpp -o build/funciones.o

main.o: directorios main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

all: clean main.o Carrera.o Aula.o funciones.o Asignatura.o
	$(CXX) $(CXXFLAGS) -o dist/programacion-horaria build/main.o build/Carrera.o build/Aula.o build/funciones.o build/Asignatura.o $(LIBS)
	rm -rf build

clean: 
	rm -fr *.o a.out core dist build

.DEFAULT_GOAL := all