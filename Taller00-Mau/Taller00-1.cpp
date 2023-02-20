#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Genera números random entre 0 y 25
int N_Aleatorio();

int main() {
    // Crea el array de 10 elementos
    int Numeros[10];
    // Funcion para el numero random
    srand(time(0));
    // Llena el array con 10 numeros radom
    for (int i = 0; i < 10; i++) {
        Numeros[i] = N_Aleatorio();
    }
    // Crea el puntero
    int *puntero = Numeros;
    // Imprime el array
    cout << "Los Numeros Random Son:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << " |-| " << *(puntero + i) << " |-| ";
    }
    cout << endl;
    // Imprime las direcciones de memoria del array
    cout << "---------------------------------------------" << endl;
    cout << "Direcciones De Memoria Del Array:" << endl;
    cout << "---------------------------------------------" << endl;
    for (int i = 0; i < 10; i++) {
        cout << " |-| " << puntero + i << " |-| ";
    }
    cout << endl;

    return 0;
}

// Genera números random entre 0 y 25
int N_Aleatorio() {
    return rand() % 26;
}