#include "../include/funciones.hpp"

vector<string> split(string str, char delimitador)
{
  vector<string> result;

  stringstream ss(str);

  while (ss.good())
  {
    string substr;
    getline(ss, substr, delimitador);
    result.push_back(substr);
  }

  return result;
}

vector<Carrera> generarCarreras(string datos)
{
  vector<Carrera> carreras;

  ifstream entrada(datos);
  for (string linea; getline(entrada, linea);)
  {
    vector<string> arreglo = split(linea, ';');
    string carrera_ = arreglo[1].substr(1, arreglo[1].size() - 1);
    int codigoCarrera = stoi(carrera_);
    Carrera carrera = Carrera(codigoCarrera);
    if (!carrera.exist(carreras))
    {
      carreras.push_back(carrera);
    }
    else
    {
      continue;
    }
  }
  cout << "carreras creadas" << endl;
  return carreras;
}

vector<Carrera> generarAsignaturas(string datos)
{
  ifstream entrada(datos);

  vector<Carrera> carreras = generarCarreras(datos);
  vector<Asignatura> asignaturas;
  for (string linea; getline(entrada, linea);)
  {
    vector<string> arreglo = split(linea, ';');
    int nivel = stoi(arreglo[0].substr(1, arreglo[0].size() - 1));
    int codigo = stoi(arreglo[1].substr(1, arreglo[1].size() - 1));
    Asignatura asignatura = Asignatura(nivel, arreglo.at(2));
    for (unsigned int i = 0; i < carreras.size(); i++)
    {
      if (codigo == carreras.at(i).codigoCarrera)
      {
        carreras.at(i).asignaturas.push_back(asignatura);
      }
      else
      {
        continue;
      }
    }
  }
  return carreras;
}

vector<Aula> generarSalas(string aulas, string periodos)
{
  vector<Aula> ss;
  ifstream salas(aulas);
  ifstream horas(periodos);
  for (string linea; getline(salas, linea);)
  {
    map<int, string> per;
    for (string linea2; getline(horas, linea);)
    {
      vector<string> arreglo = split(linea, ',');
      int periodo = stoi(arreglo[0]);
      per.insert(pair<int, string>(periodo, arreglo.at(1)));
    }
    Aula sala = Aula(linea, per);
    ss.push_back(sala);
  }
  return ss;
}

int random(int a, int b)
{
  int aux;
  std::random_device rd;
  std::mt19937 e{rd()};
  std::uniform_int_distribution<int> dist{a, b};
  aux = dist(e);
  return aux;
}

vector<Aula> salasLlenas(vector<Aula> salas, vector<Carrera> carreras)
{
  for (unsigned int i = 0; i < salas.size(); i++)
  {
    for (unsigned int k = 0; k < carreras.size(); k++)
    {
      for (unsigned int z = 0; z < carreras[k].asignaturas.size(); z++)
      {
        map<int, string> periodo_ramo;
        for (int j = 1; j <= 8; j++)
        {
          periodo_ramo.insert(pair<int, string>(j, carreras[k].asignaturas[z].nombre));
          salas[i].periodos = periodo_ramo;
        }
      }
    }
  }
  return salas;
}

void imprimirSalas(vector<Aula> salasCompletas){
  for(unsigned int i = 0; i < salasCompletas.size(); i++){
    for(const auto& x : salasCompletas[i].periodos){
      cout << x.first << " : " << x.second << endl;
    }
  }
}
