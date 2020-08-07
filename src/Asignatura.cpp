#include "../include/Asignatura.hpp"

Asignatura::Asignatura() {
    nivel = 0;
    nombre = "";
}

Asignatura::~Asignatura() {}

Asignatura::Asignatura(int _nivel, string _nombre){
    nivel = _nivel;
    nombre = _nombre;
}