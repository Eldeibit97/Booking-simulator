#include <iostream>
#include <string>
#include <fstream>
#include <memory>

ostream& operator<<(ostream& os, const Fecha& fecha) {
  os << fecha.dia << "/" << fecha.mes << "/" << fecha.anio;
  return os;
}

class Reserva{
  private:
    Fecha checkIn;
    Fecha checkOut;
    string usuario;
    string contacto;
    unique_ptr<Alojamiento> alojamiento; //Sin la referencia hace BOOM

  public:
    //Es lo que mande por el grupo
    Reserva(string &usuario_, string &contacto_,unique_ptr<Alojamiento> alojamiento_):alojamiento(std::move(alojamiento_)){
      int dia1,mes1,anio1;
      int dia2,mes2,anio2;
      string prueba = "prueba";
      cout << "Registrar fecha de ingreso y salida" << endl;
      cout << "Fecha de ingreso" << endl;
      while (prueba == "prueba"){
        try{
          cout << "No. de Dia: ";
          if (!(cin >> dia1))
          {
            cin.clear();
            cin.ignore();
            throw invalid_argument("Tipo de dato no valido.");
          }else if(dia1 < 0 || dia1 > 30){
        throw invalid_argument("Dia invalido");
        cin.clear();
        cin.ignore();
          } else {
        prueba = "listo";
          }
        } catch (const invalid_argument& e){
          cout << "Error: " << e.what() << endl;
        }
      };

      prueba = "prueba";
      cout << "Favor de poner el mes en formato numerico" << endl;
      while (prueba == "prueba"){
        try{
          cout << "Mes: ";
          if (!(cin >> mes1))
          {
        cin.clear();
        cin.ignore();
        throw invalid_argument("Tipo de dato no valido.");
          }else if(mes1 < 0 || mes1 > 12){
        throw invalid_argument("Mes invalido");
        cin.clear();
        cin.ignore();
          } else {
        prueba = "listo";
          }
        } catch (const invalid_argument& e){
          cout << "Error: " << e.what() << endl;
        }
      };

      prueba = "prueba";
      while (prueba == "prueba"){
        try{
          cout << "Año: ";
          if (!(cin >> anio1))
          {
        cin.clear();
        cin.ignore();
        throw invalid_argument("Tipo de dato no valido.");
          }else if(anio1 < 2024 || anio1 > 2050){
        throw invalid_argument("Año invalido. No puede ser menor de 2024 ni mayor a 2050 ");
        cin.clear();
        cin.ignore();
          } else {
        prueba = "listo";
          }
        } catch (const invalid_argument& e){
          cout << "Error: " << e.what() << endl;
        }
      };
      cout << "Fecha de salida" << endl;
      prueba = "prueba";
      while (prueba == "prueba"){
        try{
          cout << "No. de Dia: ";
          if (!(cin >> dia2))
          {
        cin.clear();
        cin.ignore();
        throw invalid_argument("Tipo de dato no valido.");
          }else if(dia2 < 0 || dia2 > 30){
        throw invalid_argument("Dia invalido");
        cin.clear();
        cin.ignore();
          } else {
        prueba = "listo";
          }
        } catch (const invalid_argument& e){
          cout << "Error: " << e.what() << endl;
        }
      };

      prueba = "prueba";
      cout << "Favor de poner el mes en formato numerico" << endl;
      while (prueba == "prueba"){
        try{
          cout << "Mes: ";
          if (!(cin >> mes2))
          {
        cin.clear();
        cin.ignore();
        throw invalid_argument("Tipo de dato no valido.");
          }else if(mes2 < 0 || mes2 > 12){
        throw invalid_argument("Mes invalido");
        cin.clear();
        cin.ignore();
          } else {
        prueba = "listo";
          }
        } catch (const invalid_argument& e){
          cout << "Error: " << e.what() << endl;
        }
      };

      prueba = "prueba";
      while (prueba == "prueba"){
        try{
          cout << "Año: ";
          if (!(cin >> anio2))
          {
        cin.clear();
        cin.ignore();
        throw invalid_argument("Tipo de dato no valido.");
          }else if(anio2 < 2024 || anio2 > 2050){
        throw invalid_argument("Año invalido. No puede ser menor de 2024 ni mayor a 2050 ");
        cin.clear();
        cin.ignore();
          } else {
        prueba = "listo";
          }
        } catch (const invalid_argument& e){
          cout << "Error: " << e.what() << endl;
        }
      };
      checkIn.setFecha(dia1,mes1,anio1);
      checkOut.setFecha(dia2,mes2,anio2);
      usuario = usuario_;
      contacto = contacto_;
    };

    double calcularEstancia(){
      return checkOut - checkIn;
    };

    double sacarCantidades(){
        return alojamiento->calcularTotal() * calcularEstancia();

    };

    void imprimirInformacion(){
      ofstream archivo;
      archivo.open("reservas.txt",std::ios::app);
      alojamiento->imprimirInfo();
      archivo << "Fecha de Check In: " << checkIn << endl;
      archivo << "Fecha de Check Out: " << checkOut << endl;
      archivo << "Total a pagar (Impuesto diario del %5): $" << sacarCantidades() << endl;
    };
};