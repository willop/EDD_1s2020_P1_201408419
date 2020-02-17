#ifndef NODOPILAHISTORIAL_H
#define NODOPILAHISTORIAL_H
#include <string>


using namespace std;


class NodoPilaHistorial
{
    public:

        NodoPilaHistorial *debajo;
        NodoPilaHistorial(string arg);
        string getNodoPilaHistorial();
        void setNodoHistorial(string arg);
        virtual ~NodoPilaHistorial();


    private:
        string dato;

};

#endif // NODOPILAHISTORIAL_H
