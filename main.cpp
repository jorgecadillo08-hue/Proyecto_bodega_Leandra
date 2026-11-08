
#include <iostream>
#include "movimientos.h"

using namespace std;

int main() {
	
	int stock_actual, tipo_movimiento, cantidad, stock_maximo;
	float estado;
	
	cout << "SESION DE PRUEBA" << endl;

	cout << "STOCK ACTUAL ES: ";
	cin >> stock_actual;
	
	cout << "STOCK MAXIMO DEL PRODUCTO: ";
	cin >> stock_maximo;
	
	cout << "SELECCIONE EL TIPO DE MOVIMIENTO: " << endl;
	
	cout << "1. AGREGAR STOCK AL ALMACEN" << endl;
	
	cout << "2. SALIDA DE STOCK DEL ALMACEN" << endl;
	
	cout << "SELECCIONE SU TIPO DE MOVIMIENTO POR FAVOR: ";
	cin >> tipo_movimiento;
	
	cout << "CANTIDAD A INGRESAR O RETIRAR: ";
	cin >> cantidad;
	
	bool exito = estado_operacion(stock_actual, stock_maximo, tipo_movimiento, cantidad);
	
	if(exito) {
		cout << "OPERACION EXITOSA" << endl;
		
		cout << "STOCK FINAL: " << stock_actual << endl;
		
		estado = porcentaje(stock_actual, stock_maximo);
		
		cout << "EL PORCENTAJE DE PRODUCTOS ACTUALES ES: " << estado << " %" << endl;
	}
	else{
		cout << "OPERACION FALLIDA" << endl;
	}
	
	return 0;
}