#ifndef __CARRERA_H__
#define __CARRERA_H__

#include <iostream>
#include <vector>
#include "Asignatura.hpp"


using namespace std;

class Carrera{
    private:
    public:
        int codigoCarrera;
        vector<Asignatura> asignaturas;
        Carrera(int);
        ~Carrera();
        Carrera(int, vector<Asignatura>);
        bool exist(vector<Carrera>);
};


#endif // __CARRERA_H__
