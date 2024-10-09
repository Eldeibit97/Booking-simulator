#include <iostream>
#include <string>
using namespace std;

class HotelServicios : public Hotel{

  private:
   bool restaurante;
   bool lavanderia;
   bool guarderia;
   bool bar;
   bool transporte;
   bool spa;

  public:
    HotelServicios();
    HotelServicios(int num, double pb,string nombre_,string ubicacion_,bool restaurante_,bool lavanderia_,bool guarderia_,bool bar_,bool transporte_,bool spa_) : Hotel(num, pb, nombre_, ubicacion_) {
      restaurante = restaurante_;
      lavanderia = lavanderia_;
      guarderia = guarderia_;
      bar = bar_;
      transporte = transporte_;
      spa = spa_;
    }
    
    double calcularServicios() {
      //Por cada servicio se cobra 100 mas y se le suma al precio base
      double servicios = 0.0;
      
      if (restaurante) {
        servicios += 100.0;
      }
      if (lavanderia) {
        servicios += 100.0;
      }
      if (guarderia) {
        servicios += 100.0;
      }
      if (bar) {
        servicios += 100.0;
      }
      if (transporte) {
        servicios += 100.0;
      }
      if (spa) {
        servicios += 100.0;
      }
      return servicios;
    }

    double calcularTotal() override {
      double precio = precioBase + calcularServicios();
      return precio + precio * .05;
    }

    void imprimirInfo() override {
      ofstream archivo;
      archivo.open("reservas.txt",std::ios::app);
      archivo << "Nombre del hotel: " << nombre << endl; 
      archivo << "Ubicacion del hotel: " << ubicacion << endl;
      archivo << "Numero de cuarto: " << numeroCuarto << endl;
      archivo << "Precio por dia: $" << precioBase << endl;
      archivo << "Precio por servicios extras: $" << calcularServicios() << endl;
      
    }

};