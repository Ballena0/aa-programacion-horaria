#ifndef __AULA_H__
#define __AULA_H__

#include <map>
#include <iostream>
#include <vector>
#include <string>

#include "Asignatura.hpp"

using namespace std;

class Aula{
    private:
    public:
        string nombreSala;
        vector<vector<string>> periodos;
        Aula();
        ~Aula();
        Aula(string, vector<vector<string>> &);

        bool horarioDisponible(int, int);
        void utilizarHorario(Asignatura &, int, int);
        void imprimirPeriodos();
};

#endif // __AULA_H__

