#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define CLEAN system("clear")
#include "administrador.h"

class Supermercado{
private:
    char nombre[40];
    DeClientes* gestor_clientes;
    DeStock* gestor_stock;
    DeVentas* gestor_ventas;
    Fecha fecha_actual;
    void ejecutar_operacion(int&);
public:
    Supermercado(char nombre[]){
        strcpy(this->nombre, nombre);
        fecha_actual.dia = 16;
        fecha_actual.mes = 1;
        fecha_actual.anio = 2021;
        gestor_clientes = new DeClientes(100);
        gestor_stock = new DeStock(200);
        gestor_ventas = new DeVentas(300);
    }
    void mostrar_menu();
    void registrar_productos();
    void registrar_clientes();
};