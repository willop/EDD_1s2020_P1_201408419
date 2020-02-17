#ifndef LISTAORDENADAABC_H
#define LISTAORDENADAABC_H
#include "NodoLOrdenada.h"



class ListaOrdenadaABC
{
    public:
        NodoLOrdenada *primero;
        NodoLOrdenada *ultimo;
        //metodos de una lista ordenada
        bool estadolistaordenadaABC();
        void insertarListaOrdenadaABC(string buscado, string reemplazo);
        void pintarListaOrdenadaABC(int tipo);

        //constructor
        ListaOrdenadaABC();
        virtual ~ListaOrdenadaABC();


    private:
};

#endif // LISTAORDENADAABC_H
