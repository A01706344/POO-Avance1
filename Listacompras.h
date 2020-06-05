#ifndef LISTACOMPRAS_H
#define LISTACOMPRAS_H

#include<iostream>
#include<stdlib.h>

using namespace std;

struct Nodo{
	string dato;
	Nodo *siguiente;
};

void insertarLista(Nodo *&,string);
void mostrarLista(Nodo *);
void eliminarNodo(Nodo *&,string);

Nodo *lista = NULL;

void insertarLista(Nodo *&lista,string n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	
	Nodo *aux1 = lista;
	Nodo *aux2;
	
	while((aux1 != NULL) ){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	
	if(lista == aux1){
		lista = nuevo_nodo;
	}
	else{
		aux2->siguiente = nuevo_nodo;
	}
	nuevo_nodo->siguiente = aux1;
}

void mostrarLista(Nodo *lista){
	system("CLS");
	Nodo *actual = new Nodo();
	actual = lista;
	
	while(actual != NULL){
		cout<<actual->dato<<" ";
		actual = actual->siguiente;
	}
}

void eliminarNodo(Nodo *&lista,string n){
	if(lista != NULL){
		Nodo *aux_borrar;
		Nodo *anterior = NULL;
		
		aux_borrar = lista;
		
		while((aux_borrar != NULL) && (aux_borrar->dato !=n)){
			anterior = aux_borrar;
			aux_borrar = aux_borrar->siguiente;
		}
		
		if(aux_borrar == NULL){
			cout<<"El elemento no ha sido encontrado";
		}
		
		else if(anterior == NULL){
			lista = lista->siguiente;
			delete aux_borrar;
		}
		else{
			anterior->siguiente = aux_borrar->siguiente;
			delete aux_borrar;
		}
	}
}




#endif
