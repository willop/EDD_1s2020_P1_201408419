#include "ListaOrdenadaABC.h"
#include <iostream>
#include <string.h>
#include <windows.h>
#include <fstream>

using namespace std;
//constructor
ListaOrdenadaABC::ListaOrdenadaABC()
{
    primero=NULL;
    ultimo=NULL;
}

bool ListaOrdenadaABC::estadolistaordenadaABC(){
    //preguntar si la lista esta vacia
    if(primero==NULL && ultimo ==NULL){
        return true;

    }
    else{
        return false;
    }

}


void ListaOrdenadaABC::insertarListaOrdenadaABC(string buscada,string reemplazada){
        //creo mi nodo
        NodoLOrdenada *nuevonodo=new NodoLOrdenada(buscada ,reemplazada);

        //si la lista esta vacia la lista es el primer nodo
        if(estadolistaordenadaABC()==true){
            primero=nuevonodo;
            ultimo=nuevonodo;
        }
        else{
        //si no esta vacia
        NodoLOrdenada *aux = primero;
        NodoLOrdenada *aux2;
        char* buscarnuevonodo;
        buscarnuevonodo=(char*)nuevonodo->getNodoBuscadaOrdenada().c_str();
        char* buscarnodoexistente;
        buscarnodoexistente=(char*)aux->getNodoBuscadaOrdenada().c_str();

        //para añadir elemento al final o enmedio de la lista
        while((aux!=NULL) && (strcmp(buscarnuevonodo,buscarnodoexistente)>0)){
           aux2=aux;
           aux=aux->siguiente;
        }//fin del while

        //esto es para que el nuevo nodo se inserte al inicio
        if(primero==aux){
        primero=nuevonodo;
            if(aux->siguiente==NULL){
            ultimo=aux;
            }
            else{

            }
        }
        else{
            aux2->siguiente=nuevonodo;

            //ultimo=nuevonodo;

        }//fin del else

        nuevonodo->siguiente=aux;
        if(aux==NULL)
        {
            ultimo=nuevonodo;
        }

        }//fin del else
}


//recorrer lista ordenada alfabeticamente
void ListaOrdenadaABC::pintarListaOrdenadaABC(int _tipo){
    ofstream archivolistaordenada;
    //tipo 1 es de busqueda
    //tipo 2 es de reemplazo
    switch(_tipo){
    //para busqueda
    case 1:
    {

    archivolistaordenada.open("C:\\Users\\Wilfred\\Desktop\\grafolistabusqueda.txt",ios::out);
    //si no se puede crear el archivo
    if(archivolistaordenada.fail()==true){
        cout<<"No se pudo graficar la lista de busqueda ordenada";
        cin.get();
    }
    //si no hay problema al crear el archivo
    else{
        archivolistaordenada<<"Digraph grafo{\nnode [shape=record];\n label=\"Lista ordenada de busqueda\";\n";

    //verificar que la lista no este vacia
    if(estadolistaordenadaABC()==true){
        system("cls");
        cout<<"La grafica de la lista de busqueda ordenada esta vacia";
        cin.get();
    }
    //si no esta vacia
    else{

    int contado=0;
    NodoLOrdenada *aux=primero;
        //si solo hay un nodo en la lista
        if(primero==ultimo){
            contado=1;
            archivolistaordenada<<"struct"<<contado<<" [label =\" | Palabra Buscada: "<<aux->getNodoBuscadaOrdenada()<<"\n Palabra Reemplazada: "<<aux->getNodoReemplazadaOrdenada()<<" | \"];\n";
            archivolistaordenada<<"struct1->NULL;\n}";
            archivolistaordenada.close();
        }
        //si hay mas de un nodo en la lista
        else{

            while(aux!=NULL){
                contado++;
                archivolistaordenada<<"struct"<<contado<<" [label =\" | Palabra Buscada: "<<aux->getNodoBuscadaOrdenada()<<"\n Palabra Reemplazada: "<<aux->getNodoReemplazadaOrdenada()<<" | \"];\n";
                aux=aux->siguiente;
            }


            for(int i=1;i<=contado;i++){
                archivolistaordenada<<"struct"<<i<<"->";
            }
            archivolistaordenada<<"NULL;\n}";
            archivolistaordenada.close();
            cin.get();

            }

        }//fin else si no esta vacia
        system("dot C:\\Users\\Wilfred\\Desktop\\grafolistabusqueda.txt -o C:\\Users\\Wilfred\\Desktop\\grafoListaordenadabusqueda.png -Tpng");
    }//fin del else fail archivo

        break;
    }//fin del case 1


    case 2:
    {

    archivolistaordenada.open("C:\\Users\\Wilfred\\Desktop\\grafolistareemplazo.txt",ios::out);
    //si no se puede crear el archivo
    if(archivolistaordenada.fail()==true){
        cout<<"No se pudo graficar la lista de busqueda ordenada";
        cin.get();
    }
    //si no hay problema al crear el archivo
    else{
        archivolistaordenada<<"Digraph grafo{\nnode [shape=record];\n label=\"Lista ordenada de reemplazo\";\n";

    //verificar que la lista no este vacia
    if(estadolistaordenadaABC()==true){
        system("cls");
        cout<<"La grafica de la lista de busqueda ordenada esta vacia";
        cin.get();
    }
    //si no esta vacia
    else{

    int contado=0;
    NodoLOrdenada *aux=primero;
        //si solo hay un nodo en la lista
        if(primero==ultimo){
            contado=1;
            archivolistaordenada<<"struct"<<contado<<" [label =\" | Palabra Reemplazada: "<<aux->getNodoBuscadaOrdenada()<<"\n Palabra Buscada: "<<aux->getNodoReemplazadaOrdenada()<<" | \"];\n";
            archivolistaordenada<<"struct1->NULL;\n}";
            archivolistaordenada.close();
        }
        //si hay mas de un nodo en la lista
        else{

            while(aux!=NULL){
                contado++;
                archivolistaordenada<<"struct"<<contado<<" [label =\" | Palabra Reemplazada: "<<aux->getNodoBuscadaOrdenada()<<"\n Palabra Buscada: "<<aux->getNodoReemplazadaOrdenada()<<" | \"];\n";
                aux=aux->siguiente;
            }


            for(int i=1;i<=contado;i++){
                archivolistaordenada<<"struct"<<i<<"->";
            }
            archivolistaordenada<<"NULL;\n}";
            archivolistaordenada.close();
            cin.get();

            }

        }//fin else si no esta vacia
        system("dot C:\\Users\\Wilfred\\Desktop\\grafolistareemplazo.txt -o C:\\Users\\Wilfred\\Desktop\\grafoListaordenadareemplazo.png -Tpng");
    }//fin del else fail archivo

        break;
    }//fin de case 2

    }//fin del switch



    }//fin del metodo de pintado de ambos




//destructor
ListaOrdenadaABC::~ListaOrdenadaABC()
{
    //dtor
}
