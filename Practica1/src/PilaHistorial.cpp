#include "PilaHistorial.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

PilaHistorial::PilaHistorial()
{
    primero=NULL;
    ultimo=NULL;
}

bool PilaHistorial::estadopilahistorial(){

if(primero==NULL && ultimo==NULL){
    return true;
}
else {
    return false;
}
}//fin del metod de bool


//ingresar datos a la pila
void PilaHistorial::pushPilaHistorial(string _datoo){
    //se crea el espacio en memoria del nodo llenando el nodo de una vez
    NodoPilaHistorial *nuevoNodoPila = new NodoPilaHistorial(_datoo);

    //si la lista esta vacia
    if(estadopilahistorial()==true){
        primero=nuevoNodoPila;
        ultimo=nuevoNodoPila;
    }

    //si la lista no esta vacial
    else{
        nuevoNodoPila->debajo=primero;
        primero=nuevoNodoPila;
    }
}//fin del metodo de ingresar a la pila


void PilaHistorial::recorrerPila(){


    //verificar si esta vacia la pila
    if(estadopilahistorial()==true){
        cout<<"La pila se encuentra vacia ";
        cin.get();
    }
    else{

        //creo una variable para crear un archivo
        ofstream archivo;
        archivo.open("C:\\Users\\Wilfred\\Desktop\\grafopila1.txt",ios::out);
        //si falla al crear el archivo
        if(archivo.fail()==true)
        {
            cout<<"Fallo al abrir un archivo para dibujar la pila";
            cin.get();

        }
        else{
            archivo<<"Digraph grafo{\nnode [shape=record];\n";

        //contador de estructuraas
        int contador=0;

        //creo un nodo que va a recorrer la pila
        NodoPilaHistorial *aux=primero;
        while(aux!=NULL){
        contador++;
        //cout<<aux->getNodoPilaHistorial()<<endl<<".|."<<endl;
        archivo<<"struct"<<contador<<" [label =\" | "<<aux->getNodoPilaHistorial()<<" | \"];\n";
        aux= aux->debajo;
        }



        //cout<<"NULL";
        archivo<<"Null\n ";

        for(int i=1;i<=contador;i++){
            archivo<<"struct"<<i<<"->";
        }
        archivo<<"Null;\n}";
        archivo.close();
        //system("cd /home/willop/Escritorio/EDD/Practica1consola");
        system("dot C:\\Users\\Wilfred\\Desktop\\grafopila1.txt -o C:\\Users\\Wilfred\\Desktop\\imgpila1.png -Tpng");
        cin.get();
        }//fin al escribir un archivo
    }

}


//eliminar el primer nodo
void PilaHistorial::popPilaHistorial(){
//verificar que la pila no este vacia;
    if(estadopilahistorial()==true){
        system("cls");
        cout<<"La pila de acciones esta vacia.";
    }
    else{
        NodoPilaHistorial *aux=primero;
        primero=aux->debajo;
        delete aux;


    }

}

PilaHistorial::~PilaHistorial()
{
    //dtor
}
