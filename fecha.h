class Fecha{
private:
    int dia;
    int mes;
    int anio;
public:
    Fecha(){}
    Fecha(int dia, int mes, int anio){
        this->dia = dia;
        this->mes = mes;
        this->anio = anio;
    }
    void mostrar_fecha(){
        cout.fill('0'); cout.width(2); // rellenar ceros a la izquierda
        cout << dia << "/";
        cout.fill('0'); cout.width(2); 
        cout << mes << "/";
        cout.fill('0'); cout.width(2); 
        cout << anio;
        // cout << dia << "/" << mes << "/" << anio;
    }
    friend class Supermercado;
};