#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <vector>
#include <conio.h>
#include <fstream>//libreria para manipulacion de arvhivos desde el programa, tanto leer como escribir en ellos.
//#include <ncurses.h>//libreria para modificar la interfaz de la consola.
//Headers del proyecto
#include <stdlib.h>
#include "ListaDoble.h" //lista doble enlazada
#include "PilaHistorial.h" //pila ctr+z
#include "ListaCircularS.h"// lista simple enlazada
#include "ListaOrdenadaABC.h" //Lista ordenada



using namespace std;

//prototipos


void gotoxy(int x, int y)
{
 HANDLE hCon;
 COORD dwPos;

 dwPos.X = x;
 dwPos.Y = y;
 hCon = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleCursorPosition(hCon,dwPos);

}

//metodo para pintar el borde o la caja de texto.
void pintar(){



//para colocar color de fondo y color de fuente
//int ww;



 for(int i=0; i < 119; i++){
 gotoxy (i, 0); printf("%c", 205);
 gotoxy(i, 29); printf("%c", 205);
 }

 for(int v=0; v < 29; v++){
 gotoxy (0,v); printf("%c", 186);
 gotoxy(119,v); printf("%c", 186);
 }

 //aca se pintan las esquinas del recuadro para los bordes
 gotoxy (0,0); printf("%c", 201);
 gotoxy (0,29); printf("%c", 200);
 gotoxy (119,0); printf("%c", 187);
 gotoxy(119,29); printf("%c", 188);


 } //fin metodo gotoxy();


int main(){
    const int arr=80, aba=72; //arr=arriba - aba=abajo
    const int der=75, izq=77; //izq=izquierda - der=derecha
    const int ent=13, esc=27; //ent=enter - esc=escape
    const int ln=110, ly=121; //ln=tecla(L) - ly=letra(Y)
	//-----------------------------variables-------------------------------------
	int menu=0;//salir o mantenerce en el while del menu
	int opcion;//seleccionar la opcion en el menu
	ListaDoble lista;
    PilaHistorial pilacambios;
    PilaHistorial pilarevertidos;
    ListaCircularS listacircular1;
    ListaOrdenadaABC listabusqueda;
    ListaOrdenadaABC listareemplazo;

	//-------------------------------fin de variables----------------------------
	pintar();

while(menu=1){
        //system("cls");
	  gotoxy(1,1);printf("\tUNIVERSIDAD DE SAN CARLOS DE GUATEMALA");
	  gotoxy(1,2);printf("\tFACULTAD DE INGENIERIA");
	  gotoxy(1,3);printf("\tESTRUCTURAS DE DATOS");
	  gotoxy(1,4);printf("\tPRACTICA 1");
	  gotoxy(1,5);printf("\tWILFRED STEWART PEREZ SOLORZANO");
	  gotoxy(1,6);printf("\t201408419");
	  gotoxy(7,10);	cout<<"\t\t\t\t-----------------------------MENU-----------------------------";

	  gotoxy(2,12);printf("1.\tCrear archivo");
	  gotoxy(2,13);printf("2.\tAbrir archivo");
	  gotoxy(2,14);printf("3.\tArchivos recientes ");
	  gotoxy(2,15);printf("4.\tCambiar color de la interfaz");
	  gotoxy(2,16);printf("5.\tSalir");
	  gotoxy(2,17);printf("\t\t\tIngrese su opcion...   ");
	  cin>>opcion;
	  //gotoxy();

	  switch(opcion)
	  {

	      //crar un archivo
	  	case 1:{
	  	    string aux;
	  		string contenido;
	  		system("cls");
	  		pintar();
	  		gotoxy(1,1);printf("\t\t\t\t\t\t\tCrear un archivo");
	  		gotoxy(1,2);printf("^+W (Buscar y reemplazar)\t\t\t\t^+C (Reportes)\t\t\t\t\t^+S (Guardar)");
	  		gotoxy(1,4);

	  		//aca empieza la escritura dentro del archivo de texto
	  		/////
	  		///////
	  		///////

            char teclaprecionada;
            int terminar2=1;
            while(terminar2!=0){
                teclaprecionada=getch();
                cout<<teclaprecionada;
                aux=teclaprecionada;
                contenido=contenido+aux;
                //aca por si preciona la convinacion de teclas ctrl + x
                if(teclaprecionada==24){
                    terminar2=0;
                }
                else{
                        switch(teclaprecionada)
                        {
                        //para saltos de linea
                        case 13:
                            {
                            //getline(cin,aux);
                            printf("\n");
                            contenido=contenido+aux+"\n";
                            break;
                            }
                            //generar reportes
                        case 3:
                            {


                            //cout<<"\n\n\nEl texto recolectado es: "<<endl<<contenido;
                            for(int i=0;i<contenido.size()-1;i++){

                            lista.insertar(contenido[i]);
                            }
                            //generar imagen
                            lista.recorrerlista();
                            cin.get();
                            system("cls");
                            //se llena y se muestra la lista ordenada de las palabras modificadas

                            listabusqueda.pintarListaOrdenadaABC(1);
                            listareemplazo.pintarListaOrdenadaABC(2);
                            system("cls");
                            pilacambios.recorrerPila();
                            }
                            system("cls");

                            pintar();
                            gotoxy(1,1); printf("Se genero el reporte en el escritorio");
                            gotoxy(1,2); printf("Presione Ctrl+x para regresar al menu...");
                            cin.get();


                            break;
                        ///// para buscar y reemplazar
                        case 23:
                               //elimino esta lista
                            lista.limpiarlistadoble();
                            vector<string> vec;
                            string subtexto;
                            gotoxy(2,25);
                            cout<<"Buscar y reemplazar: ";
                            cin>>subtexto;


                            //separar buscar de reemplazar
                            stringstream ss(subtexto);
                            //intento de split
                            while(ss.good()){
                                string substr;
                                getline(ss,substr,';');
                                vec.push_back(substr);
                            }

                            cout<<endl<<"\n\nListado:"<<endl<<vec.at(0)<<endl<<vec.at(1);


                            //buscar el texto
                            string::size_type posicion = contenido.find(vec.at(0),0);

                            cout<<endl<<"\n\nEl contenido en la lista es: "<<endl<<contenido;
                            if(posicion<string::npos)
                                contenido.replace(posicion,string(vec.at(0)).length(),vec.at(1));
                            system("cls");
                            pintar();
                            pintar();
                            gotoxy(1,1);printf("\t\t\t\t\t\t\tSe modifico el archivo");
                            gotoxy(1,2);printf("Se genero de nuevo la lista doble con la modificacion.");
                            gotoxy(1,3);printf("La cadena resultante es:");
                            gotoxy(1,4);cout<<contenido;
                            for(int i=0;i<contenido.size()-1;i++){
                            lista.insertar(contenido[i]);
                            }
                            //generar imagen
                            lista.recorrerlista();

                            //se llena y se muestra la lista ordenada de las palabras modificadas
                            listabusqueda.insertarListaOrdenadaABC(vec.at(0),vec.at(1));
                            listareemplazo.insertarListaOrdenadaABC(vec.at(1),vec.at(0));
                            string textoparapila="Palabra Buscada: "+vec.at(0)+"\nReemplazada por: "+vec.at(1)+"\nEstado: No revertido";
                            pilacambios.pushPilaHistorial(textoparapila);

                        break;



                        }//fin del switch
                }

            }//fin del while



	  		//aca empieza a pedir teclas hasta que precione otra

	  		system("cls");
	  		//gotoxy(2,50);
	  		//cout<<"Ingreso:\n"<<contenido;
	  		break;
	  	}

	  	//abrir un archivo por medio de una ruta
	  	case 2:{
			string rutaarchivo;
            string cuerpoarchivo;
	  		system("cls");
	  		pintar();
	  		gotoxy(1,1);printf("\t\t\t\t\t\t\tAbrir un archivo");
	  		gotoxy(1,2);printf("^+W (Buscar y reemplazar)\t\t\t\t^+C (Reportes)\t\t\t\t\t^+S (Guardar)");
	  		gotoxy(1,3);printf("Ingrese la ruta del archivo: ");
	  		gotoxy(1,4);
	  		cin.get();
            getline(cin,rutaarchivo);
            string aux;
                ifstream leerarchivo;
                //cout<<rutaarchivo;
                leerarchivo.open(rutaarchivo.c_str(),ios::in);
                if(leerarchivo.is_open()){
                    while(! leerarchivo.eof()){
                        getline(leerarchivo,aux);
                        cout<<"Leido:  "<<cuerpoarchivo<<endl;
                        cuerpoarchivo=cuerpoarchivo+"\n"+aux;
                    }
                    //cout<<"Esto encontro:"<<endl;
                    //cout<<cuerpoarchivo;

                    leerarchivo.close();
                    listacircular1.insertarListaCircularS(rutaarchivo);
                }
                else{
                    cout<<"No se pudo abrir el documento o tiene algun error";
                }


            //cout<<endl<<"\n\nLa lista:\n";
            //listacircular1.recorrerListaCircularS();
            //cin.get();

            //while para capturar la tecla precionada

                char cTecla;
                int terminar=1;
                while(terminar != 0){
                    cTecla = getch();
                    cout<<cTecla;

                        if(cTecla==27){
                            //cout<<"Preciono ctrl +z y salio";
                            terminar=0;
                        }

                        else{

                            switch(cTecla)
                            {
                                case 13:
                                    printf("\r\n");
                                break;
                            }
                            //fin del switch
                            } //fin del else
                }//end while para

            string textocompleto;
            getline(cin,textocompleto);
            cout<<"\n\nTexto:  "<<textocompleto;
            cin.get();

	  		//lista.recorrerlista();
	  		//cin>>rutaarchivo;
	  		//gotoxy(1,6);
            system("pause>aa");
	  		system("cls");
	  		break;
	  	}





	  	//archivos recientes
	  	case 3:{
	  	    system("cls");
	  		pintar();
			gotoxy(1,1);printf("\t\t\t\t\t\tEntro a la opcion de historial");
	  		gotoxy(8,30); printf("X.- para generar reporte de historial\t\t\t\t\t\tN. Salir al menu");
	  		gotoxy(1,3);
            listacircular1.recorrerListaCircularS();
            //listacircular1.graficarListaCircularS();

            char cTecla;
                int terminar=1;
                while(terminar != 0){
                    cTecla = getch();
                    cout<<cTecla;

                        if(cTecla==110||cTecla==78){
                            //cout<<"Preciono N";
                            terminar=0;
                        }

                        else{

                            switch(cTecla)
                            {
                                case 120:
                                    listacircular1.graficarListaCircularS();
                                    system("cls");
                                    pintar();
                                    gotoxy(15,20); printf("Se genero el grafo en el escritorio.");
                                    //cin.get();
                                break;
                            }
                            //fin del switch
                            } //fin del else

            }
            system("cls");
	  		break;
	  	}


	  	//opciones para cambiar de color la consola
	  	case 4:{
	  		int ww;
	  		system("cls");
	  		pintar();
	  		gotoxy(1,1);printf("Entro a la opcion cambio de color");
	  		gotoxy(1,2);printf("0.\tFondo negro y fuente verde");
	  		gotoxy(1,3);printf("1.\tFondo blanco y fuente rojo claro");
	  		gotoxy(1,4);printf("2.\tFondo purpura y fuente aguamarina claro");
	  		gotoxy(1,5);printf("3.\tFondo azul y fuente amarillo claro");
	  		gotoxy(1,6);printf("4.\tFondo gris y fuente verde");
	  		gotoxy(1,7);printf("5.\tFondo aguamarina y fuente blanco");
	  		gotoxy(1,9);printf("Ingrese un numero:\n");
	  		gotoxy(1,10);
			cin>>ww;
				switch(ww){
					case 0:
						//negro y verde
						system ("color 0A");
						break;
					case 1:
						//blanco y rojo
						system ("color 7C");
						break;
					case 2:
						//purpura y agua
						system ("color 5B");
						break;
					case 3:
						//azul y amarillo claro
						system ("color 1B");
						break;
					case 4:
						//gris y verde
						system ("color 8A");
						break;
					case 5:
						//aguamarina y blanco
						system ("color 3F");
						break;
					default:{
						break;//system ("color 8");
					}

				}//fin del switch para el color
	  		system("pause>aa");
	  		system("cls");
	  		break;
	  	}
	  	case 5:{
	  		system("cls");
	  		pintar();
	  		gotoxy(2,1);printf("Salio del menu");
	  		menu=0;
	  		//system("pause>aa");
	  		exit(-1);
	  	}
	  	default:{
	  		system("cls");
            pintar();
	  		//gotoxy(1,1);printf("SELECCIONE UNA OPCION VALIDA");
	  		break;
	  	}
	  }

}//fin del while

return 0;

}
