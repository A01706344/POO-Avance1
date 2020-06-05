#ifndef CPAPAGO_H
#define CPAPAGO_H

#include<iostream>
#include<stdlib.h>

using namespace std;


class Pago{// Esta clase es la que te permite tener un total ya que despues se hereda a las funciones de pago con tarjeta y efectivo para asi poder realizar el coboro
	protected:
		float total;
	public:
		Pago(float);
		virtual void Pagar()=0;
};

Pago::Pago(float _total){//Constructor
	total=_total;
}

/*
void Pago::Pagar(){//Metodo que te muestra la cantidad a pagar
	system("CLS");
	cout<<"El total a pagar es:"<<total<<endl;
}
*/

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


#endif
