#include "fecha.h"

class Producto{
protected:
    int codigo;
    char nombre[100];
    int precio;
public:
    Producto(){}
    void mostrar_datos(){
    }
};

class EnStock : public Producto{
private:
    int cantidad;
public:
    EnStock(){}
};

class EnVenta : public Producto{
private:
    int cliente_dni;
    int cantidad_vendida;
    Fecha fecha_venta;
public:
    EnVenta(){}
};