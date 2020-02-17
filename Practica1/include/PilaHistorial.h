#ifndef PILAHISTORIAL_H
#define PILAHISTORIAL_H

#include "NodoPilaHistorial.h"
#include <iostream>
#include <string>

using namespace std;
class PilaHistorial
{
    public:
        NodoPilaHistorial *primero;
        NodoPilaHistorial *ultimo;
        bool estadopilahistorial();
        void pushPilaHistorial(string arg);
        void GraficarPilaHistorial();
        PilaHistorial();
        void recorrerPila();
        virtual ~PilaHistorial();



    private:
};

#endif // PILAHISTORIAL_H
