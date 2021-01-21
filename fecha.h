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
    bool operator==(Fecha& other){
        return other.dia == dia && other.mes == mes && other.anio == anio;
    }
    void operator=(Fecha& other){
        dia = other.dia;
        mes = other.mes;
        anio = other.anio;
    }
    void aumentar_fecha(){
        ++dia;
        if(dia > 30){
            dia = 1;
            ++mes;
        }
        if(mes > 12){
            mes = 1;
            ++anio;
        }
    }
    friend class Supermercado;
};