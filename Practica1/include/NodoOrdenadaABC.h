#ifndef LISTAORDENADAABC_H
#define LISTAORDENADAABC_H
#include "NodoLOrdenadaABC.h"



class ListaOrdenadaABC
{
public:
        NodoLOrdenadaABC *siguiente;
        void setNodoListaOrdenada(int arg);
        int getNodoListaOrdenada();
        //constructor
        NodoLOrdenadaABC(int arg);
        //destructor
        virtual ~NodoLOrdenadaABC();



    private:
        int dato;
};

#endif // LISTAORDENADAABC_H
