#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <memory>
#include "Fecha.cpp"
#include "Alojamiento.cpp"
#include "Reserva.cpp"
#include "AirBnb.cpp"
#include "Hotel.cpp"
#include "Hotel_Servicios.cpp"

using namespace std;

string nombreHotel(){
  while (true)
  {
  int op;
  cout << "¿En que hotel deseas reservas?" << endl;
  cout << "1. Holiday Inn ($1000 por noche)" << endl;
  cout << "2. Motel 6 ($500 por noche)" << endl;
  cout << "3. El Hotelucho ($200 por noche)" << endl;
    if (!(cin >> op)) {
      cout << "Tipo de dato no valido. Por favor solo introducir numero enteros dentro del rango." << endl;
      cin.clear();
      cin.ignore();
    }else if(op < 1 || op > 3){
      cout << "Opcion no valida, escriba una de las opciones presentes." << endl;
      cin.clear();
      cin.ignore();
    }
    switch (op)
  {
  case 1:
    return "Holiday Inn";
    break;
  case 2:
    return "Motel 6";
    break;
  case 3: 
    return "El Hotelucho";
    break;
    }
  }
}

string nombreAirBnb(){
  while (true){
    int op;
    cout << "¿En que AirBnB deseas reservas?" << endl;
    cout << "1. Casa de playa ($1000 por noche)" << endl;
    cout << "2. La chosa ($500 por noche)" << endl;
    cout << "3. La casa del profe ($200 por noche)" << endl;
      if (!(cin >> op)) {
      cout << "Tipo de dato no valido. Por favor solo introducir numero enteros dentro del rango." << endl;
      cin.clear();
      cin.ignore();
    }else if(op < 1 || op > 3){
      cout << "Opcion no valida, escriba una de las opciones presentes." << endl;
      cin.clear();
      cin.ignore();
    }
      switch (op)
    {
    case 1:
      return "Casa de playa";
    case 2:
      return "La chosa";
    case 3: 
      return "La casa del profe";
      }
  }
}

bool servicios(string servicio){
  string opcion;
  cout << "¿Desea agregar " << servicio << "? Si / No: " << endl;
  cin >> opcion;
  if (opcion == "Si" || opcion == "si"){
    return true;
  } else {
    return false;
  }
}

Reserva crearReserva(string &usuario, string &contacto){

  while(true){
    int opcion;
    string nombre;
    string op_cuarto;
    cout << "¿Qué tipo de alojamiento desea reservar?" << endl;
    cout << "1. Hotel" << endl;
    cout << "2. Airbnb" << endl;
    if (!(cin >> opcion)) {
      cout << "Tipo de dato no valido. Por favor solo introducir numero enteros dentro del rango." << endl;
      cin.clear();
      cin.ignore();
      crearReserva(usuario, contacto);
    }else if(opcion < 1 || opcion > 2){
      cout << "Opcion no valida, escriba una de las opciones presentes." << endl;
      cin.clear();
      cin.ignore();
      crearReserva(usuario, contacto);
    }
    switch (opcion)
    {
    case 1:
      nombre = nombreHotel();
      double precio;
      if(nombre == "Holiday Inn"){
        precio = 1000;
      } else if (nombre == "Motel 6"){
        precio = 500;
      } else {
        precio = 200;
      }
      cout << "¿Quiere agregar servicios ($100 por servicio agregado)? Si / No: " << endl;
      cin >> op_cuarto;
      if (op_cuarto == "Si" || op_cuarto == "si"){
        bool restaurante = servicios("restaurante");
        bool lavanderia = servicios("lavanderia");
        bool guarderia = servicios("guarderia"); 
        bool bar = servicios("bar");
        bool transporte = servicios("transporte");
        bool spa = servicios("spa");
        unique_ptr<HotelServicios> hotel = make_unique<HotelServicios>(rand() % 200, precio, nombre, "Hermosillo", restaurante, lavanderia, guarderia, bar, transporte, spa);
        return Reserva(usuario, contacto,std::move(hotel));
      }else{
        unique_ptr<Hotel> hotel = make_unique<Hotel>(rand() % 200, precio, nombre, "Hermosillo");
        return Reserva(usuario, contacto,std::move(hotel));
      }
      break;
    case 2:
      nombre = nombreAirBnb();
      double precio2;
      int personas;
      if(nombre == "Casa de playa"){
        precio2 = 1000;
        personas = 10;
      } else if (nombre == "La casa del profe"){
        precio2 = 500;
        personas = 5;
      } else {
        precio2 = 200;
        personas = 2;
      }
      unique_ptr<Airbnb> air = make_unique<Airbnb>(nombre, "Hermosillo",personas, precio2);
      return Reserva(usuario, contacto,std::move(air));
      break;
      }
    }
  }


string crearUsuario(){
  string usuario;
  cout << "Usuario: "; 
  getline(cin, usuario);
  return usuario;
}

string crearContacto(){
  string contacto;
  cout << "Contacto: ";
  cin >> contacto;
  if(contacto.empty()){
    cout << "Escribe un nombre de usuario porfavor" << endl;
    cin.clear();
    cin.ignore();
    crearUsuario();
  }
  return contacto;
}

void imprimirReservas(string &usuario, string &contacto, vector <Reserva> &reservas){
  ofstream archivo;
  archivo.open("reservas.txt");
  archivo << "Nombre en las reservas: " << usuario << endl;
  archivo << "Contacto en las reservas: " << contacto << endl;
  archivo << endl;
  archivo.close();
  archivo.open("reservas.txt",std::ios::app);
  for (int i = 0; i < reservas.size(); i++){
    archivo << "Reserva " << i + 1 << endl;
    reservas.at(i).imprimirInformacion();
    archivo << endl;
  }
  archivo.close();
}

void realizarPago(){
  string num_tarjeta;
  string cVV;
  cout << endl;
  while (true)
  {
    cout << "Escriba su numero de tarjeta: ";
    cin >> num_tarjeta;
  if(num_tarjeta.length() > 16 || num_tarjeta.length() < 16){
    cout << "Escribiste mas o menos de 16 digitos, intentalo otra vez" << endl;
    cin.clear();
    cin.ignore();
    continue;
  }
  cout << "Escriba su CVV: ";
  cin >> cVV;
  if(cVV.length() > 3 || cVV.length() < 3){
    cout << "Escribe el CVV correctamente" << endl;
    cin.clear();
    cin.ignore();
    continue;
  }
  break;
  }
}

double pagoTotal(vector <Reserva> &reservas){
  double total;
  for(int i = 0; i < reservas.size(); i++){
      total = total + reservas.at(i).sacarCantidades();
  }
  return total;
}

int main(){
  vector <Reserva> reservas;
  string usuario = crearUsuario();
  string *ptrusuario = &usuario;
  string contacto = crearContacto();
  string *ptrcontacto = &contacto;

  do {
    reservas.push_back(crearReserva(*ptrusuario, *ptrcontacto));

    string opcion;
    cout << "¿Desea hacer otra reserva? Si / No: ";
    cin >> opcion;

    if (opcion == "No" || opcion == "no") {
      break;
    }
  } while (true);
  cout << endl;
  cout << "Calculando Total a pagar..." << endl;
  cout << "Monto total a pagar: $" << pagoTotal(reservas);
  cout << endl;
  cout << "Pasando al proceso de pago..." << endl;
  realizarPago();
  cout << endl;
  cout << "¡Pago realizado!" << endl;
  cout << "Generando comprobantes de reservas..." << endl;
  imprimirReservas(*ptrusuario, *ptrcontacto, reservas);
  cout << "Comprobantes generados bajo el nombre reservas.txt" << endl;
  return 0;
};