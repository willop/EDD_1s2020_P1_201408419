#ifndef LISTADOBLE_H
#define LISTADOBLE_H

//se añade la clase nodos
#include "NodoLDoble.h"
#include <iostream>


class ListaDoble
{
    public:
        ListaDoble();
        NodoLDoble *Primero;
        NodoLDoble *Ultimo;
        void limpiarlistadoble();
        void insertar(char entero);
        void recorrerlista();
        bool estadoLista();

        virtual ~ListaDoble();



    private:
        //no se llena por que no tiene caracteristicas la lista solo realizara acciones
};

#endif // LISTADOBLE_H
