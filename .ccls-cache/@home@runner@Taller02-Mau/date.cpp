#include "date.h"
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <string>

using namespace std;

bool LeerArchivo(string nombreArchivo, list<Cancion> &Play, Cancion T) {
  // Se crea una variable para saber que archivo leer
  string a;
  ifstream f(nombreArchivo, ios::in);
  // Se verifica si el archivo esta abierto
  if (f.is_open()) {
    cout << endl << "Carga Exitosa" << endl << endl;
    getline(f, a);
    while (getline(f, a)) {
      tokenizar(a, Play, T);
    }
    f.close();
    return true;
  } else {
    return false;
  }
}

void tokenizar(string cadena, list<Cancion> &Play, Cancion T) {
  string d;
  int cont = 0;
  stringstream input_stringstream(cadena); // Convertir la cadena a un stream
  while (getline(input_stringstream, d, '|')) {
    ;
    switch (cont) {
    case 0: {
      T.Nombre = d;
      break;
    }
    case 1: {
      T.Autor = d;
      break;
    }
    case 2: {
      T.Genero = d;
      break;
    }
    case 3: {
      T.Album = d;
      break;
    }
    case 4: {
      T.Ano = stoi(d);
      break;
    }
    }
    cont++;
  }
  Play.push_front(T);
}

void MostrarAutores(list<Cancion> Play) {
  set<string> Ej;
  for (const auto Cancion : Play) {
    Ej.insert(Cancion.Autor);
  }
  for (const auto e : Ej) {
    cout << "Autor: " << e << endl;
  }
  cout << endl;
}

void ImprimirArchivo(list<Cancion> Play) {
  for (const auto Cancion : Play) {
        cout << endl
         << "------------------------------------" << endl
         << "|      El Archivo Contiene         |" << endl
         << "------------------------------------" << endl;
    cout << "Nombre: " << Cancion.Nombre << endl;
    cout << "Autor: " << Cancion.Autor << endl;
    cout << "Album: " << Cancion.Album << endl;
    cout << "Año: " << Cancion.Ano << endl;
    cout << "Genero: " << Cancion.Genero << endl;
    cout << endl;
  }
}

void Canciones_A(list<Cancion> Play, string e) {
  set<string> E;
  for (const auto Cancion : Play) {
    if (e == Cancion.Autor) {
      E.insert(Cancion.Nombre);
    }
  }
  for (const auto u : E) {
    cout << "Canciones Del Autor: " << u << endl;
  }
  cout << endl;
}

void Album_A(list<Cancion> Play) {
  set<AC> Alb;
  AC Y;
  for (auto Cancion : Play) {
    Y.Album = Cancion.Album;
    Y.Ano = Cancion.Ano;
    Alb.insert(Y);
  }
  cout << "Albums Coordenados Cronolagicamente: " << endl;
  for (auto u : Alb) {
    cout << "|-| Album: " << u.Album << "|-|"
         << "|-| Año: " << u.Ano << "|-|" << endl;
    ;
  }
  cout << endl;
}

void Album_C(string e, list<Cancion> Play) {
  set<string> E;
  for (const auto Cancion : Play) {
    if (e == Cancion.Album) {
      E.insert(Cancion.Nombre);
    }
  }
  for (const auto u : E) {
    cout << "Canciones Del Album: " << u << endl;
  }
  cout << endl;
}

void Can_Nom_A(list<Cancion> Play) {
  ACT Y;
  list<ACT> l;
  for (const auto Cancion : Play) {
    Y.Nombre = Cancion.Nombre;
    Y.Album = Cancion.Album;
    l.push_back(Y);
  }
  for (auto u : l) {
    cout << "|-| Album: " << u.Album << "|-|"
         << "|-| Año: " << u.Nombre << "|-|" << endl;
    ;
  }
  l.sort();
  cout << "Albums y Canciones: " << endl;
  for (auto u : l) {
    cout << "|-| Album: " << u.Album << "|-|"
         << "|-| Cancion: " << u.Nombre << "|-|" << endl;
  }
  cout << endl;
}