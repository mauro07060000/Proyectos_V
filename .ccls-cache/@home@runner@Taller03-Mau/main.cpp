#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void ImpFactura();

int main() {
 
  ImpFactura();

  return 0;
}

void ImpFactura() {
 //Se crea una variable para saber que archivo leer
  string nombreArchivo = "example1.txt";
  string a;
  cout << endl << "------------------------------------" << endl << "       El Archivo Contiene: " << endl << "------------------------------------" << endl;
  ifstream f(nombreArchivo, ios::in);
  //Se verifica si el archivo esta abierto
  if (f.is_open()) {
    while (getline(f, a)) {
  //Se imprime la informacion
      cout << " |-| CLIENTE |-| " << a << endl << endl;
    }
  }
}
