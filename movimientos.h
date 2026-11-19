#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H

#include <iostream>
#include <string>

using namespace std;
 // PERMITE QUE SOLO PUEDA LEER NUMEROS, MAS NO CARACTERES
    int leer_numero(){

    int numero;

    cin >> numero;

    while(cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "ERROR, INGRESE SOLO NUMEROS: ";
        cin >> numero;
    }

    return numero;
}

 // PERMITE CALCULAR EL TOTAL DE STOCK DISPONIBLE PARA AGREGAR PRODUCTOS
    int calcular_espacio_disponible(int stock_actual, int stock_maximo){
    	
    	int resultado;
    	
    	resultado = stock_maximo - stock_actual;
    	
    	return resultado;
	}

// PERMITE VERIFICAR QUE LA CANTIDAD QUE AGREGUE O RETIRE SEA POSITIVA
   bool validar_cantidad_positiva(int cantidad){
   	
   	if(cantidad <= 0) {
		cout << "ERROR, INGRESAR O RETIRAR UNA CANTIDAD ADECUADA" << endl;
		return false;
	}
	return true;
  }
  
  // PERMITE CONFIRMAR ANTES DE REALIZAR LOS MOVIMIENTOS
  bool pedir_confirmacion(char respuesta) {
 
    if(respuesta == 'S') {
    	return true;
	}
	
	return false;
}

// PERMITE VALIDAR QUE EL DNI SEA ESCRITO Y CONTADO CORRECTAMENTE
  bool validar_dni(string dni){

    if(dni.length() != 8){
        return false;
    }

    for(int i = 0; i < 8; i++){
        if(dni[i] < '0' || dni[i] > '9'){
            return false;
        }
    }

    return true;
}

// PERMITE VALIDAR QUE EL RUC SE ESCRIBA CORRECTAMENTE
  bool validar_ruc(string ruc){

    if(ruc.length() != 11){
        return false;
    }

    for(int i = 0; i < 11; i++){
        if(ruc[i] < '0' || ruc[i] > '9'){
            return false;
        }
    }

    return true;
}

// PERMITE LA CONDICION DEL PAGO
  string pedir_condicion_pago(){

    int opcion;

    cout << "CONDICION DE PAGO:" << endl;
    cout << "1. CONTADO" << endl;
    cout << "2. CREDITO" << endl;
    cout << "SELECCIONE LA CONDICION: ";
    opcion = leer_numero();

    while(opcion < 1 || opcion > 2){
        cout << "ERROR, SELECCIONE 1 o 2: ";
        opcion = leer_numero();
    }

    if(opcion == 1){
        return "CONTADO";
    }

    return "CREDITO";
}

// PERMITE REGISTRAR DATOS DEL PROVEEDOR
  void registrar_datos_proveedor(){

    string proveedor;
    string ruc_proveedor;
    string factura;
    string condicion;
    int plazo_dias = 0;

    cout << "--- DATOS DE LA COMPRA ---" << endl;
    cout << "NOMBRE DEL PROVEEDOR: ";
    cin >> proveedor;
    
    cout << "RUC DEL PROVEEDOR: "; 
    cin >> ruc_proveedor;
    
    while(validar_ruc(ruc_proveedor) == false){           
        cout << "ERROR, EL RUC DEBE TENER 11 DIGITOS NUMERICOS: ";
        cin >> ruc_proveedor;
    }
    
    cout << "NUMERO DE FACTURA: ";
    cin >> factura;
    
    condicion = pedir_condicion_pago();
    
    if(condicion == "CREDITO"){              
        cout << "PLAZO DE PAGO EN DIAS: ";
        plazo_dias = leer_numero();

        while(plazo_dias <= 0){
            cout << "ERROR, EL PLAZO DEBE SER MAYOR A CERO: ";
            plazo_dias = leer_numero();
        }
    }
    
    cout << "COMPRA REGISTRADA AL PROVEEDOR " << proveedor << " (RUC " << ruc_proveedor << ") CON FACTURA " << factura << endl;

    if(condicion == "CREDITO"){
        cout << "CONDICION: CREDITO A " << plazo_dias << " DIAS" << endl;
    }
    else{
        cout << "CONDICION: CONTADO" << endl;
    }
}

// PERMITE REGISTRAR LOS DATOS DEL CLIENTE
  void registrar_datos_cliente(){

    string nombre_cliente;
    string dni;
    string ruc;
    string razon_social;
    int tipo_comprobante;

    cout << "--- DATOS DEL CLIENTE ---" << endl;
    cout << "NOMBRE DEL CLIENTE: ";
    cin >> nombre_cliente;
    cout << "DNI DEL CLIENTE: ";
    cin >> dni;

    while(validar_dni(dni) == false){
        cout << "ERROR, EL DNI DEBE TENER 8 DIGITOS: ";
        cin >> dni;
    }

    cout << "TIPO DE COMPROBANTE (1. BOLETA / 2. FACTURA): ";
    tipo_comprobante = leer_numero();

    while(tipo_comprobante < 1 || tipo_comprobante > 2){
        cout << "ERROR, SELECCIONE 1 o 2: ";
        tipo_comprobante = leer_numero();
    }

    if(tipo_comprobante == 1){
        cout << "VENTA REGISTRADA AL CLIENTE " << nombre_cliente << " (DNI " << dni << ") CON BOLETA" << endl;
    }
    else{
        cout << "RUC DEL CLIENTE: ";     
        cin >> ruc;

        while(validar_ruc(ruc) == false){
            cout << "ERROR, EL RUC DEBE TENER 11 DIGITOS NUMERICOS: ";
            cin >> ruc;
        }

        cout << "RAZON SOCIAL: ";
        cin >> razon_social;

        cout << "VENTA REGISTRADA A " << razon_social << " (RUC " << ruc << ") CON FACTURA" << endl;
    }
}

// PERMITE ELEGIR EL METODO DE PAGO
string elegir_metodo_pago(){

    int opcion;

    cout << "METODO DE PAGO:" << endl;
    cout << "1. EFECTIVO" << endl;
    cout << "2. YAPE / PLIN" << endl;
    cout << "3. TARJETA" << endl;
    cout << "SELECCIONE EL METODO: ";
    opcion = leer_numero();

    while(opcion < 1 || opcion > 3){
        cout << "ERROR, SELECCIONE 1, 2 o 3: ";
        opcion = leer_numero();
    }

    if(opcion == 1){
        return "EFECTIVO";
    }
    else if(opcion == 2){
        return "YAPE / PLIN";
    }

    return "TARJETA";
}

//PERMITE PEDIR EL MOTIVO DE LA MERMA
  string pedir_motivo_merma(){

    int opcion;

    cout << "MOTIVO DE LA MERMA:" << endl;
    cout << "1. VENCIDO" << endl;
    cout << "2. DANIADO" << endl;
    cout << "3. ROBO O PERDIDA" << endl;
    cout << "SELECCIONE EL MOTIVO: ";
    opcion = leer_numero();

    while(opcion < 1 || opcion > 3){
        cout << "ERROR, SELECCIONE 1, 2 o 3: ";
        opcion = leer_numero();
    }

    if(opcion == 1){
        return "VENCIDO";
    }
    else if(opcion == 2){
        return "DANIADO";
    }

    return "ROBO O PERDIDA";
}

// PERMITE EL MOTIVO DE DEVOLUCION
string pedir_motivo_devolucion(){

    int opcion;

    cout << "MOTIVO DE LA DEVOLUCION:" << endl;
    cout << "1. PRODUCTO DEFECTUOSO" << endl;
    cout << "2. PRODUCTO EQUIVOCADO" << endl;
    cout << "3. CLIENTE NO CONFORME" << endl;
    cout << "SELECCIONE EL MOTIVO: ";
    opcion = leer_numero();

    while(opcion < 1 || opcion > 3){
        cout << "ERROR, SELECCIONE 1, 2 o 3: ";
        opcion = leer_numero();
    }

    if(opcion == 1){
        return "PRODUCTO DEFECTUOSO";
    }
    else if(opcion == 2){
        return "PRODUCTO EQUIVOCADO";
    }

    return "CLIENTE NO CONFORME";
}

// PERMITE REGISTRAR LA FECHA DE VENCIMIENTO
  void registrar_fecha_vencimiento(){

    int dia;
    int mes;
    int anio;

    cout << "--- FECHA DE VENCIMIENTO DEL LOTE ---" << endl;

    cout << "ANIO: ";
    anio = leer_numero();

    while(anio < 2026 || anio > 2040){
        cout << "ERROR, EL ANIO DEBE ESTAR ENTRE 2026 Y 2040: ";
        anio = leer_numero();
    }

    cout << "MES (1 a 12): ";
    mes = leer_numero();

    while(mes < 1 || mes > 12){
        cout << "ERROR, EL MES DEBE ESTAR ENTRE 1 Y 12: ";
        mes = leer_numero();
    }

    cout << "DIA (1 a 31): ";
    dia = leer_numero();

    while(dia < 1 || dia > 31){
        cout << "ERROR, EL DIA DEBE ESTAR ENTRE 1 Y 31: ";
        dia = leer_numero();
    }

    cout << "LOTE REGISTRADO CON VENCIMIENTO: " << dia << "/" << mes << "/" << anio << endl;
}
  
  // PERMITE REALIZAR LA OPERACION DE INGRESO DE STOCK
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
		registrar_datos_proveedor();
		registrar_fecha_vencimiento();
		return true;
	}
	else{
		cout << "LA CANTIDAD EXCEDE AL ESPACIO DISPONIBLE" << endl;
		return false;
	}
  }
  
  // PERMITE REALIZAR LA OPERACION DE RETIRO DE STOCK
  bool ejecutar_retiro(int &stock_actual, int cantidad){
  	
  	bool respuesta;
	char caracter;
	string metodo_pago;
	  
	  cout << "CONFIRMAR SI RETIRAR PRODUCTOS O NO (S/N): ";
	  cin >> caracter;
	  
	  respuesta = pedir_confirmacion(caracter);
	  
	  if(respuesta == false){
	  	return false;
	  }
  	
  	if(cantidad <= stock_actual){
  		stock_actual = stock_actual - cantidad;
  		cout << "SE RESTARON " << cantidad << " PRODUCTOS CORRECTAMENTE" << endl;
  		registrar_datos_cliente();
        metodo_pago = elegir_metodo_pago();
        cout << "PAGO REGISTRADO CON: " << metodo_pago << endl;
  		return true;
	  }
	  else{
	  	cout << "ERROR AL RETIRAR UNA CANTIDAD SUPERIOR AL STOCK ACTUAL" << endl;
		return false;
	  }
  }
  
  // PERMITE REALIZAR LA OPERACION DE RETIRO POR MERMA
  bool ejecutar_merma(int &stock_actual, int cantidad){
        
        if(cantidad <= 0){
            cout << "ERROR, LA CANTIDAD DE MERMA DEBE SER MAYOR A CERO" << endl;
            return false;
        }
        
        string motivo;
        motivo = pedir_motivo_merma();
        
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
            cout << "SE REGISTRO UNA MERMA DE " << cantidad << " PRODUCTOS (" << motivo << ")" << endl;
            return true;
        }
        else{
            cout << "ERROR: LA MERMA SUPERA EL STOCK ACTUAL DISPONIBLE" << endl;
            return false;
        }
    }
    
    // PERMITE REALIZAR LA OPERACION DE DEVOLUCION DE PRODUCTOS
    bool ejecutar_devolucion_cliente(int &stock_actual, int stock_maximo, int cantidad){
    
    if(cantidad <= 0) {
        cout << "ERROR, LA CANTIDAD DE DEVOLUCION DEBE SER MAYOR A CERO" << endl;
        return false;
    }
    
    int espacio_disponible = calcular_espacio_disponible(stock_actual, stock_maximo);
    
    if(cantidad > espacio_disponible){
        cout << "ERROR: LA DEVOLUCION EXCEDE EL ESPACIO MAXIMO DEL ALMACEN" << endl;
        return false;
    }
    
    string motivo;                        
    motivo = pedir_motivo_devolucion();
    
    bool respuesta;
    char caracter;
    
    cout << "CONFIRMAR DEVOLUCION DE CLIENTE (S/N): ";
    cin >> caracter;
    
    respuesta = pedir_confirmacion(caracter);
    
    if(respuesta == false){
        cout << "OPERACION DE DEVOLUCION CANCELADA." << endl;
        return false;
    }
    
    stock_actual = stock_actual + cantidad;
    cout << "SE REGISTRO LA DEVOLUCION DE " << cantidad << " PRODUCTOS (" << motivo << ")" << endl;
    return true;
}
  
  // LA PRINCIPAL DE ESTE MODULO
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
		case 4:{
			bool devolucion;
			
			devolucion = ejecutar_devolucion_cliente(stock_actual, stock_maximo, cantidad);
			
			return devolucion;
		}
		default:{
			cout << "SELECCIONE LOS NUMEROS MOSTRADOS POR FAVOR" << endl;
			return false;
		}
	}
}
 // CALCULA PORCENTAJE DE LOS PRODUCTOS 
        float porcentaje(int actual, int maximo){
	
	    float resultado_porcentaje;
	
	    resultado_porcentaje = ((static_cast<float>(actual)) / maximo) * 100;
	
	    return resultado_porcentaje;
   }
   
#endif