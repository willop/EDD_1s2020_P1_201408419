#include "NodoPilaHistorial.h"
#include <iostream>


//inicia el constructor
NodoPilaHistorial::NodoPilaHistorial(string _dato)
{
    //se llena el campo
    this->dato=_dato;
    //se declara nulo el apuntador de la pila
    debajo=NULL;
}

string NodoPilaHistorial::getNodoPilaHistorial(){
    return dato;
}

void NodoPilaHistorial::setNodoHistorial(string _dat){
    this->dato=_dat;
}


//es el destructor
NodoPilaHistorial::~NodoPilaHistorial()
{

}
