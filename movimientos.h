#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H

#include <iostream>
#include <string>

using namespace std;
	
	bool estado_operacion( string codigo_producto, int &stock_actual, int tipo_movimiento, int cantidad){
		
		if(cantidad <= 0) {
		cout << "ERROR, INGRESAR O RETIRAR UNA CANTIDAD ADECUADA" << endl;
		return false;
	}
	
	switch(tipo_movimiento){
		case 1: {
			if(stock_actual <= 200){
				if(cantidad <= 200 - stock_actual){
					stock_actual = stock_actual + cantidad;
					return true;
			}
			else{
					cout << "CANTIDAD MAXIMA A INGRESAR: " << 200 - stock_actual << " , POR FAVOR RESPETAR EL MAXIMO DE LA CANTIDAD" << endl;
					return false;
				}
			}	
			else{
				cout << "ERROR AL AGREGAR PRODUCTOS QUE SUPEREN EL STOCK MAXIMO DEL PRODUCTO" << endl;
				return false;
			}
			break;
		}
		case 2:{
			if(cantidad <= stock_actual) {
				stock_actual = stock_actual - cantidad;
				return true;
			}
			else{
				cout << "ERROR AL RETIRAR UNA CANTIDAD SUPERIOR AL STOCK ACTUAL" << endl;
				return false;
			}
			break;
		}
		default:{
			cout << "SELECCIONE LOS NUMEROS MOSTRADOS POR FAVOR" << endl;
			return false;
			break;
		}
	}
}

#endif