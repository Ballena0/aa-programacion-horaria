#ifndef __AULA_H__
#define __AULA_H__

#include <map>
#include <iostream>

using namespace std;

class Aula{
    private:
    public:
        string nombreSala;
        map<int, string> periodos;
        Aula();
        ~Aula();
        Aula(string, map<int, string> &);
};

#endif // __AULA_H__
