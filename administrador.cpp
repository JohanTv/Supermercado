#include "administrador.h"

// *************************************************************************************************** //
int DeClientes::buscar_dni(int dni){
    int indice = -1;
    for(int i=0; i<cantidad_actual; ++i){
        if(clientes[i].dni == dni){
            indice = i;
            break;
        }
    }
    return indice; // Si no existe, retorna -1 sino el indice del cliente
}

void DeClientes::registrar_clientes(int cantidad){
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

void DeClientes::registrar_cliente(int dni){
    clientes[cantidad_actual].dni = dni;
    getchar();
    cout << "Nombres     >> "; cin.getline(clientes[cantidad_actual].nombres, 40);
    cout << "Apellidos   >> "; cin.getline(clientes[cantidad_actual].apellidos, 40);
    cout << "\t*** Registro exitoso *** " << endl; getchar();
    ++cantidad_actual;
}

void DeClientes::listar_clientes(){
    if(cantidad_actual == 0){
        cout << "No hay clientes registrados" << endl;
    }else{
        for(int i=0; i < cantidad_actual; ++i){
            cout << "\t*** Cliente N°" << i+1 << " ***" << endl;
            clientes[i].mostrar_datos();
            cout << endl;
        }
    }
    getchar();
}

void DeClientes::consultar_datos(){
    int dni;
    cout << "Ingrese el DNI del cliente >> "; cin >> dni;
    getchar();
    int indice = buscar_dni(dni);
    if(indice == -1)
        cout << "No se ha encontrado el cliente" << endl;
    else{
        cout << "\t*** Datos del cliente ***" << endl;
        clientes[indice].mostrar_datos();
    }
}

int DeClientes::capacidad_disponible(){
    return MAX_CLIENTES - cantidad_actual;
}

// *************************************************************************************************** //

int DeStock::buscar_codigo(int codigo){
    int indice = -1;
    for(int i=0; i<cantidad_actual; ++i){
        if(productos[i].codigo == codigo){
            indice = i;
            break;
        }
    }
    return indice; // Si no existe, retorna -1 sino el indice del producto
}

void DeStock::registrar_productos(int cantidad){
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

void DeStock::registrar_producto(int codigo){
    productos[cantidad_actual].codigo = codigo;
    getchar();
    cout << "Nombre del producto >> "; cin.getline(productos[cantidad_actual].nombre, 40);
    cout << "Precio por unidad   >> "; cin >> productos[cantidad_actual].precio;
    cout << "Cantidad en stock   >> "; cin >> productos[cantidad_actual].cantidad; getchar();
    cout << "\t*** Registro exitoso *** " << endl; getchar();
    ++cantidad_actual;
}

void DeStock::listar_productos(){
    if(cantidad_actual == 0){
        cout << "No hay productos registrados" << endl;
    }else{
        for(int i=0; i < cantidad_actual; ++i){
            cout << "\t*** Producto N°" << i+1 << " ***" << endl;
            productos[i].mostrar_datos_especificos();
            cout << endl;
        }
    }
    getchar();
}

void DeStock::consultar_datos(){
    int codigo;
    cout << "Ingrese el codigo del producto >> "; cin >> codigo;
    getchar();
    int indice = buscar_codigo(codigo);
    if(indice == -1)
        cout << "No se ha encontrado el producto" << endl;
    else{
        cout << "\t*** Datos del producto ***" << endl;
        productos[indice].mostrar_datos_especificos();
    }
}

int DeStock::capacidad_disponible(){
    return MAX_STOCK - cantidad_actual;
}