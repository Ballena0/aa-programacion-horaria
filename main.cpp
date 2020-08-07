#include <iostream>
#include <string>
#include <stdio.h>
#include <chrono>
#include <fstream>
#include <vector>

#include "include/Asignatura.hpp"
#include "include/Aula.hpp"
#include "include/Carrera.hpp"
#include "include/funciones.hpp"

using namespace std;

#define rutaRamos "data/ramos.csv"
#define rutaSalas "data/salas.txt"
#define rutaPeriodos "data/periodos.txt"
#define dias "Período, Lunes , Martes, Miércoles, Jueves, Viernes"
#define cantidad_dias 5

/**
 * Taller computacional
 * @param argc cantidad de argumentos
 * @param argv argumentos
 * @return El código de salida del programa
 */

void participantes();
bool existeArchivo(string ruta);
void escribirResultado(string rutaSalida);

int main(int argc, char **argv)
{

  auto start = chrono::system_clock::now();

  if (existeArchivo(rutaRamos))
  {
    vector<Aula> salas = generarSalas(rutaSalas, rutaPeriodos);
    vector<Carrera> carrerasCompletas = generarAsignaturas(rutaRamos);
    //algoritmo de asignacion

    //escribir csv
    escribirResultado(argv[1]);

  }else{
    cout << "Archivo no existe" << endl;
    return EXIT_FAILURE;
  }

  auto end = chrono::system_clock::now();
  chrono::duration<float, milli> duration = end - start;
  cout << duration.count() << "'ms" << endl;

  return EXIT_SUCCESS;
}

void participantes()
{
  cout << endl
       << "=== PRUEBA 3 ===" << endl;
  cout << "Sebastián Albornoz" << endl;
  cout << "Sebastián Santelices" << endl;
  cout << "Jorge Verdugo" << endl;
}

bool existeArchivo(string ruta)
{
  ifstream f(ruta.c_str());
  return f.good();
}

void escribirResultado(string rutaSalida)
{
  string archivo = rutaSalida + "horario.csv";
  ofstream salida(archivo, fstream::app);
  salida << dias << endl;
  //periodo, 1l, 1m, 1mi, 1j, 1v ...
}
