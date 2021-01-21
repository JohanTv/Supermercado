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

void DeClientes::cargar_clientes(){
    ifstream archivo(ruta_archivo, ios::binary);
    if(!archivo.fail()){
        Cliente p;
        archivo.read( (char *) &p, sizeof(Cliente) );
        while(!archivo.eof()){
            clientes[cantidad_actual] = p;
            ++cantidad_actual;
            archivo.read( (char *) &p, sizeof(Cliente) );
        }
        cantidad_anterior = cantidad_actual;
    }else
        cantidad_anterior = 0;
    archivo.close();
}

void DeClientes::guardar_clientes(){
    if(cantidad_actual != cantidad_anterior){
        ofstream archivo(ruta_archivo, ios::binary | ios::app);
        for(int i=cantidad_anterior; i < cantidad_actual; ++i){
            archivo.write( (char *) &clientes[i], sizeof(Cliente));
        }
        archivo.close();
    }
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

void DeStock::cargar_productos(){
    ifstream archivo(ruta_archivo, ios::binary);
    if(!archivo.fail()){
        EnStock p;
        archivo.read( (char *) &p, sizeof(EnStock) );
        while(!archivo.eof()){
            productos[cantidad_actual] = p;
            ++cantidad_actual;
            archivo.read( (char *) &p, sizeof(EnStock) );
        }
        cantidad_anterior = cantidad_actual;
    }else
        cantidad_anterior = 0;
    archivo.close();
}

void DeStock::guardar_productos(){
    if(cantidad_actual != cantidad_anterior){
        ofstream archivo(ruta_archivo, ios::binary | ios::app);
        for(int i=cantidad_anterior; i < cantidad_actual; ++i){
            archivo.write( (char *) &productos[i], sizeof(EnStock));
        }
        archivo.close();
    }
}

// *************************************************************************************************** //
void DeVentas::registrar_venta(int dni, int cantidad, Fecha fecha_actual, EnStock p){
    productos[cantidad_actual].cliente_dni = dni;
    productos[cantidad_actual].cantidad_vendida = cantidad;
    productos[cantidad_actual].fecha_venta = fecha_actual;
    productos[cantidad_actual].codigo = p.get_codigo();
    strcpy(productos[cantidad_actual].nombre, p.get_nombre());
    productos[cantidad_actual].precio = p.get_precio();
    ++cantidad_actual;
}

void DeVentas::calcular_ventas(Fecha fecha){
    Contador vendidos[MAX_VENTAS];
    int cantidad = 0;
    for(int i=0; i<cantidad_actual; ++i){
        if(productos[i].fecha_venta == fecha){
            aumentar_contador(vendidos, cantidad, productos[i]);
        }
    }
    cout << "\t\t*** Ventas "; fecha.mostrar_fecha(); cout << "***" << endl;
    if(cantidad == 0){
        cout << "No se registraron ventas en este dia" << endl;
        getchar();
        return;
    }
    int cantidad_total = 0;
    int monto_total = 0;
    for(int i=0; i<cantidad; ++i){
        cantidad_total += vendidos[i].cantidad;
        monto_total += vendidos[i].monto_acumulado;
    }
    cout << "\tTotal de productos vendidos >> " << cantidad_total << endl;
    cout << "\tMonto total generado        >> s/." << monto_total << endl;
    getchar();
}

void DeVentas::estadistica_productos(Fecha fecha){
    Contador vendidos[MAX_VENTAS];
    int cantidad = 0;
    for(int i=0; i<cantidad_actual; ++i){
        if(productos[i].fecha_venta == fecha){
            aumentar_contador(vendidos, cantidad, productos[i]);
        }
    }
    cout << "\t\t*** Ventas "; fecha.mostrar_fecha(); cout << "***" << endl;
    if(cantidad == 0){
        cout << "No se registraron ventas en este dia" << endl;
        getchar();
        return;
    }
    for(int i=0; i<cantidad; ++i){
        cout << "\n*** Producto N°" << i+1 << " ***" << endl;
        vendidos[i].mostrar_datos();
    }
    getchar();
}

void DeVentas::aumentar_contador(Contador vendidos[], int& limite, EnVenta p){
    bool ok = false;
    for(int i=0; i<limite; ++i){
        if(vendidos[i].codigo == p.codigo){
            vendidos[i].aumentar_cantidad(p.cantidad_vendida);
            vendidos[i].aumentar_monto(p.cantidad_vendida*p.precio);
            ok = true;
        }
    }
    if(!ok){
        vendidos[limite].codigo = p.codigo;
        vendidos[limite].cantidad = p.cantidad_vendida;
        vendidos[limite].monto_acumulado = p.cantidad_vendida*p.precio;
        strcpy(vendidos[limite].nombre, p.nombre);
        ++limite;
    }
}

void DeVentas::top_productos(Fecha fecha){
    Contador vendidos[MAX_VENTAS];
    int cantidad = 0;
    for(int i=0; i<cantidad_actual; ++i){
        if(productos[i].fecha_venta == fecha){
            aumentar_contador(vendidos, cantidad, productos[i]);
        }
    }
    cout << "\t\t*** Productos del "; fecha.mostrar_fecha(); cout << "***" << endl;
    if(cantidad == 0){
        cout << "No se registraron ventas en este dia" << endl;
        getchar();
        return;
    }
    for(int i = cantidad; i > 0; i--){
        for(int j = 0; j < i-1; j++){
            if(vendidos[j].cantidad < vendidos[j+1].cantidad){
                Contador aux = vendidos[j];
                vendidos[j] = vendidos[j+1];
                vendidos[j+1] = aux;
            }
        }
    }
    int lim;
    if(cantidad < 3) lim = cantidad;
    else lim = 3;
    for(int i=0; i<lim; ++i){
        cout << "\n*** Producto N°" << i+1 << " ***" << endl;
        vendidos[i].mostrar_datos();
    }
    getchar();
}

int DeVentas::capacidad_disponible(){
    return MAX_VENTAS - cantidad_actual;
}

void DeVentas::cargar_ventas(){
    ifstream archivo(ruta_archivo, ios::binary);
    if(!archivo.fail()){
        EnVenta p;
        archivo.read( (char *) &p, sizeof(EnVenta) );
        while(!archivo.eof()){
            productos[cantidad_actual] = p;
            ++cantidad_actual;
            archivo.read( (char *) &p, sizeof(EnVenta) );
        }
        cantidad_anterior = cantidad_actual;
    }else
        cantidad_anterior = 0;
    archivo.close();
}

void DeVentas::guardar_ventas(){
    if(cantidad_actual != cantidad_anterior){
        ofstream archivo(ruta_archivo, ios::binary | ios::app); //Escribir al final del archivo.
        for(int i=cantidad_anterior; i < cantidad_actual; ++i){
            archivo.write( (char *) &productos[i], sizeof(EnVenta));
        }
        archivo.close();
    }
}