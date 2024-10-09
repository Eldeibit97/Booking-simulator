#include <iostream>
#include <string>
using namespace std;

class Airbnb : public Alojamiento{

  private:
    int limiteHuespedes;
    double precio; 
  
  public:
    Airbnb();
    Airbnb(string nombre_,string ubicacion_,int limiteHuespedes_,double precio_) : Alojamiento(nombre_,ubicacion_){
        limiteHuespedes = limiteHuespedes_;
        precio = precio_;
    };

    double calcularTotal() override{
        return precio + 500;
    }
    void imprimirInfo() override{
        ofstream archivo;
        archivo.open("reservas.txt",std::ios::app);
        archivo << "Nombre del AirBnB: " << nombre << endl;
        archivo << "Ubicacion del AirBnB: " << ubicacion << endl;
        archivo << "Limite de huespedes: " << limiteHuespedes << endl;
        archivo << "Precio por dia: $" << precio << endl;
    }
};
