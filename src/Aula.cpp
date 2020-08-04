#include "../include/Aula.hpp"

Aula::Aula() {}

Aula::~Aula() {}

Aula::Aula(string _nombreSala, map<int, string> &_periodos)
{
    nombreSala = _nombreSala;
    periodos = _periodos;
}
