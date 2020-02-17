#ifndef LISTACIRCULARS_H
#define LISTACIRCULARS_H

#include "NodoLCircularS.h"
#include <iostream>
#include <string>

using namespace std;
class ListaCircularS
{
    public:
        //nodos primera y ultima posicion de la lista circular
        NodoLCircularS *Primero;
        NodoLCircularS *Ultimo;

        //metodos de la lista
        bool estadoListaCircularS();
        void insertarListaCircularS(string  arg);
        void recorrerListaCircularS();
        void graficarListaCircularS();
        //contructor
        ListaCircularS();
        //destructor
        virtual ~ListaCircularS();




    private:
};

#endif // LISTACIRCULARS_H
