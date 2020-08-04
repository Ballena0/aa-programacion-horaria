#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <string>

#include "Carrera.hpp"
#include "Asignatura.hpp"
#include "Aula.hpp"

#include "omp.h"

using namespace std;

vector<string> split(string, char);
vector<Carrera> generarCarreras(string);
vector<Carrera> generarAsignaturas(string);
vector<Aula> generarSalas(string, string);

