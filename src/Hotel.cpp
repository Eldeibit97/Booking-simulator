#include <iostream>
#include <string>
using namespace std;

class Hotel : public Alojamiento {
  protected:
    int numeroCuarto;
    double precioBase; 

  public:
    Hotel();
    Hotel(int num, double pb,string nombre_,string ubicacion_) : Alojamiento(nombre_, ubicacion_) {
      numeroCuarto = num;
      precioBase = pb;
    }
    
    double calcularTotal() override {
        return precioBase + precioBase * .05;
    }

    void imprimirInfo() override {
      ofstream archivo;
      archivo.open("reservas.txt",std::ios::app);
      archivo << "Nombre del hotel: " << nombre << endl; 
      archivo << "Ubicacion del hotel: " << ubicacion << endl;
      archivo << "Numero de cuarto: " << numeroCuarto << endl;
      archivo << "Precio base por dia: $" << precioBase << endl;
    };
};