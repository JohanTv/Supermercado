#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

#define CLEAN system("clear")
#include "administrador.cpp"

class Supermercado{
private:
    char nombre[40];
    char ruta_archivo[40];
    DeClientes gestor_clientes;
    DeStock gestor_stock;
    DeVentas gestor_ventas;
    Fecha fecha_actual;
    void ejecutar_operacion(int&);
public:
    Supermercado(char _nombre[]){
        strcpy(nombre, _nombre);
        strcpy(gestor_stock.ruta_archivo,"Datos/Productos.dat\0");
        gestor_stock.cargar_productos();
        strcpy(gestor_clientes.ruta_archivo,"Datos/Clientes.dat\0");
        gestor_clientes.cargar_clientes();
        strcpy(gestor_ventas.ruta_archivo,"Datos/Ventas.dat\0");
        gestor_ventas.cargar_ventas();
        strcpy(ruta_archivo,"Datos/Fecha.txt\0");
        cargar_fecha();
    }
    void mostrar_menu();
    void registrar_productos();
    void registrar_clientes();
    void registrar_compras();
    bool validar_compra(int, int);
    void calcular_ventas();
    void top_productos();
    void estadistica_productos();
    void cargar_fecha();
    void guardar_fecha();
};