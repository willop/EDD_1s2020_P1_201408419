#ifndef NODOLDOBLE_H
#define NODOLDOBLE_H


class NodoLDoble
{
    public:
        NodoLDoble *siguiente;
        NodoLDoble *anterior;
        NodoLDoble(char caracter);
        //get y set
        char getNodoListaDoble();
        void setNodoListaDoble(char caracter);
        virtual ~NodoLDoble();

    private:
        //caracteristicas del nodo
        char caracter;
};

#endif // NODOLDOBLE_H

