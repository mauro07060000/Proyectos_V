#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <limits>

using namespace std;

class Grafo {
public:
    int numVertices;
    vector<string> nombresEstaciones;
    list<pair<int, int>> *listasAdy;
    vector<bool> visitados;
    vector<int> distancias;

    Grafo(int numVertices) {
        this->numVertices = numVertices;
        listasAdy = new list<pair<int, int>>[numVertices];
        nombresEstaciones.resize(numVertices);
        visitados.resize(numVertices);
        distancias.resize(numVertices, numeric_limits<int>::max());
        for (int i = 0; i < numVertices; ++i) {
            visitados[i] = false;
        }
    }

    void agregarArista(int origen, int destino, int peso) {
        listasAdy[origen].push_back(make_pair(destino, peso));
        // Si el grafo es no dirigido, descomenta la siguiente línea:
        // listasAdy[destino].push_back(make_pair(origen, peso));
    }

    void asignarNombreEstacion(int vertice, const string& nombre) {
        nombresEstaciones[vertice] = nombre;
    }

    void imprimirGrafo() {
        for (int i = 0; i < numVertices; ++i) {
            cout << "Adyacencias de la estación " << nombresEstaciones[i] << ": ";
            for (auto v : listasAdy[i]) {
                cout << nombresEstaciones[v.first] << " [Peso:" << v.second << "] ";
            }
            cout << endl;
        }
    }
};

void bfs(Grafo& grafo, int origen) {
    queue<int> cola;
    grafo.visitados[origen] = true;
    cola.push(origen);

    while (!cola.empty()) {
        int vertice = cola.front();
        cola.pop();

        cout << grafo.nombresEstaciones[vertice] << " ";

        for (auto v : grafo.listasAdy[vertice]) {
            if (!grafo.visitados[v.first]) {
                grafo.visitados[v.first] = true;
                cola.push(v.first);
            }
        }
    }
}

void DFS(Grafo& grafo, int origen) {
    grafo.visitados[origen] = true;
    cout << grafo.nombresEstaciones[origen] << " ";

    for (auto it = grafo.listasAdy[origen].begin(); it != grafo.listasAdy[origen].end(); ++it) {
        if (!grafo.visitados[it->first]) {
            DFS(grafo, it->first);
        }
    }
}

void dijkstra(Grafo& grafo, int origen) {
    grafo.distancias[origen] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> colaPrioridad;
    colaPrioridad.push(make_pair(0, origen));

    while (!colaPrioridad.empty()) {
        int verticeActual = colaPrioridad.top().second;
        int distanciaActual = colaPrioridad.top().first;
        colaPrioridad.pop();

        if (grafo.visitados[verticeActual])
            continue;

        grafo.visitados[verticeActual] = true;

        for (auto arista : grafo.listasAdy[verticeActual]) {
            int verticeDestino = arista.first;
            int peso = arista.second;

            if (!grafo.visitados[verticeDestino] && distanciaActual + peso < grafo.distancias[verticeDestino]) {
                grafo.distancias[verticeDestino] = distanciaActual + peso;
                colaPrioridad.push(make_pair(grafo.distancias[verticeDestino], verticeDestino));
            }
        }
    }
  cout << grafo.nombresEstaciones[origen];
}

void imprimirDistancias(Grafo& grafo) {
    cout << " distancias mas cortas:" << endl;
    for (int i = 0; i < grafo.numVertices; ++i) {
        cout << grafo.nombresEstaciones[i] << ": ";
        if (grafo.distancias[i] == numeric_limits<int>::max()) {
            cout << "Infinito" << endl;
        } else {
            cout << grafo.distancias[i] << endl;
        }
    }
}

int main() {
    Grafo grafo(4);

    grafo.asignarNombreEstacion(0, "Portal Usme");
    grafo.asignarNombreEstacion(1, "Portal Sur");
    grafo.asignarNombreEstacion(2, "Portal Américas");
    grafo.asignarNombreEstacion(3, "Portal Tunal");

    grafo.agregarArista(0, 1, 10);
    grafo.agregarArista(1, 2, 5);
    grafo.agregarArista(2, 3, 15);

    cout << "GRAFO:" << endl;
    grafo.imprimirGrafo();

    cout << "BFS:" << endl;
    bfs(grafo, 0);
    cout << endl;

    // Restaurar visitados para el DFS
    for (int i = 0; i < grafo.numVertices; ++i) {
        grafo.visitados[i] = false;
    }

    cout << "DFS:" << endl;
    DFS(grafo, 0);
    cout << endl;
    // Restaurar visitados y distancias para Dijkstra
    for (int i = 0; i < grafo.numVertices; ++i) {
        grafo.visitados[i] = false;
        grafo.distancias[i] = numeric_limits<int>::max();
    }
    cout << endl << "Dijkstra:" << endl;
    dijkstra(grafo, 0);
    imprimirDistancias(grafo);

    return 0;
}
