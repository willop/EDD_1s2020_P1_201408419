#include "AbrirArchivo.h"
#include <iostream>
#include <string>
#include <fstream>

//constructor
AbrirArchivo::AbrirArchivo()
{
    //ctor
}

//metodos

string AbrirArchivo::Abrirarchivonuevo(string _ruta){
string cadenasalida;
ifstream archivo(_ruta);
if(!archivo.eof()){
        archivo>>cadenasalida;
}
 return cadenasalida;
}


//destructor
AbrirArchivo::~AbrirArchivo()
{
    //dtor
}
