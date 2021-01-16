class Cliente{
private:
    int dni;
    char nombres[40];
    char apellidos[40];
public:
    Cliente(){}
    void mostrar_datos(){
        cout << "DNI       >> " << this->dni << endl;
        cout << "Nombres   >> " << this->nombres << endl;
        cout << "Apellidos >> " << this->apellidos << endl;
    }
    friend class DeClientes;
};