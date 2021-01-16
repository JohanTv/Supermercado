#include "administrador.h"

class Supermercado{
private:
    char nombre[40];
    DeClientes gestor_clientes;
    DeStock gestor_stock;
    DeVentas gestor_ventas;
    Fecha fecha_actual;
public:
    Supermercado(){}
};