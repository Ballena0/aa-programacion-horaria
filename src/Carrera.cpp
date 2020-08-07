#include "../include/Carrera.hpp"
#include "../include/Asignatura.hpp"

Carrera::Carrera(int _codigo) {
    codigoCarrera = _codigo;
}

Carrera::~Carrera() {
    vector<Asignatura> asignatura;
    
    codigoCarrera = 0;
    asignaturas = asignatura;
}

Carrera::Carrera(int _codigo, vector<Asignatura> _asignaturas)
{
    codigoCarrera = _codigo;
    asignaturas = _asignaturas;
}

bool Carrera::exist(vector<Carrera> carreras){
    if(!carreras.empty()){
        for(unsigned int i = 0; i < carreras.size(); i++){
            if(this->codigoCarrera == carreras.at(i).codigoCarrera){
                return true;
            }
        }
    }
}