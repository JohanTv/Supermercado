#include "supermercado.cpp"

int main(){
    char nombre[] = "Wong\0";
    Supermercado test(nombre);
    test.mostrar_menu();
    return 0;
}
