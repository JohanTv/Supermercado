class Cliente{
private:
    int dni;
    char nombres[40];
    char apellidos[40];
public:
    Cliente(){}
    void mostrar_datos(){
        cout << "DNI       >> " << dni << endl;
        cout << "Nombres   >> " << nombres << endl;
        cout << "Apellidos >> " << apellidos << endl;
    }
    friend class DeClientes;
};