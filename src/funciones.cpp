#include <stdio.h>
#include <vector>
#include "../include/funciones.hpp"  

vector<string> split(string str, char delimitador) {
    vector<string> result;

    stringstream ss(str);

    while (ss.good()) {
        string substr;
        getline(ss, substr, delimitador);
        result.push_back(substr);
    }

    return result;
}

vector<Carrera> generarCarreras(string datos) {
  vector<Carrera> carreras;

  ifstream entrada(datos);
  for (string linea; getline(entrada, linea);)
  {
    vector<string> arreglo = split(linea, ';');
    Carrera carrera = Carrera(stoi(arreglo.at(1)));
    if(!carrera.exist(carreras)){
      carreras.push_back(carrera);
    }else{
      continue;
    }
  }
  return carreras;
}

vector<Carrera> generarAsignaturas(string datos) {
  vector<Carrera> carreras = generarCarreras(datos);
  vector<Asignatura> asignaturas;
  ifstream entrada(datos);
  for(string linea; getline(entrada, linea);){
    vector<string> arreglo = split(linea, ';');
    Asignatura asignatura = Asignatura(stoi(arreglo.at(0)), arreglo.at(2));
    for(unsigned int i = 0; i < carreras.size(); i++){
      if(stoi(arreglo.at(1)) == carreras.at(i).codigoCarrera){
        carreras.at(i).asignaturas.push_back(asignatura);
      }
      else{
        continue;
      }
    }
  }
  return carreras;
}

vector<Aula> generarSalas(string aulas, string periodos){
  vector<Aula> ss;
  ifstream salas(aulas);
  ifstream horas(periodos);
  for(string linea; getline(salas, linea);){
      map<int, string> per;
    for(string linea2; getline(horas, linea);){
      vector<string> arreglo = split(linea, ',');
      per.insert(pair<int, string>(stoi(arreglo.at(0)), arreglo.at(1)));
    }
    Aula sala = Aula(linea, per);
    ss.push_back(sala);
  }
  return ss;

}

