#include "../include/Aula.hpp"

Aula::Aula() {
    map<int, string> periodos;

    nombreSala = "";
    periodos = periodos;    
}

Aula::~Aula() {}

Aula::Aula(string _nombreSala, map<int, string> &_periodos)
{
    nombreSala = _nombreSala;
    periodos = _periodos;
}
