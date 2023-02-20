#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Estructura de datos para los guardar la info
struct Cliente {
  string Nombre;
  string Direccion;
  string Ciudad;
  string Correo;
  string Telefono;
};

// Función para imprimir la factura de un cliente en un fichero de texto
void CrearFactura(Cliente *P, float total, int N) {
  // Se nombra el archivo
  string nombreArchivo = "Factura.txt";
  // Se nombra abre el archivo
  ofstream f(nombreArchivo, ios::app);
  // Se verifica si el archivo esta abierto
  if (f.is_open()) {
    // Ser recorren los datos del usuario para escribirlos en el archivo txt
    for (int i = 0; i < N; i++) {
      f << " Nombre: " << (P + i)->Nombre << ","
        << " Direccion: " << (P + i)->Direccion << ","
        << " Ciudad: " << (P + i)->Ciudad << ","
        << " Correo: " << (P + i)->Correo << ","
        << " Telefono: " << (P + i)->Telefono << endl;
    }
    f.close();
  }
}

void ImpFactura() {
  // Se crea una variable para saber que archivo leer
  string nombreArchivo = "Factura.txt";
  string a;
  cout << endl
       << "------------------------------------" << endl
       << "       El Archivo Contiene: " << endl
       << "------------------------------------" << endl;
  ifstream f(nombreArchivo, ios::in);
  // Se verifica si el archivo esta abierto
  if (f.is_open()) {
    while (getline(f, a)) {
      // Se imprime la informacion
      cout << " |-| CLIENTE |-| " << a << endl << endl;
    }
  }
}

int main() {
  int N;
  Cliente clientes[N], *P;
  P = clientes;
  cout << "¿Cuantos Usuarios Desea Ingresar?" << endl;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cout << "Ingrese El Nombre: " << endl;
    cin.ignore();
    getline(cin, (P + i)->Nombre);
    cout << "Ingrese La Direccion: " << endl;
    getline(cin, (P + i)->Direccion);
    cout << "Ingrese La Ciudad: " << endl;
    getline(cin, (P + i)->Ciudad);
    cout << "Ingrese El Correo: " << endl;
    getline(cin, (P + i)->Correo);
    cout << "Ingrese El Telefono: " << endl;
    getline(cin, (P + i)->Telefono);
  }
  // Calcular el total de la factura
  float total = 120.99;
  // Crea la factura
  CrearFactura(P, total, N);
  // Imprimir la factura del cliente1
  ImpFactura();
  return 0;
}