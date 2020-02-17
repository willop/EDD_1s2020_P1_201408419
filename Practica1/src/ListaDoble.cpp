#include "ListaDoble.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;


//constructor de la lista
ListaDoble::ListaDoble()
{
    //se inicializan los nodos primero y ultimo como nulos
    Primero =NULL;
    Ultimo=NULL;

}
//metodo para ingresar a la lisat
void ListaDoble::insertar(char _dato){
    //se reserva espacio en memoria
        NodoLDoble *nuevoNodo=new NodoLDoble(_dato);

// si la lista esta vacia
if(estadoLista()==true){
    //esta vacia por lo tanto el nodo sera el primero de la lista
    Primero=nuevoNodo;
    Ultimo=nuevoNodo;
}
//ya hay elementos en la lista
else{
        //ahora la penultima posicion de la lista apunta a el nuevo nodo para ser el ultimo
    Ultimo->siguiente =nuevoNodo;
    //el nuevo nodo apunta hacia atras al ultimo
    nuevoNodo->anterior=Ultimo;
    //el nuevo nodo sera la ultima posicion
    Ultimo=nuevoNodo;
}


}//fin del metodo de insertar en la fila


void ListaDoble::recorrerlista(){
//preguntar si la lista esta vacia
if(estadoLista()==true){
    cout<<"La lista esta vacia por favor ingrese valores en la opcion 1";
    cin.get();
}
else{
        //aca creo el archivo para empezar a graficar la lista doble
        ofstream archivolistadoble;
        archivolistadoble.open("C:\\Users\\Wilfred\\Desktop\\grafolistadoble.txt",ios::out);
        //si falla el crear el archivo
        if(archivolistadoble.fail()==true){
            cout<<"Se creo un error al crear un archivo de texto de la lista doble almacenando ";
           cin.get();
        }
        //si no falla
        else{

            archivolistadoble<<"Digraph grafo{\nnode [shape=record];\n label=\"Lista doble\";\n";


        int contadordenodos=0;


    NodoLDoble *aux= Primero;
    while(aux!=NULL){
            contadordenodos++;
        //cout<<aux->getNodoListaDoble()<<"->";
        archivolistadoble<<"struct"<<contadordenodos<<" [label =\" | "<<aux->getNodoListaDoble()<<" | \"];\n";
        aux= aux->siguiente;
    }
    //cout<<"NULL";
    archivolistadoble<<"Null\n ";

    for(int i=1;i<=contadordenodos;i++){

        archivolistadoble<<"struct"<<i<<"->";

    }

    //cout<<"NULL";
    archivolistadoble<<"Null\n\n[dir=both];}";
    archivolistadoble.close();


    system("dot C:\\Users\\Wilfred\\Desktop\\grafolistadoble.txt -o C:\\Users\\Wilfred\\Desktop\\imglistadoble.png -Tpng");
        //cin.get();
    //cout<<endl<<"Recorrido de la lista inversamente:"<<endl;


    cin.get();
        }
}

}


bool ListaDoble::estadoLista(){
    //pregunra si los apuntadores estan vacios, si lo estan la lista esta vacia
    if(Primero==NULL && Ultimo==NULL){
        return true;
    }
    else{
        return false;
    }

}
//para saber si la lista esta llena o no


void ListaDoble::limpiarlistadoble(){
Primero=NULL;
Ultimo=NULL;
}


//destructor
ListaDoble::~ListaDoble()
{

}
