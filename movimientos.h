#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H

#include <iostream>
#include <string>

using namespace std;

    int calcular_espacio_disponible(int stock_actual, int stock_maximo){
    	
    	int resultado;
    	
    	resultado = stock_maximo - stock_actual;
    	
    	return resultado;
	}

   bool validar_cantidad_positiva(int cantidad){
   	
   	if(cantidad <= 0) {
		cout << "ERROR, INGRESAR O RETIRAR UNA CANTIDAD ADECUADA" << endl;
		return false;
	}
	return true;
  }
  
  bool pedir_confirmacion(char respuesta) {
 
    if(respuesta == 'S') {
    	return true;
	}
	
	return false;
}
  
  bool ejecutar_ingreso(int &stock_actual, int stock_maximo, int cantidad){
  	
  	if(stock_actual > stock_maximo) {
  		cout << "ERROR AL INGRESAR PRODUCTOS, SUPERA EL MAXIMO" << endl;
  		return false;
	  }
	  
	  
	  
	  bool respuesta;
	  char caracter;
	  
	  cout << "CONFIRMAR SI INGRESAR PRODUCTOS O NO (S/N): ";
	  cin >> caracter;
	  
	  respuesta = pedir_confirmacion(caracter);
	  
	  if(respuesta == false){
	  	return false;
	  }
	  
	int espacio_disponible = calcular_espacio_disponible(stock_actual, stock_maximo);
	  
	if(cantidad <= espacio_disponible){
		stock_actual = stock_actual + cantidad;
		cout << "SE AGREGARON " << cantidad << " PRODUCTOS CORRECTAMENTE" << endl;
		return true;
	}
	else{
		cout << "LA CANTIDAD EXCEDE AL ESPACIO DISPONIBLE" << endl;
		return false;
	}
  }
  
  bool ejecutar_retiro(int &stock_actual, int cantidad){
  	
  	bool respuesta;
	char caracter;
	  
	  cout << "CONFIRMAR SI RETIRAR PRODUCTOS O NO (S/N): ";
	  cin >> caracter;
	  
	  respuesta = pedir_confirmacion(caracter);
	  
	  if(respuesta == false){
	  	return false;
	  }
  	
  	if(cantidad <= stock_actual){
  		stock_actual = stock_actual - cantidad;
  		cout << "SE RESTARON " << cantidad << " PRODUCTOS CORRECTAMENTE" << endl;
  		return true;
	  }
	  else{
	  	cout << "ERROR AL RETIRAR UNA CANTIDAD SUPERIOR AL STOCK ACTUAL" << endl;
		return false;
	  }
  }
  
  bool ejecutar_merma(int &stock_actual, int cantidad){
        
        if(cantidad <= 0){
            cout << "ERROR, LA CANTIDAD DE MERMA DEBE SER MAYOR A CERO" << endl;
            return false;
        }
        
        bool respuesta;
	    char caracter;
	  
	  cout << "CONFIRMAR SI RETIRAR PRODUCTOS POR MERMA O NO (S/N): ";
	  cin >> caracter;
	  
	  respuesta = pedir_confirmacion(caracter);
	  
	  if(respuesta == false){
	  	return false;
	  }
        
        if(cantidad <= stock_actual){
            stock_actual = stock_actual - cantidad;
            cout << "SE REGISTRO UNA MERMA DE " << cantidad << " PRODUCTOS (VENCIDOS/DANIADOS)" << endl;
            return true;
        }
        else{
            cout << "ERROR: LA MERMA SUPERA EL STOCK ACTUAL DISPONIBLE" << endl;
            return false;
        }
    }
  
	bool estado_operacion(int &stock_actual, int stock_maximo, int tipo_movimiento, int cantidad){
		
		bool validacion;
		
		validacion = validar_cantidad_positiva(cantidad);
		
		if(!validacion){
			return false;
		}
		
	switch(tipo_movimiento){
		case 1: {
			bool ingreso;
			
			ingreso = ejecutar_ingreso(stock_actual, stock_maximo, cantidad);
			
			return ingreso;
		}
		case 2:{
			bool retiro;
			
			retiro = ejecutar_retiro(stock_actual, cantidad);
			
			return retiro;
		}
		case 3:{
			bool merma;
			
			merma = ejecutar_merma(stock_actual, cantidad);
			
			return merma;
		}
		default:{
			cout << "SELECCIONE LOS NUMEROS MOSTRADOS POR FAVOR" << endl;
			return false;
		}
	}
}

        float porcentaje(int actual, int maximo){
	
	    float resultado_porcentaje;
	
	    resultado_porcentaje = ((static_cast<float>(actual)) / maximo) * 100;
	
	    return resultado_porcentaje;
   }
   
#endif