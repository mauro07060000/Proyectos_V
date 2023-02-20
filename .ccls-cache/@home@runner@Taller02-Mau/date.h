#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <string>

#ifndef date_h
#define date_h

using namespace std;

struct Cancion {
  string Nombre;
  string Autor;
  string Genero;
  string Album;
  int Ano;
};

struct AC {
  int Ano;
  string Album;
  bool operator<(const AC &y) const { return Ano < y.Ano; }
};

struct ACT {
  string Nombre;
  string Album;
  bool operator<(const ACT &y) const {
    if (Album != y.Album)
      return Album < y.Album;
    if (Nombre != y.Nombre)
      return Nombre < y.Nombre;
  }
};

bool LeerArchivo(string nombreArchivo, list<Cancion> &Play, Cancion T);
void tokenizar(string tokenizar, list<Cancion> &Play, Cancion T);
void MostrarAutores(list<Cancion> Play);
template <class T> int comp(T a, T b);
void ImprimirArchivo(list<Cancion> Play);
void MostrarAutores(list<Cancion> Play);
void Canciones_A(list<Cancion> Play, string e);
void Album_A(list<Cancion> Play);
void Album_C(string e, list<Cancion> Play);
void Can_Nom_A(list<Cancion> Play);

#endif