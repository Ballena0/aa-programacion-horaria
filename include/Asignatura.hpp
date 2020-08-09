#ifndef __ASIGNATURA_H__
#define __ASIGNATURA_H__

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Asignatura{
    private:
    public:
        int nivel;
        string nombre;
        bool con_aula = false;
        int codigo;
        Asignatura();
        ~Asignatura();
        Asignatura(int, string, int);
};


#endif // __ASIGNATURA_H__