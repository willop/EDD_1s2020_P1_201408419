#include "ListaCircularS.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
//constructor
ListaCircularS::ListaCircularS()
{
    Primero=NULL;
    Ultimo=NULL;
}



//metodo de ingresar a la lista circular simple
void ListaCircularS::insertarListaCircularS(string _dato){
    //crear un nodo de tipo lista circular
    NodoLCircularS *nuevoNodoCircular = new NodoLCircularS(_dato);

    //si no hay elementos en la lista
    if(estadoListaCircularS()==true){
        Primero=nuevoNodoCircular;
        Ultimo=nuevoNodoCircular;
    }
    //si hay elementos en la lista
    else{
        Ultimo->siguiente=nuevoNodoCircular;
        Ultimo = nuevoNodoCircular;
        Ultimo->siguiente = Primero;
    }
}//fin del metodo de la lista circular enlazada


void ListaCircularS::recorrerListaCircularS(){
    //verificar si la lista esta vacia
    int contador=0;

if(estadoListaCircularS()==true){
    cout<<"La lista circular simple esta vacia.";
    cin.get();
}
// si no esta vacia
else{
        NodoLCircularS *aux=Primero;
        //por si solo hay un numero
        if(Primero==Ultimo){
                contador++;
            cout<<contador<<".-   "<<aux->getNodoListaCircularS()<<endl;
            cin.get();
        }

        else{
        while(aux!=Ultimo){
        contador++;
            cout<<contador<<".-   "<<aux->getNodoListaCircularS()<<endl;
            aux= aux->siguiente;
        }
        contador++;
        cout<<contador<<".-   "<<aux->getNodoListaCircularS()<<endl;

        cin.get();
        }

}

}

//aca el metodo para graficar la lista circular simple
void ListaCircularS::graficarListaCircularS(){

    ofstream archivolistacircular;
    archivolistacircular.open("C:\\Users\\Wilfred\\Desktop\\grafolistacircular.txt", ios::out);
    //si falla el crear archivo
    if(archivolistacircular.fail()==true){
        cout<<"No se pudo graficar la lista circular del historial de archivos";
        cin.get();
    }
    //si no falla
    else{
        archivolistacircular<<"Digraph grafo{\nnode [shape=record];\n label=\"Historial de archivos\";\n";
        int contadordenodos=0;
        NodoLCircularS *aux=Primero;

        if(Primero==Ultimo){
            contadordenodos++;
            archivolistacircular<<"struct1"<<" [label = \" | "<<Primero->getNodoListaCircularS()<<" | \"];\n";
            archivolistacircular<<"struct1->struct1;\n}";
            archivolistacircular.close();
        }

        else{

        while(aux!=Ultimo){
            contadordenodos++;
            archivolistacircular<<"struct"<<contadordenodos<<" [label =\" | "<<aux->getNodoListaCircularS()<<" | \"];\n";
            //cout<<aux->getNodoListaCircularS()<<"->";
            aux= aux->siguiente;
        }
        contadordenodos++;
        archivolistacircular<<"struct"<<contadordenodos<<" [label =\" | "<<aux->getNodoListaCircularS()<<" | \"];\n";


        for(int i=1;i<=contadordenodos;i++){
            archivolistacircular<<"struct"<<i<<"->";
        }
        archivolistacircular<<"struct1;\n}";
        archivolistacircular.close();


        }

        system("dot C:\\Users\\Wilfred\\Desktop\\grafolistacircular.txt -o C:\\Users\\Wilfred\\Desktop\\grafohistorial.png -Tpng");

    }




}//fin del metodo




//// estado de la lista
bool ListaCircularS::estadoListaCircularS(){
if(Primero==NULL && Ultimo==NULL){
    return true;
}
else{
    return false;
}

}

//destructor
ListaCircularS::~ListaCircularS()
{

}
