#include <iostream>

/*
Nombre: Mauricio Rodriguez Cordoba
Fecha: 29/Marzo/2023
Ejercicio: Crear un arbol bst, insertar ciertos valores, eliminarlos e imprimir
el arbol
*/

using namespace std;
// se crea una clase nodo con sus atributos y constructor principal
class Nodo {
public:
  int dato;
  int balance;
  Nodo *izquierda;
  Nodo *derecha;

  Nodo(int d) {
    dato = d;
    balance = 0;
    izquierda = nullptr;
    derecha = nullptr;
  }
};
// se crea una clase de arbol llamada bst con un
class BST {
public:
  // apuntador a la clase nodo
  Nodo *raiz;
  // constructor vacio
  BST() { raiz = nullptr; }
  // funcion insertar que recibe como parametros un apuntador a raiz de bst y el dato a insertar
  void insertar(Nodo *&raiz, int dato) {
    // el arbol esta vacio entonces el dato pasa a ser la raiz
    if (raiz == nullptr) {
      raiz = new Nodo(dato);
      return;
    } else {
      // el valor es menor que el valor del nodo actual por tanto se hace recursion para ir a la izquierda
      if (dato < raiz->dato) {
        insertar(raiz->izquierda, dato);
      } else {
        // el valor es mayor que el valor del nodo actual por tanto se hace recursion para ir a la derecha
        insertar(raiz->derecha, dato);
      }
    }
  }
  // funcion eliminar nodo que recibe como parametros un apuntador a raiz de bst
  // y el dato a eliminar
  Nodo *eliminarNodo(Nodo *raiz, int valor) {
    // se verifica si el árbol está vacío, si es asi no hay nada que eliminar
    if (raiz == nullptr) {
      return nullptr;
    }
    // Si el valor que buscamos es menor que el valor del nodo actual, vamos a
    // buscarlo en el subárbol izquierdo
    if (valor < raiz->dato) {
      raiz->izquierda = eliminarNodo(raiz->izquierda, valor);
      // Como cambiamos de nodo y pasamos uno de la izquierdo, necesitamos
      // actualizar el puntero del padre
    }
    // Si el valor que buscamos es mayor que el valor del nodo actual, vamos a
    // buscarlo en el subárbol derecho
    else if (valor > raiz->dato) {
      raiz->derecha = eliminarNodo(raiz->derecha, valor);
      // Como cambiamos de nodo y pasamos uno de la derecha , necesitamos
      // actualizar el puntero del padre
    }
    // Si el valor que buscamos es igual al valor del nodo actual,
    // entonces encontramos el nodo que queremos eliminar
    else {
      // el nodo no tiene hijos
      if (raiz->izquierda == nullptr && raiz->derecha == nullptr) {
        // Eliminamos el nodo
        delete raiz;
        // Como hemos eliminado el nodo, su puntero en el padre debe ser
        // actualizado a nullptr
        raiz = nullptr;
      }
      // el nodo tiene un hijo
      else if (raiz->izquierda == nullptr) {
        // Guardamos el puntero al nodo que se eliminará
        Nodo *temp = raiz;
        // El nodo a eliminar es reemplazado por su único hijo
        raiz = raiz->derecha;
        // Eliminamos el nodo
        delete temp;
      } else if (raiz->derecha == nullptr) {
        // Guardamos el puntero al nodo que se eliminará
        Nodo *temp = raiz;
        // El nodo a eliminar es reemplazado por su único hijo
        raiz = raiz->izquierda;
        // Eliminamos el nodo
        delete temp;
      }
      // el nodo tiene dos hijos
      else {
        // Encontramos el nodo con el valor mínimo en el subárbol derecho
        Nodo *temp = encontrarMinimo(raiz->derecha);
        // Reemplazamos el valor del nodo a eliminar por el valor mínimo
        // encontrado
        raiz->dato = temp->dato;
        // Eliminamos el nodo con el valor mínimo encontrado
        raiz->derecha = eliminarNodo(raiz->derecha, temp->dato);
        // Como hemos modificado el árbol, necesitamos actualizar el puntero del
        // padre al subárbol derecho
      }
    }
    // Devolvemos el puntero a la raíz del árbol actualizado
    return raiz;
  }

  // funcion que nos permite encontrar el valor minimo de un subarbol que recibe
  // un apuntador al nodo actual del bst
  Nodo *encontrarMinimo(Nodo *raiz) {
    while (raiz->izquierda != nullptr) {
      raiz = raiz->izquierda;
    }
    return raiz;
  }
  // funcion que nos permite recorrer en formato InOrder el bst
  void inOrder(Nodo *&nodo) {
    // si es nulo no retorna nada y acaba la función
    if (nodo == nullptr) {
      return;
    }
    // Por medio de recursividad se va al nodo de su izquierda
    inOrder(nodo->izquierda);
    // imprime el dato que se encuentra en el nodo
    cout << nodo->dato << " ";
    // Por medio de recursividad se va al nodo de su derecha
    inOrder(nodo->derecha);
  }
};

// Se crea la clase de arbol AVL
class AVl {
public:
// Se crea un apuntador tipo nodo que apunte al nodo actual
  Nodo *raiz;
  AVl() { raiz = nullptr; }
// funcion insertar que recibe como parametros un apuntador a raiz de bst y el dato a insertar
void insertar(Nodo *&nodo, int dato) {
  // el arbol esta vacio entonces el dato pasa a ser la raiz
    if (nodo == nullptr) {
      nodo = new Nodo(dato);
    }
  // el valor es menor que el valor del nodo actual por tanto se hace recursion para ir a la izquierda
    else if (dato < nodo->dato) {
      insertar(nodo->izquierda, dato);
  // el valor es mayor que el valor del nodo actual por tanto se hace recursion para ir a la derecha
    } else if (dato >= nodo->dato){
      insertar(nodo->derecha, dato);
    }
  // Como el nodo no es null y tiene un nuevo dato entonces se necesita balancear el arbol para cumplir con la condicion
if (nodo != nullptr) {
  // Se llama la funcion que actualiza el valor de balance
      actualiza_balance(nodo);
  // Se verifica si el valor del balance es mayor a 1
      if (nodo->balance > 1) {
  // Se mide la altura de ambos hijos del nodo izquerdo para saber si se hace a la derecha
        if (altura(nodo->izquierda->izquierda) >= altura(nodo->izquierda->derecha)) {
  // Se reealiza una rotacion a la derecha con el nodo actual
          nodo = rotacion_derecha(nodo);
        } else {
  // Se realiza el intercambio y la rotacion de los nodos 
          nodo->izquierda = rotacion_izquierda(nodo->izquierda);
          nodo = rotacion_derecha(nodo);
        }
      } else if (nodo->balance < -1) {
  // Se mide la altura de ambos hijos del nodo izquerdo para saber si se hace a la derecha
        if (altura(nodo->derecha->derecha) >= altura(nodo->derecha->izquierda)) {
  // Se reealiza una rotacion a la derecha con el nodo actual
          nodo = rotacion_izquierda(nodo);
        } else {
  // Se realiza el intercambio y la rotacion de los nodos 
          nodo->derecha = rotacion_derecha(nodo->derecha);
          nodo = rotacion_izquierda(nodo);
        }
      }
    }
  }

  // funcion eliminar nodo que recibe como parametros un apuntador a raiz de bst y el dato a eliminar
 Nodo* eliminar(Nodo* nodo, int dato) {
    // se verifica si el árbol está vacío, si es asi no hay nada que eliminar
    if (nodo == nullptr) {
        return nullptr;
    }
    // Si el valor que buscamos es mayor que el valor del nodo actual, vamos a buscarlo en el subárbol izquierdo de lo contrario se busca en el derecho
    if (dato < nodo->dato) {
        nodo->izquierda = eliminar(nodo->izquierda, dato);
    } else if (dato > nodo->dato) {
        nodo->derecha = eliminar(nodo->derecha, dato);
    } else { // Si encontramos el valor que queremos eliminar
        // Creamos un puntero al nodo a borrar
        Nodo* nodo_a_borrar = nodo;
        // Si el nodo tiene un solo hijo, tomamos ese hijo y lo hacemos el nuevo padre
        if (nodo->izquierda == nullptr) {
            nodo = nodo->derecha;
        } else if (nodo->derecha == nullptr) {
            nodo = nodo->izquierda;
        } else { // Si el nodo tiene dos hijos
            // Buscamos el sucesor del nodo, que es el valor más pequeño en el subárbol derecho
            Nodo* sucesor = Minimo(nodo->derecha);
            // Reemplazamos el valor del nodo a borrar con el del sucesor
            nodo->dato = sucesor->dato;
            // Eliminamos el sucesor del subárbol derecho
            nodo->derecha = eliminar(nodo->derecha, sucesor->dato);
        }
        // Liberamos la memoria del nodo a borrar
        delete nodo_a_borrar;
    }
    // Actualizamos el balance del nodo y realizamos rotaciones si es necesario para mantener el árbol balanceado
    if (nodo != nullptr) {
        actualiza_balance(nodo);
        if (nodo->balance > 1) {
            if (altura(nodo->izquierda->izquierda) >= altura(nodo->izquierda->derecha)) {
                nodo = rotacion_derecha(nodo);
            } else {
                nodo->izquierda = rotacion_izquierda(nodo->izquierda);
                nodo = rotacion_derecha(nodo);
            }
        } else if (nodo->balance < -1) {
            if (altura(nodo->derecha->derecha) >= altura(nodo->derecha->izquierda)) {
                nodo = rotacion_izquierda(nodo);
            } else {
                nodo->derecha = rotacion_derecha(nodo->derecha);
                nodo = rotacion_izquierda(nodo);
            }
        }
    }
    // Retornamos el nuevo nodo raíz del árbol
    return nodo;
}

//la funcion halla en minimo nodo que se encuentre en el subarbol derecho
     Nodo *Minimo(Nodo *raiz) {
    while (raiz->izquierda != nullptr) {
      raiz = raiz->izquierda;
    }
    return raiz;
  }

//retorna la altura que tiene el nodo para tener los procesos de balanceo 
  int altura(Nodo *nodo) {
    if (nodo == nullptr) {
      return -1;
    }
    return 1 + max(altura(nodo->izquierda), altura(nodo->derecha));
  }

//actualiza el valor del balance que presenta el nodo
  void actualiza_balance(Nodo *nodo) {
    nodo->balance = altura(nodo->izquierda) - altura(nodo->derecha);
  }

// realiza la rotacion hacia la izquierda 
  Nodo *rotacion_derecha(Nodo *nodo) {
// recibe el nodo lo asigan a uno temporal
    Nodo *nodo_izquierda = nodo->izquierda;
// a partir de ese nodo de izquierda se le reasigna su hijo derecho
    nodo->izquierda = nodo_izquierda->derecha;
// a ese hijo se le asigna el nodo que recibimos
    nodo_izquierda->derecha = nodo;
// se actualiza el valor de avance al nodo 
    actualiza_balance(nodo);
// se actualiza el valor de avance al hijo izquierdo del nodo
    actualiza_balance(nodo_izquierda);
// se retorna el hijo izquierdo del nodo
    return nodo_izquierda;
  }

// realiza la rotacion hacia la derecha
  Nodo *rotacion_izquierda(Nodo *nodo) {
// recibe el nodo lo asigan a uno temporal
    Nodo *nodo_derecha = nodo->derecha;
// a partir de ese nodo de derecha se le reasigna su hijo izquierda
    nodo->derecha = nodo_derecha->izquierda;
// a ese hijo se le asigna el nodo que recibimos
    nodo_derecha->izquierda = nodo;
// se actualiza el valor de avance al nodo 
    actualiza_balance(nodo);
// se actualiza el valor de avance al hijo izquierdo del nodo
    actualiza_balance(nodo_derecha);
// se retorna el hijo izquierdo del nodo
    return nodo_derecha;
  }

 void PreOrder(Nodo *&nodo) {
    // si es nulo no retorna nada y acaba la función
    if (nodo == nullptr) {
      return;
    }
    // imprime el dato que se encuentra en el nodo
    cout << nodo->dato << " ";
    // Por medio de recursividad se va al nodo de su izquierda
    PreOrder(nodo->izquierda);
    // Por medio de recursividad se va al nodo de su derecha
    PreOrder(nodo->derecha);
  }
};

int main() {
  // se crea un objeto de la clase bst
  BST bst;
  AVl avl;
  int a[12] = {32, 2, 3, 10, 19, 1, 40, 23, 54, 53, 48, 35};
  // inserta los numeros en el arbol
  for (int i = 0; i < 12; i++) {
    bst.insertar(bst.raiz, a[i]);
    avl.insertar(avl.raiz, a[i]);
  }
  // imprimimos el arbol inicial in order
  cout << "ARBOL INICIAL BST: " << endl;
  bst.inOrder(bst.raiz);
  // imprimimos el arbol inicial in order
  cout << endl << "ARBOL DEPUES DE ELIMINAR 2: " << endl;
  // se elimina el valor dos
  bst.eliminarNodo(bst.raiz, 2);
  // se imprime el valor sin el 2
  bst.inOrder(bst.raiz);
  cout << endl << "ARBOL DEPUES DE ELIMINAR 32: " << endl;
  // se elimina el valor 32
  bst.eliminarNodo(bst.raiz, 32);
  // se imprime sin el valor 32
  bst.inOrder(bst.raiz);
  cout << endl << "ARBOL DEPUES DE INSERTAR 41: " << endl;
  // se inserta el 41
  bst.insertar(bst.raiz, 41);
  // se imprime con el 41
  bst.inOrder(bst.raiz);
  cout << endl << "ARBOL INICIAL AVL BALANCEADO: " << endl;
  avl.PreOrder(avl.raiz);
  avl.insertar(avl.raiz,19);
  avl.insertar(avl.raiz,20);
  avl.insertar(avl.raiz,5);
  avl.insertar(avl.raiz,82);
  cout << endl << "ARBOL DESPUES DE INSERTAR 19,20,5,82: " << endl;
  avl.PreOrder(avl.raiz);
  cout << endl << "ARBOL DESPUES DE ELIMINAR 50: " << endl;
  avl.eliminar(avl.raiz,50);
  avl.PreOrder(avl.raiz);
}
