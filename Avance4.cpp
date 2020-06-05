//Emiliano Morales Landa
//A01706344


/*
En este avance la implementacion de la clase abstracta se puede observar en la clase de pago que hedera a la de pago con tarjeta y la de pago con efectivo
en el metodo de pagar.

Bueno ahora va la explicacion de este avance ya que todavia no esta al 100% pero ya tienen mucha mas funcionalidad que antes porque ahora ya puedes ir
agrendando productos a la lista asi como tambien eliminandolos solo que ahora surgio el incomveniente que aun lo he logrado mesclar ambas listas
junto con los precios pero espero que para la entrega final ya haya logrado unificar esas 2 listas. 
*/

#include<iostream>
#include<stdlib.h>

#include"Siscompras.h"
#include"Cpapago.h"
#include"Listacompras.h"


using namespace std;



///////////////////////////////////////////////////
void menu(){
	int opcion,a;
	string dato;
	SisCompras S1(a);

    //Imprime las opciones que va a tener el sistema
    system("CLS");
    cout << "Menu:\n";
    cout << "1. Agregar Producto\n";
    cout << "2. Borrar  Producto\n";
    cout << "3. Guardar Lista \n";
    cout << "4. Borrar Lista \n";
    cout << "5. Ver Lista \n";
    cout << "6. Pagar \n\n";
    //Leer indice que selecciona la opcion del menu
	cin >>opcion;
	
	//Switch donde dependiendo la eleccion efectua un diferente procedimiento
		switch(opcion){


			//Agrega un producto a la lista
			case 1: {
				system("CLS");
				cout<<"Indtroduce el nombre del producto que deseas elegir"<<endl;
				cin>>dato;
				insertarLista(lista,dato);
				system("pause");
				menu();
    		}

			break;
			//Borra un producto de la lista
			case 2:{
				system("CLS");
    			cout<<"Indtroduce el nombre del producto que deseas elegir"<<endl;
    			cin>>dato;
    			eliminarNodo(lista,dato);
    			cout<<endl;
				system("pause");
				menu();

    		}
    			
    		break;
    		//Caso 3 que crea un archivo .txt que guara la lisra de los porductos agregados
    		case 3:{
				S1.GuardarLista();
				system("pause");
				menu();
				
	

    		}
    		break;
    		//Caso 4 que Borra el archivo .txt de la lista
    		case 4:{
    			S1.BorrarLista();
    			system("pause");
    			menu();
    			
    	
			}
			break;
			//Caso 5 te muestra la lista en caso de que tenga una guardada
			case 5:{
				//S1.VerLista();
				mostrarLista(lista);
				cout<<endl;
				system("pause");
				menu();
				
			}
			break;
			//Caso 6 que Pagar la lista 
			case 6:{
				system("CLS");
				int OP=0;
				cout<<"Pagar con tarejeta (1)/Pagar en Efectivo (2)"<<endl;
				cin>>OP;
				switch(OP){
					case 1:{
						Pago *pag =  new PagoTarjeta(50.99,20895960);
						pag->Pagar();   //imprime en caso de que pagues con tarjeta               (con virtual)
						system("Pause");
						
					}
					break;
					
					case 2:{
						Pago *pag =  new PagoEfectivo(50.99,89.99);
						pag->Pagar();   //imprime en caso de que pagues con efectivo              (con virtual)
						system("Pause");
						
					}
					break;
				}
			}
			break;
    	}
}

int main(int argc, char* argv[]){
	
	//Impresion de menu
	menu();
		

		
}

