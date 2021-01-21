class Contador{
private:
    int codigo;
    char nombre[40];
    int cantidad;
    int monto_acumulado;
public:
    Contador(){}
    void aumentar_cantidad(int monto){ cantidad += monto; }
    void aumentar_monto(int suma){ monto_acumulado += suma; }
    void set_codigo(int _codigo){ codigo = _codigo; }
    void mostrar_datos(){
        cout << "Codigo         >> " << codigo << endl;
        cout << "Nombre         >> " << nombre << endl;
        cout << "Cantidad total >> " << cantidad << endl;
        cout << "Monto total    >> s/." << monto_acumulado << endl;
    }
    friend class DeVentas;
};