#include "supermercado.h"

void Supermercado::mostrar_menu(){
    int opc;
    do{
        CLEAN;
        cout << "*** Bienvenido a " << nombre << " ";
        fecha_actual.mostrar_fecha(); cout << " ***" << endl;
        cout << "\t[01] Registrar productos" << endl;
        cout << "\t[02] Consultar datos de un producto" << endl;
        cout << "\t[03] Listar productos" << endl;
        cout << "\t[04] Registrar clientes" << endl;
        cout << "\t[05] Consultar datos de un cliente" << endl;
        cout << "\t[06] Listar clientes" << endl;
        cout << "\t[07] Registrar compras de un cliente" << endl;
        cout << "\t[08] Calcular total vendido por dia" << endl;
        cout << "\t[09] Obtener los 3 productos mas vendidos en una fecha" << endl;
        cout << "\t[10] Estadistica de productos por fecha" << endl;
        cout << "\t[11] Siguiente dia" << endl;
        cout << "\t[00] Salir" << endl;
        cout << "\tOpcion --> "; cin >> opc;
        ejecutar_operacion(opc);
    }while(opc != 0);
    gestor_clientes.guardar_clientes();
    gestor_stock.guardar_productos();
    gestor_ventas.guardar_ventas();
    guardar_fecha();
    cout <<"\nQue tenga buen dia!....\n"<<endl;
}

void Supermercado::registrar_productos(){
    int cantidad;
    bool ok = false;
    do{
        cout << "Cantidad de productos a registrar >> "; cin >> cantidad;
        getchar();
        if(cantidad < 0){
            cout << "Cantidad incorrecta" << endl;
            getchar();
        }
        else if(cantidad > gestor_stock.capacidad_disponible()){
            cout << "No hay suficiente espacio" << endl;
            getchar();
        }
        else
            ok = true;
    }while(!ok);
    if(cantidad != 0)
        gestor_stock.registrar_productos(cantidad);
}

void Supermercado::registrar_clientes(){
    int cantidad;
    bool ok = false;
    do{
        cout << "Cantidad de clientes a registrar >> "; cin >> cantidad;
        getchar();
        if(cantidad < 0){
            cout << "Cantidad incorrecta" << endl;
            getchar();
        }
        else if(cantidad > gestor_clientes.capacidad_disponible()){
            cout << "No hay suficiente espacio" << endl;
            getchar();
        }
        else
            ok = true;
    }while(!ok);
    if(cantidad != 0)
        gestor_clientes.registrar_clientes(cantidad);
}

void Supermercado::registrar_compras(){
    int dni;
    cout << "Numero de DNI del cliente >> "; cin >> dni; getchar();
    int indice_cliente = gestor_clientes.buscar_dni(dni);
    int productos_vendidos = 0;
    if(indice_cliente == -1){
        cout << "\n\t*** No está registrado el cliente ***" << endl;
        getchar();
    }else{
        int codigo;
        do{
            CLEAN;
            cout << "*** Colocar -1 para concretar las compras ***" << endl;
            cout << "Inserte codigo del producto >> "; cin >> codigo; getchar();
            if(codigo == -1) break;

            int indice_producto = gestor_stock.buscar_codigo(codigo);
            if(indice_producto == -1){
                cout << "No existe el producto" << endl;
            }else{
                if(validar_compra(indice_cliente, indice_producto))
                    ++productos_vendidos;
            }
        }while(true);
        if(productos_vendidos != 0){
            cout << "\n\t*** Compra exitosa ***" << endl;
            getchar();
        }
    }
}

bool Supermercado::validar_compra(int indice_cliente, int indice_producto){
    int cantidad;
    int op;
    cout << "\n*** PRODUCTO ***" <<endl;
    gestor_stock.productos[indice_producto].mostrar_datos_especificos();
    cout << "\nInsertar cantidad >> "; cin >> cantidad; getchar();
    if(cantidad <= 0){
        cout << "Cantidad incorrecta" << endl; getchar();
    }else if(cantidad > gestor_stock.productos[indice_producto].get_cantidad()){
        cout << "No hay suficiente stock" << endl; getchar();
    }else{
        cout << "\nConcretar la compra:" << endl;
        cout << "\t[1] Si" << endl;
        cout << "\t[2] No" << endl;
        cout << "Opcion >> "; cin >> op;
        if(op == 1){
            gestor_stock.productos[indice_producto].disminuir_cantidad(cantidad);
            gestor_ventas.registrar_venta(
                gestor_clientes.clientes[indice_cliente].get_dni(),
                cantidad,
                fecha_actual,
                gestor_stock.productos[indice_producto]);
            return true;
        }
    }
    return false;
}

void Supermercado::calcular_ventas(){
    int op;
    CLEAN;
    cout << "\t*** Calcular Ventas ***" << endl;
    if(gestor_ventas.cantidad_actual == 0){
        cout << "\n\t*** No hay ventas registradas ***" << endl;
        getchar();
        return;
    }
    cout << "\t[1] Ventas de hoy" << endl;
    cout << "\t[2] Elegir fecha" << endl;
    cout << "\t[0] Salir" << endl;
    cout << "Opcion >> "; cin >> op; getchar();
    if(op == 1)
        gestor_ventas.calcular_ventas(fecha_actual);
    else if(op == 2){
        Fecha p;
        cout << "\nInsertar dia  >> "; cin >> p.dia;
        cout << "\nInsertar mes  >> "; cin >> p.mes;
        cout << "\nInsertar anio >> "; cin >> p.anio; getchar();
        gestor_ventas.calcular_ventas(p);
    }
}

void Supermercado::top_productos(){
    int op;
    CLEAN;
    cout << "\t*** Los 3 productos mas vendidos ***" << endl;
    if(gestor_ventas.cantidad_actual == 0){
        cout << "\n\t*** No hay ventas registradas ***" << endl;
        getchar();
        return;
    }
    cout << "\t[1] Ventas de hoy" << endl;
    cout << "\t[2] Elegir fecha" << endl;
    cout << "\t[0] Salir" << endl;
    cout << "Opcion >> "; cin >> op; getchar();
    if(op == 1)
        gestor_ventas.top_productos(fecha_actual);
    else if(op == 2){
        Fecha p;
        cout << "\nInsertar dia  >> "; cin >> p.dia;
        cout << "\nInsertar mes  >> "; cin >> p.mes;
        cout << "\nInsertar anio >> "; cin >> p.anio; getchar();
        gestor_ventas.top_productos(p);
    }
}

void Supermercado::estadistica_productos(){
    int op;
    CLEAN;
    cout << "\t*** Calcular Ventas ***" << endl;
    if(gestor_ventas.cantidad_actual == 0){
        cout << "\n\t*** No hay ventas registradas ***" << endl;
        getchar();
        return;
    }
    cout << "\t[1] Ventas de hoy" << endl;
    cout << "\t[2] Elegir fecha" << endl;
    cout << "\t[0] Salir" << endl;
    cout << "Opcion >> "; cin >> op; getchar();
    if(op == 1)
        gestor_ventas.estadistica_productos(fecha_actual);
    else if(op == 2){
        Fecha p;
        cout << "\nInsertar dia  >> "; cin >> p.dia;
        cout << "\nInsertar mes  >> "; cin >> p.mes;
        cout << "\nInsertar anio >> "; cin >> p.anio; getchar();
        gestor_ventas.estadistica_productos(p);
    }
}

void Supermercado::cargar_fecha(){
    ifstream archivo(ruta_archivo);
    if(!archivo.fail())
        archivo >> fecha_actual.dia >> fecha_actual.mes >> fecha_actual.anio;
    else{
        fecha_actual.dia = 22;
        fecha_actual.mes = 1;
        fecha_actual.anio = 2021;
    }
    archivo.close();
}

void Supermercado::guardar_fecha(){
    ofstream archivo(ruta_archivo);
    archivo << fecha_actual.dia << " " << fecha_actual.mes << " "<< fecha_actual.anio;
    archivo.close();
}

void Supermercado::ejecutar_operacion(int& opc){
    CLEAN;
    switch(opc){
        case 1:{
            registrar_productos();
            break;
        }
        case 2:{
            gestor_stock.consultar_datos();
            getchar();
            break;
        }
        case 3:{
            gestor_stock.listar_productos();
            getchar();
            break;
        }
        case 4:{
            registrar_clientes();
            break;
        }
        case 5:{
            gestor_clientes.consultar_datos();
            getchar();
            break;
        }
        case 6:{
            gestor_clientes.listar_clientes();
            getchar();
            break;
        }
        case 7:{
            registrar_compras();
            break;
        }
        case 8:{
            calcular_ventas();
            break;
        }
        case 9:{
            top_productos();
            break;
        }
        case 10:{
            estadistica_productos();
            break;
        }
        case 11:{
            fecha_actual.aumentar_fecha();
            break;
        }
    }
}