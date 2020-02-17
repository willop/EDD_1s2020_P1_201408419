#include "NodoLOrdenadaABC.h"
#include <iostream>

//constructor
NodoLOrdenadaABC::NodoLOrdenada(int _dato)
{
    this->dato=_dato;
    siguiente=NULL;
}

//metodos de get y set
NodoLOrdenadaABC::setNodoListaOrdenada(int _dato){
    this->dato = _dato;
}

NodoLOrdenada::~NodoLOrdenada()
{
    return dato;
}
