#ifndef SISCOMPRAS_H
#define SISCOMPRAS_H

#include<iostream>
#include<stdlib.h>
#include<fstream>

using namespace std;




class SisCompras{//En esta clase se declara todos los mentodos que son aplicables a la lista ya sea guardarla, eliminarla o borrarla
	public:
		int a;
		SisCompras(int);
		void GuardarLista();
		void BorrarLista();	
		void VerLista();
};

SisCompras::SisCompras(int _a){//Este es un consntructor el cual utilizo para poder indentificar y utilizar los voids en el main
	a=_a;
}

void SisCompras::GuardarLista(){//Este void me permite generar un archivo de tipo txt en el cual se almacena la lista de productos seleccionados
	system("cls");
	string arreglo[10] = {"Leche","Pan","Hielo"};
	float arregloP[10] = {20.5,18.7,15.9};
    			ofstream Lista;
    			
    			Lista.open("Lista.txt",ios::out);
    			
    			for(int i=0;i<4;i++){
				
    			Lista<<arreglo[i]<<" ";
    			}
    			Lista<<"\n";
    			for(int i=0;i<4;i++){
				
    			Lista<<arregloP[i]<<" ";
    			}
    			
    			Lista.close();
    			cout<<"Lista Guardada con Exito\n";
}

void SisCompras::BorrarLista(){//Este void me permite borrar el archivo txt que se habia generado anteriormente en caso de ya no nesecitar la lista
	system("cls");
	remove("Lista.txt");
	cout<<"Lista Borrada con exito\n";
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


#endif
