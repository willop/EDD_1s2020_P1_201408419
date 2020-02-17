#ifndef NODOLORDENADA_H
#define NODOLORDENADA_H
#include <string>

using namespace std;

class NodoLOrdenada
{
    public:
        NodoLOrdenada *siguiente;
        void setNodoListaOrdenada(string buscada,string reemplazada);
        string getNodoBuscadaOrdenada();
        string getNodoReemplazadaOrdenada();
        //constructor
        NodoLOrdenada(string buscada,string reemplazada);
        //destructor
        virtual ~NodoLOrdenada();



    private:
        string buscada;
        string reemplazada;
};

#endif // NODOLORDENADA_H
