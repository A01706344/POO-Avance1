//Emiliano Morales Landa
//A01706344


/*
Es es el Priyecto final para que funcione correctamente es necesesario seguir las instrucciones del archivo README.md
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
	ListaCompras L1(a);

    //Imprime las opciones que va a tener el sistema
    system("CLS");
    cout << "Menu:\n";
    cout << "1. Agregar Producto\n";
    cout << "2. Borrar  Producto\n";
    cout << "3. Ver Lista \n";
    cout << "4. Borrar Lista \n";
    cout << "5. Guardar Lista (.txt) \n";
    cout << "6. Ver Lista Guardada (.txt) \n";
    cout << "7. Pagar \n";
    cout << "8. Salir \n\n";
    //Leer indice que selecciona la opcion del menu
	cin >>opcion;
	
	//Switch donde dependiendo la eleccion efectua un diferente procedimiento
		switch(opcion){


			//Agrega un producto a la lista
			case 1: 
				system("CLS");
				L1.buscarProducto(Lec);
				system("pause");
				menu();
    		
			break;
			//Borra un producto de la lista
			case 2:
				system("CLS");
    			cout<<"Indtroduce el nombre del producto que deseas eliminar"<<endl;
    			cin>>dato;
    			L1.eliminarNodo(lista,dato);
    			cout<<endl;
				system("pause");
				menu();
	
    		break;
			//Caso 3 te muestra la lista en caso de que tenga una guardada
			case 3:
				L1.mostrarLista(lista);
				cout<<endl;
				system("pause");
				menu();
				
			break; 
			//Caso 4 que Borra la lista que se ha creado temporalmente
    		case 4:
    			while(lista != NULL){
    				L1.eliminarLista(lista,dato);
				}
    			system("pause");
    			menu();
    			
			break;  		
    		//Caso 5 que crea un archivo .txt que guara la lisra de los porductos agregados
    		case 5:
				S1.GuardarLista();
				system("pause");
				menu();
				
    		break;
    		//Caso 6 que te muestra la lista que se encuentra guardada en el .txt
			case 6:
				S1.VerLista();
				system("pause");
				menu();
			//Caso 7 que Pagar la lista 
			case 7:
				system("CLS");
				int OP=0;
				cout<<"Pagar con tarejeta (1)/Pagar en Efectivo (2)"<<endl;
				cin>>OP;
				
				switch(OP){
					case 1:{//Caso en el que usuario decidad pagar con tarjeta
						long NumTarjeta;
						cout<<"Inserta el numero de la tarjeta con la que se pagara\n";
						cin>> NumTarjeta;	
						Pago *pag =  new PagoTarjeta(S1.CalculoTotal(),NumTarjeta);
						
						pag->Pagar();   //imprime en caso de que pagues con tarjeta               (con virtual)
						
						system("Pause");
					}
					break;
					
					case 2:{//Caso en el que el usuario decida pagar con efectivo
						float cambio,rev;
						do{
							system("cls");
							cout<<"Con que cantidad de efectivo pagara \n";
							cin>>rev;
						
							if (S1.CalculoTotal()>rev){
								cout<<"Se nesecita mas Efectivo ";
								system("pause");
							}
							else{
								cambio=rev-S1.CalculoTotal();
							}
						}while(S1.CalculoTotal()>rev);
						
						
						Pago *pag =  new PagoEfectivo(S1.CalculoTotal(),cambio);
						
						pag->Pagar();   //imprime en caso de que pagues con efectivo              (con virtual)
						
						system("Pause");
					}
					break;
				}
			
			break;
    	}
}

int main(int argc, char* argv[]){
	
	//Impresion de menu
	menu();
		

		
}

