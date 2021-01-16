#include "cliente.h"
#include "producto.h"

class Administrador{
protected:
    int cantidad_actual;
    int cantidad_maxima;
public:
    Administrador(){}
    Administrador(int inicio, int max){
        this->cantidad_actual = inicio;
        this->cantidad_maxima = max;
    }
    int capacidad_disponible(){
        return this->cantidad_maxima - this->cantidad_actual;
    }
};

class DeClientes : public Administrador{
private:
    Cliente* clientes;
public:
    DeClientes(){ this->clientes = NULL; }
    DeClientes(int max) : Administrador(0, max){
        this->clientes = new Cliente[this->cantidad_maxima];
    }
    int buscar_dni(int dni){
        int indice = -1;
        for(int i=0; i<this->cantidad_actual; ++i){
            if(this->clientes[i].dni == dni){
                indice = i;
                break;
            }
        }
        return indice;
    }
    void registrar_clientes(int cantidad){
        int dni;
        bool ok;
        for(int i=1; i<=cantidad; ++i){
            ok = false;
            CLEAN;
            cout << "Cliente N°" << i << " a registrar!" << endl;
            do{
                cout << "Ingresar DNI     >> "; cin >> dni;
                if(buscar_dni(dni) != -1){
                    cout << "El DNI se encuentra registrado" << endl;
                }else
                    ok = true;
            }while(!ok);
            registrar_cliente(dni);
        }
    }
    void registrar_cliente(int dni){
        this->clientes[this->cantidad_actual].dni = dni;
        getchar();
        cout << "Nombres     >> "; cin.getline(this->clientes[this->cantidad_actual].nombres, 40);
        cout << "Apellidos   >> "; cin.getline(this->clientes[this->cantidad_actual].apellidos, 40);
        cout << "\t*** Registro exitoso *** " << endl; getchar();
        ++this->cantidad_actual;
    }
    void listar_clientes(){
        if(this->cantidad_actual == 0){
            cout << "No hay clientes registrados" << endl;
        }else{
            for(int i=0; i < this->cantidad_actual; ++i){
                cout << "\t*** Cliente N°" << i+1 << " ***" << endl;
                this->clientes[i].mostrar_datos();
                cout << endl;
            }
        }
        getchar();
    }

    void consultar_datos(){
        int dni;
        cout << "Ingrese el DNI del cliente >> "; cin >> dni;
        getchar();
        int indice = buscar_dni(dni);
        if(indice == -1)
            cout << "No se ha encontrado el cliente" << endl;
        else{
            cout << "\t*** Datos del cliente ***" << endl;
            this->clientes[indice].mostrar_datos();
        }
    }
};

class DeStock : public Administrador{
private:
    EnStock* productos;
public:
    DeStock(){ this->productos = NULL; }
    DeStock(int max) : Administrador(0, max){
        this->productos = new EnStock[this->cantidad_maxima];
    }
    int buscar_codigo(int codigo){
        int indice = -1;
        for(int i=0; i<this->cantidad_actual; ++i){
            if(this->productos[i].codigo == codigo){
                indice = i;
                break;
            }
        }
        return indice;
    }
    void registrar_productos(int cantidad){
        int codigo;
        bool ok;
        for(int i=1; i<=cantidad; ++i){
            ok = false;
            CLEAN;
            cout << "Producto N°" << i << " a registrar!" << endl;
            do{
                cout << "Ingresar codigo     >> "; cin >> codigo;
                if(buscar_codigo(codigo) != -1){
                    cout << "El codigo se encuentra registrado" << endl;
                }else
                    ok = true;
            }while(!ok);
            registrar_producto(codigo);
        }
    }
    void registrar_producto(int codigo){
        this->productos[this->cantidad_actual].codigo = codigo;
        getchar();
        cout << "Nombre del producto >> "; cin.getline(this->productos[this->cantidad_actual].nombre, 40);
        cout << "Precio por unidad   >> "; cin >> this->productos[this->cantidad_actual].precio;
        cout << "Cantidad en stock   >> "; cin >> this->productos[this->cantidad_actual].cantidad; getchar();
        cout << "\t*** Registro exitoso *** " << endl; getchar();
        ++this->cantidad_actual;
    }
    void listar_productos(){
        if(this->cantidad_actual == 0){
            cout << "No hay productos registrados" << endl;
        }else{
            for(int i=0; i < this->cantidad_actual; ++i){
                cout << "\t*** Producto N°" << i+1 << " ***" << endl;
                this->productos[i].mostrar_datos_especificos();
                cout << endl;
            }
        }
        getchar();
    }
    void consultar_datos(){
        int codigo;
        cout << "Ingrese el codigo del producto >> "; cin >> codigo;
        getchar();
        int indice = buscar_codigo(codigo);
        if(indice == -1)
            cout << "No se ha encontrado el producto" << endl;
        else{
            cout << "\t*** Datos del producto ***" << endl;
            this->productos[indice].mostrar_datos_especificos();
        }
    }
};

class DeVentas : public Administrador{
private:
    EnVenta* productos;
public:
    DeVentas(){ this->productos = NULL; }
    DeVentas(int max) : Administrador(0, max){
        this->productos = new EnVenta[this->cantidad_maxima];
    }
};