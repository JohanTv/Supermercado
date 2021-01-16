#include "supermercado.cpp"

int main(){
    char nombre[] = "Saga Falabella\0";
    Supermercado test(nombre);
    test.mostrar_menu();
    return 0;
}