#ifndef KARDEX_H
#define KARDEX_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct transaccionKardex {
    string fecha_hora;
    string codigo_producto;
    string tipo_movimiento;
    int cantidad;
    int stock_resultante;
    float costo_unitario;
};

void registrar_kardex(vector<transaccionKardex> &kardex, string codigo_prod, string tipo, int cantidad, int stock_actual, float costo) {
    transaccionKardex t;
    t.fecha_hora = "2026-11-08 18:00";
    t.codigo_producto = codigo_prod;
    t.tipo_movimiento = tipo;
    t.cantidad = cantidad;
    t.stock_resultante = stock_actual;
    t.costo_unitario = costo;
    kardex.push_back(t);
}

void mostrar_kardex(const vector<transaccionKardex> &kardex) {
    cout << "\n========================================" << endl;
    cout << "      HISTORIAL DE KARDEX   " << endl;
    cout << "========================================" << endl;
    if (kardex.empty()) {
        cout << "[AVISO] No hay movimientos registrados." << endl;
        cout << "========================================" << endl;
        return;
    }
    for (size_t i = 0; i < kardex.size(); ++i) {
        cout << "Operacion #" << (i + 1) << endl;
        cout << " - Fecha/Hora : " << kardex[i].fecha_hora << endl;
        cout << " - Cod. Prod. : " << kardex[i].codigo_producto << endl;
        cout << " - Movimiento : " << kardex[i].tipo_movimiento << endl;
        cout << " - Cantidad   : " << kardex[i].cantidad << endl;
        cout << " - Stock Final: " << kardex[i].stock_resultante << endl;
        cout << " - Costo U.   : S/. " << fixed << setprecision(2) << kardex[i].costo_unitario << endl;
        cout << "----------------------------------------" << endl;
    }
}

void verificar_alerta_stock(int stock_actual, int stock_minimo) {
    cout << "\n----------------------------------------" << endl;
    cout << "       MONITOREO Y ALERTAS DE STOCK     " << endl;
    cout << "----------------------------------------" << endl;
    cout << "Stock Actual : " << stock_actual << endl;
    cout << "Stock Minimo : " << stock_minimo << endl;
    if (stock_actual <= stock_minimo) {
        cout << "[ALERTA CRITICA] ¡Stock por debajo del minimo!" << endl;
        cout << "-> Accion: Reabastecimiento urgente requerido." << endl;
    } else {
        cout << "[ESTADO OPTIMO] Inventario en rango adecuado." << endl;
    }
    cout << "----------------------------------------" << endl;
}

void buscar_kardex_por_producto(const vector<transaccionKardex> &kardex, const string &codigo_buscado) {
    cout << "\n--- FILTRO KARDEX PARA: " << codigo_buscado << " ---" << endl;
    bool encontrado = false;
    for (size_t i = 0; i < kardex.size(); ++i) {
        if (kardex[i].codigo_producto == codigo_buscado) {
            cout << "Fecha: " << kardex[i].fecha_hora 
                 << " | Tipo: " << kardex[i].tipo_movimiento 
                 << " | Cant: " << kardex[i].cantidad 
                 << " | Stock Fin: " << kardex[i].stock_resultante << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "[AVISO] Sin registros para el codigo." << endl;
    }
}

int contar_total_movimientos(const vector<transaccionKardex> &kardex) {
    return static_cast<int>(kardex.size());
}

void limpiar_historial_kardex(vector<transaccionKardex> &kardex) {
    kardex.clear();
    cout << "[SISTEMA] Historial de kardex reiniciado con exito." << endl;
}

bool validar_estado_auditoria(const vector<transaccionKardex> &kardex) {
    if (kardex.size() > 0) {
        return true;
    }
    return false;
}

#endif
