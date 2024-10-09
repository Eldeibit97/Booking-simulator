#include <iostream>
#include <string>
using namespace std;

class Fecha {
  private:
    int dia;
    int mes;
    int anio;
  
  public:
    Fecha(){};
    Fecha(int dia_, int mes_, int anio_){
      dia = dia_;
      mes = mes_;
      anio = anio_;
    }

    void setFecha(int dia_, int mes_, int anio_) {
        bool fechaValida = true;

        // Validación del día
        if (dia_ < 1 || dia_ > 31) {
            cout << "Día inválido." << endl;
            fechaValida = false;
        }

        // Validación del mes
        if (mes_ < 1 || mes_ > 12) {
            cout << "Mes inválido." << endl;
            fechaValida = false;
        }

        // Validación del año
        if (anio_ < 0) {
            cout << "Año inválido." << endl;
            fechaValida = false;
        }

        // Asignar valores si la fecha es válida
        if (fechaValida) {
            dia = dia_;
            mes = mes_;
            anio = anio_;
        }
    }

    friend ostream& operator<<(ostream& os, const Fecha& fecha);

    double operator-(Fecha& fecha2){
      int dias;
      int dAnios = (anio - fecha2.anio) * 365;
      int dMeses = (mes - fecha2.mes)*30;
      int dDias = dia - fecha2.dia;
      /*cout << dAnios << endl;
      cout << dMeses << endl;
      cout << dDias << endl;*/
      dias = dAnios + dDias + dMeses;
      return dias;
    }
};