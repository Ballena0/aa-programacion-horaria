#include "../include/Aula.hpp"

Aula::Aula() {
    vector<vector<string>> periodos;

    nombreSala = "";
    periodos = periodos;    
}

Aula::~Aula() {}

Aula::Aula(string _nombreSala, vector<vector<string>> &_periodos)
{
    nombreSala = _nombreSala;
    periodos = _periodos;
}

bool Aula::horarioDisponible(int dia, int periodo){
    if(this->periodos.at(dia).at(periodo) == ""){
        return true;
    }else{
        return false;
    }
}

void Aula::utilizarHorario(Asignatura &asignatura, int dia, int periodo){
    std::string nombre = asignatura.nombre.substr(1, asignatura.nombre.size()-1);
    std::string celda = '"' + to_string(asignatura.codigo)+ " - "+nombre;
    this->periodos.at(dia).at(periodo) = celda;
    asignatura.con_aula = true;
}

void Aula::imprimirPeriodos(){
    for(int j = 0; j < 8; j++){
      for(int i = 0;i<6;i++){
          std::cout << this->periodos.at(i).at(j) << " | ";
      }
    }
}