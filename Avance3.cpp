//Emiliano Morales Landa
//A01706344


/*
En este avance el polimorfismo se aplica en la seccion de pago para poder tener diferentes salidas en el metodo pago ya sea en caso de que 
el usuario decida pagar con efectico o con tarjeta
*/
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



class Pago{// Esta clase es la que te permite tener un total ya que despues se hereda a las funciones de pago con tarjeta y efectivo para asi poder realizar el coboro
	protected:
		float total;
	public:
		Pago(float);
		virtual void Pagar();
};

Pago::Pago(float _total){//Constructor
	total=_total;
}

void Pago::Pagar(){//Metodo que te muestra la cantidad a pagar
	system("CLS");
	cout<<"El total a pagar es:"<<total<<endl;
}

class PagoTarjeta : public Pago{//Esta es la clase de pago con tarjeta en la cual se guarda el numero de tarjeta y el total a pagar
	protected:
		long NumTarjeta;
	public:
		PagoTarjeta(float,long);
		void Pagar();
		
};

PagoTarjeta::PagoTarjeta(float _total,long _NumTarjeta): Pago(_total){//Constructor que recive el total y el numero de la tarjeta
	NumTarjeta=_NumTarjeta;
}

void PagoTarjeta::Pagar(){//Metodo que te muestra la salida en caso de pagar con tarjeta
	system("CLS");
	cout<<"El cobro de "<<total<<" se ha realizado con exito a la tarjeta "<<NumTarjeta<<endl;
}

class PagoEfectivo : public Pago{//Clase de pago en efectivo que se utiliza en caso de que el usuario pague en efectivo
	protected:
		float CantEfectivo;
	public:
		PagoEfectivo(float,float);
		void Pagar();
		
};

PagoEfectivo::PagoEfectivo(float _total,float _CantEfectivo): Pago(_total){//Constructor que recivirar el monto con el que se va a pagar 
	CantEfectivo=_CantEfectivo;											//por el momento se utilizz para guardar el cambio despues de haber pagado
}

void PagoEfectivo::Pagar(){//metodo el cual es la salida en caso de que el usuario pague en efectivo
	system("CLS");
	cout<<"El cobro de "<<total<<" se ha realizado con exito y su cambio es "<<CantEfectivo<<endl;
}


///////////////////////////////////////////////////
void menu(){
	int opcion,a;
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
				cout<<"Sigue en desarrollo esta parte del proyecto"<<endl;
    		}

			break;
			//Borra un producto de la lista
			case 2:{
    			cout<<"Sigue en desarrollo esta parte del proyecto"<<endl;

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
				S1.VerLista();
				system("pause");
				menu();
				
			}
			break;
			//Caso 6 que Pagar la lista 
			case 6:{
				Pago p1(50.99);
				p1.Pagar();
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

