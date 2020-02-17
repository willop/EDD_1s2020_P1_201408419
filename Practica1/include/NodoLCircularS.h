#ifndef NODOLCIRCULARS_H
#define NODOLCIRCULARS_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;
class NodoLCircularS
{
    public:
        NodoLCircularS *siguiente;
        void setNodoListaCircularS(string dato);
        string getNodoListaCircularS();
        //constructor
        NodoLCircularS(string dato);
        //destructor
        virtual ~NodoLCircularS();



    private:
        string dato;
};

#endif // NODOLCIRCULARS_H
