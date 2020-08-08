#include "../include/Asignatura.hpp"

Asignatura::Asignatura() {
    nivel = 0;
    nombre = "";
    bool con_aula = false;
}

Asignatura::~Asignatura() {}

Asignatura::Asignatura(int _nivel, string _nombre, int _codigo){
    nivel = _nivel;
    nombre = _nombre;
    codigo = _codigo;
}

