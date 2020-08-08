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
    string carrera_ = arreglo[1].substr(1, arreglo[1].size()-1);
    int codigoCarrera = stoi(carrera_);
    Carrera carrera = Carrera(codigoCarrera);
    if(!carrera.exist(carreras)){
      carreras.push_back(carrera);
    }else{
      continue;
    }
  }
  cout << "carreras creadas" << endl;
  return carreras;
}

vector<Carrera> generarAsignaturas(string datos) {
  ifstream entrada(datos);

  vector<Carrera> carreras = generarCarreras(datos);
  vector<Asignatura> asignaturas;
  for(string linea; getline(entrada, linea);){
    vector<string> arreglo = split(linea, ';');
    int nivel = stoi(arreglo[0].substr(1, arreglo[0].size()-1));
    int codigo = stoi(arreglo[1].substr(1, arreglo[1].size()-1));
    Asignatura asignatura = Asignatura(nivel, arreglo.at(2),codigo);
    for(unsigned int i = 0; i < carreras.size(); i++){
      if(codigo == carreras.at(i).codigoCarrera){
        carreras.at(i).asignaturas.push_back(asignatura);
      }
      else{
        continue;
      }
    }
  }
  return carreras;
}

//vector<Aula> generarSalas(string aulas, string periodos){
//  vector<Aula> ss;
//  ifstream salas(aulas);
//  ifstream horas(periodos);
//  int cont=0;
//  for(string linea; getline(salas, linea);){
//      map<int, string> per;
//    for(string linea2; getline(horas, linea2);){
//      vector<string> arreglo = split(linea2, ',');
//      int periodo = stoi(arreglo[0]);
//      per.insert(pair<int, string>(periodo, arreglo.at(1)));
//    }
//    cont++;
//    horas.clear();
//    horas.seekg(0);
//    Aula sala = Aula(linea, per);
//    ss.push_back(sala);
//  }
//  return ss;
//
//}

vector<Aula> generarSalas2(string aulas){
  vector<Aula> ss;
  ifstream salas(aulas);
  for(string linea; getline(salas, linea);){
    vector<vector<string>> per(6,vector<string>(8));
    for(int i = 0; i < 6; i++){
      for(int j = 0;j<8;j++){
        if(i==0){
          per[i][j] = std::to_string(j+1);
        }else{
          per[i][j] = "";
        }
      }
    }
    Aula sala = Aula(linea, per);
    ss.push_back(sala);
  }
  return ss;

}

vector<Asignatura> asignaturasSinAula(std::vector<Carrera> carreras){
  vector<Asignatura> asignaturas_sin_aula;
  for(std::size_t i = 0; i < carreras.size();i++){
    for(std::size_t j = 0; j < carreras.at(i).asignaturas.size();j++){
      if(!carreras.at(i).asignaturas.at(j).con_aula){
        asignaturas_sin_aula.push_back(carreras.at(i).asignaturas.at(j));
      }
    }
  }
  return asignaturas_sin_aula;
}

vector<Asignatura> asignaturasSinAula2(std::vector<Asignatura> asignaturas){
  vector<Asignatura> asignaturas_sin_aula;
  for(size_t i = 0; i<asignaturas.size();i++){
    if(!asignaturas.at(i).con_aula){
      asignaturas_sin_aula.push_back(asignaturas.at(i));
    }
  }
  return asignaturas_sin_aula;
}

vector<Asignatura> asignaturasConAula(std::vector<Carrera> carreras){
  vector<Asignatura> asignaturas_sin_aula;
  for(std::size_t i = 0; i < carreras.size();i++){
    for(std::size_t j = 0; j < carreras.at(i).asignaturas.size();j++){
      if(carreras.at(i).asignaturas.at(j).con_aula){
        asignaturas_sin_aula.push_back(carreras.at(i).asignaturas.at(j));
      }
    }
}
return asignaturas_sin_aula;
}

std::map<std::string, int> cantidadPorAsignatura(std::vector<Asignatura> _asignaturas){
  std::vector<string> asignaturas;
  for(std::size_t i = 0; i<_asignaturas.size();i++){
    asignaturas.push_back(_asignaturas.at(i).nombre);
  }
  // Ingresar los nombres de las asignaturas unicas
  std::sort(asignaturas.begin(),asignaturas.end());
  auto it = std::unique(asignaturas.begin(), asignaturas.end());
  asignaturas.erase(it,asignaturas.end());
  std::map<std::string, int> cantidades;

  // Calcular cantidad de veces por asignatura
  for(std::size_t i = 0; i<asignaturas.size(); i++){
    int cantidad_asignatura = 0;
    for(std::size_t j = 0; j<_asignaturas.size();j++){
      if(asignaturas.at(i)==_asignaturas.at(j).nombre){
        cantidad_asignatura ++;
      }
    }
    cantidades.insert(pair<std::string,int>(asignaturas.at(i),cantidad_asignatura));    
  }
  //for(const auto& x : cantidades){
  //  std::cout << x.first << ": " << x.second << endl;
  //}
  return cantidades;
}

vector<Aula> aulasDisponibles(vector<Aula> salas, int dia, int periodo){
  vector<Aula> salas_disponibles;
  for(std::size_t i = 0; i<salas.size(); i++){
    if(salas.at(i).horarioDisponible(dia,periodo)){
      salas_disponibles.push_back(salas.at(i));
    }else{
      continue;
    }
  }
  return salas_disponibles;
}

// Retorna primera posición en la que se encuentre la cantidad de bloques
// disponibles entre todas las aulas.
vector<int> mismoPeriodoLibre(vector<Aula> salas, int cantidad){
  vector<int> indices;
  for(int i = 1;i<6;i++){
    for(int j = 0; j<8; j++){
      int encontrados = 0;
      for(size_t k = 0; k<salas.size();k++){
        if(salas.at(k).horarioDisponible(i,j)){
          encontrados++;
        }else{
          continue;
        }
      }
      if(encontrados >= cantidad){
        indices.push_back(i);
        indices.push_back(j);
        return indices;
      }else{
        continue;
      }
    }
  }
  return indices;
}

// Retorna el nombre de alguna de las asignaturas con mayor cantidad de secciones.
std::string mayorCantidadSecciones(std::map<std::string, int> cantidades_por_asignatura){
  std::string nombre_mayor;
  int mayor = 0;
  for(const auto& x : cantidades_por_asignatura){
    if(x.second > mayor){
      nombre_mayor = x.first;
    }else{
      continue;
    }
  }
  return nombre_mayor;
}

vector<int> indicesAsignatura(vector<Asignatura> asignaturas,std::string nombre_asignatura){
  vector<int> indices;
  for(size_t i=0;i<asignaturas.size();i++){
    if(asignaturas.at(i).nombre == nombre_asignatura){
      indices.push_back(i);
    }
  }
  return indices;
}

