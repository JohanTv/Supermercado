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
    int get_codigo(){ return codigo; }
    char* get_nombre(){ return nombre; }
    int get_precio(){ return precio; }
    friend class DeStock;
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
    int get_cantidad(){ return cantidad; }
    void disminuir_cantidad(int monto){ cantidad -= monto; }
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