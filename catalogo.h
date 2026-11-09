#ifdef CATALOGO_H
#define CATALOGO_H

#include <iostream>
#include <strings>
#include <vector>
#include <iomanip>

using namespace std;

struct producto {
	string codigo_de_barras;
	string categoria;
	string descripcion;
	string unidad_medida;
	float precio_venta;
};

bool validar_precio(float precio) {
	if (precio <= 0) {
		cout << "[ERROR] El precio de venta debe de ser mayor a cero." << endl;
		return false;
	}
	return true;
}

void registrar_producto(vector<producto> &catalogo) {
    producto p;
	cout <<"REGISTRO DE NUEVO PRODUCTO" << endl;

	cout <<"Ingrese el Codigo de Barras: ";
	cin >> p.codigo_barras;

	cout << "Ingrese categoria (ejem: Abarrotes, Bebidas): ";
    cin >> p.categoria;

	cin.ignore();
    cout << "Ingrese descripcion del producto: ";
    getline(cin, p.descripcion);
	
	cout << "Ingrese unidad de medida (ej. und, kg, lt): ";
    cin >> p.unidad_medida;

	do {
        cout << "Ingrese precio de venta (S/.): ";
        cin >> p.precio_venta;
    } while (!validar_precio(p.precio_venta));

	catalogo.push_back(p);
    cout << "\n[EXITO] ¡Producto registrado exitosamente en el catalogo!" << endl;
}
void mostrar_producto(const producto &p) {
    cout << "       FICHA DE CATALOGO - PRODUCTO     " << endl;
    cout << "Codigo de Barras : " << p.codigo_barras << endl;
    cout << "Categoria        : " << p.categoria << endl;
    cout << "Descripcion      : " << p.descripcion << endl;
    cout << "Unidad de Medida : " << p.unidad_medida << endl;
    cout << "Precio de Venta  : S/. " << fixed << setprecision(2) << p.precio_venta << endl;
}

void listar_catalogo(const vector<producto> &catalogo) {
    if (catalogo.empty()) {
        cout << "\n[AVISO] El catalogo de productos esta actualmente vacio." << endl;
        return;
    }
    
    cout << "         LISTADO GENERAL DE CATALOGO    " << endl;
    for (size_t i = 0; i < catalogo.size(); ++i) {
        cout << "Producto #" << (i + 1) << endl;
        cout << " - Codigo: " << catalogo[i].codigo_barras << endl;
        cout << " - Descripcion: " << catalogo[i].descripcion << endl;
        cout << " - Precio: S/. " << catalogo[i].precio_venta << endl;
    }
}

void buscar_producto_por_codigo(const vector<producto> &catalogo) {
    if (catalogo.empty()) {
        cout << "\n[AVISO] No hay productos registrados para buscar." << endl;
        return;
    }
    
    string codigo_buscado;
    cout << "\nIngrese el codigo de barras a buscar (o escanee): ";
    cin >> codigo_buscado;
    
    bool encontrado = false;
    for (size_t i = 0; i < catalogo.size(); ++i) {
        if (catalogo[i].codigo_barras == codigo_buscado) {
            cout << "\n[ENCONTRADO] ¡Producto localizado en el sistema!" << endl;
            mostrar_producto(catalogo[i]);
            encontrado = true;
            break;
        }
    }
    
    if (!encontrado) {
        cout << "\n[ERROR] El codigo de barras ingresado no se encuentra registrado en el catalogo." << endl;
    }
}

#endif
