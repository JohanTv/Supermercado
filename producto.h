#include "fecha.h"

class Producto{
protected:
    int codigo;
    char nombre[100];
    int precio;
public:
    Producto(){}
    void mostrar_datos(){
        cout << "Codigo  >> " << codigo << endl;
        cout << "Nombre  >> " << nombre << endl;
        cout << "Precio  >> s/." << precio << endl;
    }
};

class EnStock : public Producto{
private:
    int cantidad;
public:
    EnStock(){}
    void mostrar_datos_especificos(){
        mostrar_datos();
        cout << "Cantidad >> " << cantidad << endl;
    }
    friend class DeStock;
};

class EnVenta : public Producto{
private:
    int cliente_dni;
    int cantidad_vendida;
    Fecha fecha_venta;
public:
    EnVenta(){}
    friend class DeVentas;
};