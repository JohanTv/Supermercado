#include "cliente.h"
#include "producto.h"

// maximos registros
const int MAX_CLIENTES = 300;
const int MAX_STOCK = 350;
const int MAX_VENTAS = 500;

class Administrador{
protected:
    int cantidad_actual;
public:
    Administrador(){ cantidad_actual = 0; }
};

class DeClientes : public Administrador{
private:
    Cliente clientes[MAX_CLIENTES];
public:
    DeClientes() : Administrador() {}
    int buscar_dni(int dni); // buscar un cliente por su DNI
    void registrar_clientes(int cantidad); // Registramos n clientes
    void registrar_cliente(int dni); // Guardamos los datos de un cliente
    void listar_clientes(); // Se lista todos los clientes registrados
    void consultar_datos(); // Se busca un cliente por su DNI
    int capacidad_disponible(); // Retorna cuantos registros disponibles hay, si hay cero no se podra registrar a alguien
};

class DeStock : public Administrador{
private:
    EnStock productos[MAX_STOCK];
public:
    DeStock() : Administrador() {}
    int buscar_codigo(int codigo); // buscar un cliente por su codigo
    void registrar_productos(int cantidad); // Registramos n productos
    void registrar_producto(int codigo); // Guardamos los datos de un producto
    void listar_productos(); // Se lista todos los productos registrados
    void consultar_datos(); // Se busca un producto por su codigo
    int capacidad_disponible(); // Retorna cuantos registros disponibles hay, si hay cero no se podra registrar a alguien
};

class DeVentas : public Administrador{
private:
    EnVenta productos[MAX_VENTAS];
public:
    DeVentas() : Administrador() {} // Falta implementar, esto se hace en la siguiente entrega
};