#include "cliente.h"
#include "producto.h"

class Administrador{
protected:
    int cantidad_actual;
    int cantidad_maxima;
public:
    Administrador(){}
};

class DeClientes : public Administrador{
private:
    Cliente* clientes;
public:
    DeClientes(){}
};

class DeStock : public Administrador{
private:
    EnStock productos;
public:
    DeStock(){}
};

class DeVentas : public Administrador{
private:
    EnVenta productos;
public:
    DeVentas(){}
};