#include "NodoLDoble.h"
#include <iostream>

//constructor preguntar si en el .h tiene que agregarse el parametro
NodoLDoble::NodoLDoble(char _dato)
{
    this->caracter=_dato;
    //se inicializan los punteros nulos ya que el nodo apunta a nulos a ambos lados
    siguiente=NULL;
    anterior=NULL;
}
//set y get

char NodoLDoble::getNodoListaDoble(){
    return caracter;
}

void NodoLDoble::setNodoListaDoble(char _dato){
    this->caracter=_dato;
}


//destructor
NodoLDoble::~NodoLDoble()
{

}
