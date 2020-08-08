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
void escribirResultado(string rutaSalida);

int main(int argc, char **argv)
{

  auto start = chrono::system_clock::now();

  if (existeArchivo(rutaRamos) && existeArchivo(rutaSalas) && existeArchivo(rutaPeriodos))
  {
    //vector<Aula> salas = generarSalas(rutaSalas, rutaPeriodos);
    // cada Aula tiene nombreSala y periodos que es un vector donde [dia][periodo]
    vector<Aula> salas = generarSalas2(rutaSalas);
    vector<Carrera> carreras = generarAsignaturas(rutaRamos);

    // Vector que revisa cuales son las asignaturas actualmente sin aula
    //carreras.at(0).asignaturas.at(0).con_aula = true;
    //carreras.at(0).asignaturas.at(1).con_aula = true;
    vector<Asignatura> asignaturas_sin_aula = asignaturasSinAula(carreras);
    //vector<Asignatura> asignaturas_con_aula = asignaturasConAula(carreras);
    //cout << asignaturas_sin_aula.at(0).nombre <<" << "<< endl;
    //cout << asignaturas_con_aula.at(0).nombre << " <<< "<<endl;
    //cout << asignaturas_con_aula.at(1).nombre << " <<< "<<endl;

    //std::map<std::string, int> cantidades_por_asignatura = cantidadPorAsignatura(asignaturas_sin_aula);
    //for(const auto& x : cantidades_por_asignatura){
    //  std::cout << x.first << "; "<< x.second << endl; 
    //}
    //salas.at(0).utilizarHorario(asignaturas_sin_aula.at(0),1,0);
    //salas.at(1).utilizarHorario(asignaturas_sin_aula.at(0),1,0);
    //salas.at(2).utilizarHorario(asignaturas_sin_aula.at(0),1,0);
    //cout<< salas.at(0).periodos.at(1).at(0) << "ASD" << endl;
    //cout<< salas.at(1).periodos.at(1).at(0) << "ASD" << endl;
    //cout<< salas.at(1).periodos.at(1).at(0) << "ASD" << endl;
    //vector<int> aula_verificada = mismoPeriodoLibre(salas, 3);
    //std::cout << aula_verificada.at(0) << " <i  j>" << aula_verificada.at(1)<<endl;
    //salas.at(0).utilizarHorario(asignaturas_sin_aula.at(0),1,0);
    //vector<Aula> aulas_disponibles = aulasDisponibles(salas, 1, 0);
    //std::cout << salas.at(0).periodos.at(1).at(0) << "<<< "<< endl;
    //std::cout << aulas_disponibles.at(0).nombreSala << "<< "<< endl;
    //std::cout << aulas_disponibles.at(1).nombreSala << "<< "<< endl;
    //std::cout << aulas_disponibles.at(2).nombreSala << "<< "<< endl;
    //std::cout << aulas_disponibles.at(3).nombreSala << "<< "<< endl;
    //std::cout << aulas_disponibles.at(4).nombreSala << "<< "<< endl;
    //algoritmo de asignacion
    int globalCnt = 0;
    while(asignaturas_sin_aula.size()!=0){
      std::map<std::string, int> cantidades_por_asignatura = cantidadPorAsignatura(asignaturas_sin_aula);
      std::string nombre_mayor = mayorCantidadSecciones(cantidades_por_asignatura);
      vector<int> indices_mayor = indicesAsignatura(asignaturas_sin_aula,nombre_mayor);
      //cout << indices_mayor.at(0) << " " << indices_mayor.at(1) << " "<< indices_mayor.at(2)<<endl;
      vector<int> indices_celdas_verificadas = mismoPeriodoLibre(salas, indices_mayor.size());
      //cout << indices_celdas_verificadas.at(0) << " " << indices_celdas_verificadas.at(1)<<endl;
      // Agregar las asignaturas a cualquier seccion con las celdas verificadas disponibles
      //int cnt = 0;
      //  for(size_t j = 0; j < salas.size(); j++){
      //    if(cnt<indices_mayor.size()){
      //      if(salas.at(j).horarioDisponible(indices_celdas_verificadas.at(0),indices_celdas_verificadas.at(1))){
      //      salas.at(j).utilizarHorario(asignaturas_sin_aula.at(cnt),indices_celdas_verificadas.at(0),indices_celdas_verificadas.at(1));
      //      cnt++;
      //      cout << salas.at(j).periodos.at(indices_celdas_verificadas.at(0)).at(indices_celdas_verificadas.at(1))<<"LO que tiene celda" <<endl;
      //      }
      //    }else{
      //      break;
      //    }          
      //  }
      int cnt = 0;
      while(cnt< indices_mayor.size()){
        for(unsigned int i=0; i<salas.size(); i++){
          if(salas.at(i).horarioDisponible(indices_celdas_verificadas.at(0),indices_celdas_verificadas.at(1))){
            if(cnt<indices_mayor.size()){
              salas.at(i).utilizarHorario(asignaturas_sin_aula.at(indices_mayor.at(cnt)),indices_celdas_verificadas.at(0),indices_celdas_verificadas.at(1));
              cout << "Sala: " << salas.at(i).nombreSala << "  Periodos: " << indices_celdas_verificadas.at(0) << " ; " << indices_celdas_verificadas.at(1)<< endl;
              cout << "Celda: " << salas.at(i).periodos.at(indices_celdas_verificadas.at(0)).at(indices_celdas_verificadas.at(1));
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
      

      cout << "Termino de llenar una carrera" << endl;
      //cout << asignaturas_sin_aula.at(0).nombre <<endl;
      asignaturas_sin_aula = asignaturasSinAula2(asignaturas_sin_aula);
      //cout << asignaturas_sin_aula.at(0).nombre <<endl;
    }
    cout << "Conteo global de inserciones: " << globalCnt << endl;
    cout << "===== M2-201 =====" << endl;
    salas.at(0).imprimirPeriodos();
    cout << endl;
    cout << "===== M2-202 =====" << endl;
    salas.at(1).imprimirPeriodos();
    cout << endl;
    cout << "===== M2-203 =====" << endl;
    salas.at(2).imprimirPeriodos();
    cout << endl;
    cout << "===== M2-204 =====" << endl;
    salas.at(3).imprimirPeriodos();
    cout << endl;
    cout << "===== M2-205 =====" << endl;
    salas.at(4).imprimirPeriodos();

    //escribir csv
    //escribirResultado(argv[1]);

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
