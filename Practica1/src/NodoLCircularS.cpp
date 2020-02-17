#include "NodoLCircularS.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
//metodo de contructor inicializado con un dato
NodoLCircularS::NodoLCircularS(string _dato)
{
    //llenar el primer valor
    this->dato=_dato;
    //se inician los apuntadores apuntando a null
    siguiente=NULL;
}

//metodos de set y get
void NodoLCircularS::setNodoListaCircularS(string _dato){
     this->dato=_dato;
}

string NodoLCircularS::getNodoListaCircularS(){
return dato;
}

//metodo destructor
NodoLCircularS::~NodoLCircularS()
{

}
