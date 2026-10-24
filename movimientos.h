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
			stock_actual = stock_actual + cantidad;
			return true;
			break;
		}
		case 2:{
			if(cantidad <= stock_actual) {
				stock_actual = stock_actual - cantidad;
				if(stock_actual < 0) {
					stock_actual = 0;
				}
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