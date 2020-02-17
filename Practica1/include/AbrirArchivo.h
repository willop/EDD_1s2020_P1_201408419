#ifndef ABRIRARCHIVO_H
#define ABRIRARCHIVO_H
#include <sstream>
#include <iostream>
#include <string>

class AbrirArchivo
{
    public:
        //metodos
        string Abrirarchivonuevo(string arg);

        //constructor
        AbrirArchivo();
        //destructor
        virtual ~AbrirArchivo();

    private:
        //string ruta;
};

#endif // ABRIRARCHIVO_H
