#include <iostream>
#include <string>
using namespace std;

class Alojamiento{

  protected:
    string nombre;
    string ubicacion;
  
  public:
    Alojamiento();
    Alojamiento(string nombre_,string ubicacion_){
        nombre = nombre_;
        ubicacion = ubicacion_; 
    }

    virtual double calcularTotal()  = 0;
    virtual void imprimirInfo() = 0;
    virtual ~Alojamiento() = default;
};
