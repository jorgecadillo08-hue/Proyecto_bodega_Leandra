#include <iostream>
#include <vector>
#include <string>
#include "catalogo.h"
#include "movimientos.h"
#include "kardex.h"

using namespace std;

void precargar_datos_demo(vector<producto> &catalogo) {
    producto p1 = {"77501234", "Abarrotes", "Arroz Extra 1kg", "kg", 4.50f};
    producto p2 = {"77505678", "Bebidas", "Agua Mineral 600ml", "und", 2.00f};
    producto p3 = {"77509999", "Abarrotes", "Aceite Vegetal 1L", "lt", 8.50f};
    catalogo.push_back(p1);
    catalogo.push_back(p2);
    catalogo.push_back(p3);
}

void menu_catalogo(vector<producto> &catalogo) {
    int sub_opcion = 0;
    do {
        cout << "\n--- SUBMENU: MODULO 1 (CATALOGO) ---" << endl;
        cout << "1. Registrar Nuevo Producto" << endl;
        cout << "2. Ver Listado General" << endl;
        cout << "3. Buscar Producto por Codigo" << endl;
        cout << "4. Volver al Menu Principal" << endl;
        cout << "Seleccione: ";
        cin >> sub_opcion;
        switch (sub_opcion) {
            case 1:
                registrar_producto(catalogo);
                break;
            case 2:
                listar_catalogo(catalogo);
                break;
            case 3:
                consultar_producto_interactivo(catalogo);
                break;
            case 4:
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (sub_opcion != 4);
}

void menu_movimientos(vector<producto> &catalogo, int &stock_actual, int &stock_maximo, vector<transaccionKardex> &kardex) {
    if (catalogo.empty()) {
        cout << "\n[AVISO] Catalogo vacio. Registre productos primero." << endl;
        return;
    }

    string codigo;
    cout << "\nIngrese codigo del producto a operar: ";
    cin >> codigo;
    int idx = buscar_producto_por_codigo(catalogo, codigo);
    if (idx == -1) {
        cout << "Producto no encontrado en el catalogo." << endl;
        return;
    }

    cout << "\nProducto Seleccionado: " << catalogo[idx].descripcion << endl;
    cout << "Precio Unitario: S/. " << catalogo[idx].precio_venta << endl;
    cout << "SESION DE PRUEBA DE MOVIMIENTOS" << endl;
    cout << "STOCK ACTUAL ES: " << stock_actual << endl;
    cout << "STOCK MAXIMO DEL PRODUCTO: ";
    cin >> stock_maximo;

    int tipo_movimiento, cantidad;
    cout << "SELECCIONE EL TIPO DE MOVIMIENTO:" << endl;
    cout << "1. AGREGAR STOCK AL ALMACEN" << endl;
    cout << "2. SALIDA DE STOCK DEL ALMACEN" << endl;
    cout << "SELECCIONE SU TIPO DE MOVIMIENTO POR FAVOR: ";
    cin >> tipo_movimiento;

    cout << "CANTIDAD A INGRESAR O RETIRAR: ";
    cin >> cantidad;

    bool exito = estado_operacion(stock_actual, stock_maximo, tipo_movimiento, cantidad);

    if (exito) {
        cout << "OPERACION EXITOSA" << endl;
        cout << "STOCK FINAL: " << stock_actual << endl;
        float estado = porcentaje(stock_actual, stock_maximo);
        cout << "EL PORCENTAJE DE PRODUCTOS ACTUALES ES: " << estado << " %" << endl;

        string t_str = (tipo_movimiento == 1) ? "INGRESO" : "RETIRO";
        registrar_kardex(kardex, catalogo[idx].codigo_barras, t_str, cantidad, stock_actual, catalogo[idx].precio_venta);
    } else {
        cout << "OPERACION FALLIDA" << endl;
    }
}

void menu_monitoreo(vector<transaccionKardex> &kardex, int stock_actual, int stock_minimo) {
    int sub_opcion = 0;
    do {
        cout << "\n--- SUBMENU: MODULO 3 (MONITOREO Y KARDEX) ---" << endl;
        cout << "1. Verificar Alertas de Stock" << endl;
        cout << "2. Ver Historial de Kardex (en Soles)" << endl;
        cout << "3. Filtrar Kardex por Codigo" << endl;
        cout << "4. Ver Total Movimientos" << endl;
        cout << "5. Limpiar Kardex" << endl;
        cout << "6. Volver al Menu Principal" << endl;
        cout << "Seleccione: ";
        cin >> sub_opcion;
        switch (sub_opcion) {
            case 1:
                verificar_alerta_stock(stock_actual, stock_minimo);
                break;
            case 2:
                mostrar_kardex(kardex);
                break;
            case 3: {
                string cod;
                cout << "Ingrese codigo: ";
                cin >> cod;
                buscar_kardex_por_producto(kardex, cod);
                break;
            }
            case 4:
                cout << "Total operaciones registradas: " << contar_total_movimientos(kardex) << endl;
                break;
            case 5:
                limpiar_historial_kardex(kardex);
                break;
            case 6:
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (sub_opcion != 6);
}

int main() {
    vector<producto> catalogo;
    vector<transaccionKardex> historial_kardex;

    int stock_actual = 20;
    int stock_maximo = 100;
    int stock_minimo = 10;

    precargar_datos_demo(catalogo);

    int opcion = 0;
    do {
        cout << "   SISTEMA DE GESTION BODEGA LEANDRA    " << endl;
        cout << "1. Modulo 1: Catalogo de Productos" << endl;
        cout << "2. Modulo 2: Movimientos de Almacen" << endl;
        cout << "3. Modulo 3: Monitoreo, Alertas y Kardex" << endl;
        cout << "4. Salir del Sistema" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                menu_catalogo(catalogo);
                break;
            case 2:
                menu_movimientos(catalogo, stock_actual, stock_maximo, historial_kardex);
                break;
            case 3:
                menu_monitoreo(historial_kardex, stock_actual, stock_minimo);
                break;
            case 4:
                cout << "Saliendo del sistema de la Bodega Leandra. ¡Hasta pronto!" << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
}
