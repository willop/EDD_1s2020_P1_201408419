#include "NodoLOrdenada.h"
#include <iostream>
#include <string>

using namespace std;
//constructor
NodoLOrdenada::NodoLOrdenada(string _dato1, string _dato2)
{
    this->buscada=_dato1;
    this->reemplazada=_dato2;
    siguiente=NULL;
}

//metodos de get y set
void NodoLOrdenada::setNodoListaOrdenada(string _dato1,string _dato2){
    this->buscada=_dato1;
    this->reemplazada=_dato2;
}

//ger buscada
string NodoLOrdenada::getNodoBuscadaOrdenada(){
return buscada;
}

//get restaurada
string NodoLOrdenada::getNodoReemplazadaOrdenada(){
return reemplazada;
}


//destructor
NodoLOrdenada::~NodoLOrdenada()
{

}
