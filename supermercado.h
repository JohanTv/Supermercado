#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define CLEAN system("cls")
#include "administrador.cpp"

class Supermercado{
private:
    char nombre[40];
    DeClientes gestor_clientes;
    DeStock gestor_stock;
    DeVentas gestor_ventas;
    Fecha fecha_actual;
    void ejecutar_operacion(int&);
public:
    Supermercado(char _nombre[]){
        strcpy(nombre, _nombre);
        fecha_actual.dia = 16;
        fecha_actual.mes = 1;
        fecha_actual.anio = 2021;
    }
    void mostrar_menu();
    void registrar_productos();
    void registrar_clientes();
};