#ifndef SISCOMPRAS_H
#define SISCOMPRAS_H

#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>

#include"Listacompras.h"


using namespace std;

ifstream Lec;


class SisCompras{//En esta clase se declara todos los mentodos que son aplicables a la lista ya sea guardarla, eliminarla o borrarla
	public:
		int a;
		SisCompras(int);
		void GuardarLista();
		void VerLista();
		int CalculoTotal();
};

SisCompras::SisCompras(int _a){//Este es un consntructor el cual utilizo para poder indentificar y utilizar los voids en el main
	a=_a;
}

void SisCompras::GuardarLista(){//Este void me permite generar un archivo de tipo txt en el cual se almacena la lista de productos seleccionados
	system("cls");
    ofstream Lista;
    system("cls");
    			
    Nodo *actual = new Nodo();
	actual = lista;
				
    Lista.open("Lista.txt",ios::out);
	
	while(actual != NULL)
	{
		Lista<<actual->dato<<endl;
		actual = actual->siguiente;
	}
    			
    Lista.close();
    cout<<"Lista Guardada con Exito\n";
}

void SisCompras::VerLista(){//Este void en caso de tener una lista guardada te mostrara el contenido en la consola y en caso de no existir ninguna lista
	system("cls");			// guardada te dira que no sencotro ninguna lista guardada y saldra del programa
	ifstream Lista;
	string texto;
	
	Lista.open("Lista.txt",ios::in);
	
	if(Lista.fail()){
		cout<<"No se encontro Ninguna lista guardada\n";
		exit(1);
	}
	
	while(!Lista.eof()){
		getline(Lista,texto);
		cout<<texto<<endl;
	}
	
	Lista.close();
	return;
}

int SisCompras::CalculoTotal(){//Este metodo nos permite realizar el calculo del total a pagar de la lista con los productos seleccionados
	
	Nodo *actual = new Nodo();
	actual = lista;
	int total=0;

	
	while(actual != NULL){
		string Palabra=actual->dato;
		if(Palabra == "Pan")
		{
			total=total+15;
		}
		if(Palabra == "Agua")
		{
			total=total+10;
		}
		if(Palabra == "Hielo")
		{
			total=total+20;
		}
		if(Palabra == "Cafe")
		{
			total=total+40;
		}
		if(Palabra == "Papa")
		{
			total=total+25;
		}
		if(Palabra == "Manzana")
		{
			total=total+55;
		}
		if(Palabra == "Chocolate")
		{
			total=total+60;
		}
		if(Palabra == "Leche")
		{
			total=total+24;
		}
		if(Palabra == "Queso")
		{
			total=total+70;
		}
		if(Palabra == "Huevo")
		{
			total=total+60;
		}
		
		actual = actual->siguiente;
	}
	
	return total;
	
}


#endif
