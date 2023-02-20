#include "date.h"
#include <iostream>
#include <list>

using namespace std;


int main() {  bool Salida = false;
  while(!Salida){
  string NombreArhcivo;
  list<Cancion> Play;
  list<AC> Alb;
  AC Y;
  Cancion T;
  int op;
  bool Archivo = false;

      cout << "¿Cual Es El Archivo Que Desea Leer?" << endl;
    cin >> NombreArhcivo;
  Archivo = LeerArchivo(NombreArhcivo, Play, T);
  if(!Archivo) cout << "El Archvio No Existe" << endl;
  while (Archivo) {
      cout << " |-| "<< "¿Que Opcion Desea?" << endl;
      cout << " |-| "<< "1. Ver El Contenido Del Archivo" << endl;
      cout << " |-| "<< "2. Motrar Los Autores Existentes" << endl;
      cout << " |-| "<< "3. Mostrar Las Canciones De Un Autor" << endl;
      cout << " |-| "<< "4. Mostrar Los Albums Presentes Del Archivo"<< endl;
      cout << " |-| "<< "5. Mostrar Las Canciones Presentes De Un Album"<< endl;
      cout << " |-| "<< "6. Mostrar Las Canciones Y Los Almbums Presentes Del Archivo" << endl;
      cout << " |-| "<< "7. Salir Del Programa" << endl << endl;
     cout << endl;
      cin >> op;
     cout << endl;
      switch (op) {
      case 1: {
        ImprimirArchivo(Play);
        break;
      }
      case 2: {
        MostrarAutores(Play);
        break;
      }
      case 3: {
         string aux;
         cout << " |-| "<< "¿Que Autor?"<< " |-| " << endl;
        cin >> aux;
        Canciones_A(Play, aux);
        break;
      }
      case 4: {
        Album_A(Play);
        break;
      }
      case 5: {
         string aux;
         cout << " |-| "<< "¿Cual Album?"<< " |-| " << endl;
        cin >> aux;
        Album_C(aux, Play);
        break;
      }
      case 6: {
        Can_Nom_A(Play);
        break;
      }
      case 7: { Salida = true;
        Archivo = false;
        break;
      }
      }
    } 
}
  return 0;
}