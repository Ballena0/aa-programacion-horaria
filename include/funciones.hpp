#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <stdio.h>

#include "Carrera.hpp"
#include "Asignatura.hpp"
#include "Aula.hpp"

#include "omp.h"

using namespace std;

vector<string> split(string, char);
vector<Carrera> generarCarreras(string);    
vector<Carrera> generarAsignaturas(string);
vector<Aula> generarSalas(string);
vector<Asignatura> asignaturasSinAula(std::vector<Carrera>);
vector<Asignatura> asignaturasSinAula2(std::vector<Asignatura>);
vector<Asignatura> asignaturasConAula(std::vector<Carrera>);
std::map<std::string, int> cantidadPorAsignatura(std::vector<Asignatura>);
vector<Aula> aulasDisponibles(vector<Aula>, int, int);
vector<int> mismoPeriodoLibre(vector<Aula>, int);
std::string mayorCantidadSecciones(std::map<std::string, int>);
vector<int> indicesAsignatura(vector<Asignatura> ,std::string );
void generarCsv(Aula);