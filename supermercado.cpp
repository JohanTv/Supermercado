#include "supermercado.h"

void Supermercado::mostrar_menu(){
    int opc;
    do{
        CLEAN;
        cout << "*** Bienvenido a " << this->nombre << " ";
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
        else if(cantidad > this->gestor_stock->capacidad_disponible()){
            cout << "No hay suficiente espacio" << endl;
            getchar();
        }
        else
            ok = true;
    }while(!ok);
    if(cantidad != 0)
        gestor_stock->registrar_productos(cantidad);
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
        else if(cantidad > this->gestor_clientes->capacidad_disponible()){
            cout << "No hay suficiente espacio" << endl;
            getchar();
        }
        else
            ok = true;
    }while(!ok);
    if(cantidad != 0)
        gestor_clientes->registrar_clientes(cantidad);
}

void Supermercado::ejecutar_operacion(int& opc){
    CLEAN;
    switch(opc){
        case 1:{
            registrar_productos();
            break;
        }
        case 2:{
            gestor_stock->consultar_datos();
            getchar();
            break;
        }
        case 3:{
            gestor_stock->listar_productos();
            getchar();
            break;
        }
        case 4:{
            registrar_clientes();
            break;
        }
        case 5:{
            gestor_clientes->consultar_datos();
            getchar();
            break;
        }
        case 6:{
            gestor_clientes->listar_clientes();
            getchar();
            break;
        }
        case 7:{
            break;
        }
        case 8:{
            break;
        }
        case 9:{
            break;
        }
        case 10:{
            break;
        }
        case 11:{
            break;
        }
    }
}