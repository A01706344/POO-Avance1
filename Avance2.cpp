//Emiliano Morales Landa
//A01706344


/*
En este avance que logre implementar las funciones de guardar, eliminar,ver la lista ademas de las funcion de pago que todas estas funciones por el momneto estan funcionando con valores predefinidos 
posteriormente en futuros avances se podran establecer por el usuario 
*/
#include<iostream>
#include<stdlib.h>
#include<fstream>

using namespace std;

class Producto{
	private:
		string Nombre;
		string Catergoria;
		float Precio;
};

class ListaCompras{
	protected:
		void AgreagarProducto();
		void BorrarPorducto();
};

void AgreagarProducto(){
	
	
}

void BorrarPorducto(){
	
	
}

class SisCompras{
	public:
	void GuardarLista();
	void BorrarLista();	
	void VerLista();
};

void GuardarLista(){
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

void BorrarLista(){
	system("cls");
	remove("Lista.txt");
	cout<<"Lista Borrada con exito\n";
}

void VerLista(){
	system("cls");
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
}

class Pago{
	protected:
		float total;
	public:
		Pago(float);
		void Pagar();
};

Pago::Pago(float _total){
	total=_total;
}

void Pago::Pagar(){
	system("CLS");
	cout<<"El total a pagar es:"<<total<<endl;
}

class Tarjeta: public Pago{
	private:
		int NumTarjeta;
	public:
		Tarjeta(float,int);
		void PagarTarjeta();
};

Tarjeta::Tarjeta(float _total,int _NumTarjeta): Pago(_total){
	NumTarjeta=_NumTarjeta;
}

void Tarjeta::PagarTarjeta(){
	system("CLS");
	cout<<"El cobro de "<<total<<" se ha realizado con exito a la tarjeta "<<NumTarjeta<<endl;
}
class Efectivo: public Pago{
	
};

///////////////////////////////////////////////////
void menu(){
	int opcion;

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
				GuardarLista();
				system("pause");
				menu();
				
	

    		}
    		break;
    		//Caso 4 que Borra el archivo .txt de la lista
    		case 4:{
    			BorrarLista();
    			system("pause");
    			menu();
    			
    	
			}
			break;
			//Caso 5 te muestra la lista en caso de que tenga una guardada
			case 5:{
				VerLista();
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
						Tarjeta t1(50.99,2089);
						t1.PagarTarjeta();
						
					}
					break;
					
					case 2:{
						cout<<"Sigue en desarrollo esta parte del proyecto"<<endl;
						
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
