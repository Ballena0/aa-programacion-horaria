#include <iostream>
#include <string>
#include <stdio.h>
#include <chrono>
#include <fstream>
#include <vector>
#include <sstream>

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

int main(int argc, char **argv)
{

  auto start = chrono::system_clock::now();

  if (existeArchivo(rutaRamos) && existeArchivo(rutaSalas) && existeArchivo(rutaPeriodos))
  {
<<<<<<< HEAD
    vector<Aula> s = generarSalas(rutaSalas, rutaPeriodos);
    vector<Carrera> carrerasCompletas = generarAsignaturas(rutaRamos);
    cout << "carreras creadas" << endl;
    vector<Aula> salasCompletas_ = salasLlenas(s, carrerasCompletas);
    imprimirSalas(salasCompletas_);
    //algoritmo de asignacion
=======
    //vector<Aula> salas = generarSalas(rutaSalas, rutaPeriodos);
    // cada Aula tiene nombreSala y periodos que es un vector donde [dia][periodo]
    vector<Aula> salas = generarSalas(rutaSalas);
    vector<Carrera> carreras = generarAsignaturas(rutaRamos);
>>>>>>> seidev

    // Vector que revisa cuales son las asignaturas actualmente sin aula
    vector<Asignatura> asignaturas_sin_aula = asignaturasSinAula(carreras);

    // Algoritmo de asignacion
    int globalCnt = 0;
    while(asignaturas_sin_aula.size()!=0){
      std::map<std::string, int> cantidades_por_asignatura = cantidadPorAsignatura(asignaturas_sin_aula);
      std::string nombre_mayor = mayorCantidadSecciones(cantidades_por_asignatura);
      vector<int> indices_mayor = indicesAsignatura(asignaturas_sin_aula,nombre_mayor);
      vector<int> indices_celdas_verificadas = mismoPeriodoLibre(salas, indices_mayor.size());

      int cnt = 0;
      while(cnt< indices_mayor.size()){
        for(unsigned int i=0; i<salas.size(); i++){
          if(salas.at(i).horarioDisponible(indices_celdas_verificadas.at(0),indices_celdas_verificadas.at(1))){
            if(cnt<indices_mayor.size()){
              salas.at(i).utilizarHorario(asignaturas_sin_aula.at(indices_mayor.at(cnt)),indices_celdas_verificadas.at(0),indices_celdas_verificadas.at(1));
              cnt++;
              globalCnt++;
            }else{
              break;
            }            
          }else{
            continue;
          }            
        }
      }
      asignaturas_sin_aula = asignaturasSinAula2(asignaturas_sin_aula);
    }

    // DEBUGGING

    //cout << "Conteo global de inserciones: " << globalCnt << endl;
    //cout << "===== M2-201 =====" << endl;
    //salas.at(0).imprimirPeriodos();
    //cout << endl;
    //cout << "===== M2-202 =====" << endl;
    //salas.at(1).imprimirPeriodos();
    //cout << endl;
    //cout << "===== M2-203 =====" << endl;
    //salas.at(2).imprimirPeriodos();
    //cout << endl;
    //cout << "===== M2-204 =====" << endl;
    //salas.at(3).imprimirPeriodos();
    //cout << endl;
    //cout << "===== M2-205 =====" << endl;
    //salas.at(4).imprimirPeriodos();

    // Escribir csv

    for(unsigned int i=0; i<salas.size(); i++){
      generarCsv(salas.at(i));
    }

  }else{
    cout << "Archivo no existe" << endl;
    return EXIT_FAILURE;
  }

  auto end = chrono::system_clock::now();
  chrono::duration<float, milli> duration = end - start;
  cout << duration.count() << "'ms" << endl;
  participantes();

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
