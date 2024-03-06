#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

// DEFINICIONES DE TIPO
typedef pair<int, int> posicion;
typedef int altura;
typedef int poblacion;
typedef pair<altura, poblacion> zona;
typedef vector<vector<zona > > mapa;

void vivenEnAltura(mapa m, int &alt, int &cantGente) {
    alt = 0;
    cantGente = 0;
    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j < m[0].size(); j++){
            if(alt < m[i][j].first){
                alt = m[i][j].first;
            }
        }
    }
    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j < m[0].size(); j++){
            if(m[i][j].first == alt){
                cantGente = cantGente + m[i][j].second;
            }
        }
    }
}

int main() {
    /* No hace falta modificar el main */

    // El mapa 1
    int f;
    cin >> f;
    int c;
    cin >> c;
    mapa m;
    char aux;
    int alt;
    int pob;
    for (int i = 0; i < f; i++) {
        vector<zona> fila;
        for (int j = 0; j < c; j++) {
            cin >> aux;
            cin >> alt;
            cin >> aux;
            cin >> pob;
            cin >> aux;
            fila.push_back(make_pair(alt, pob));
        }

        m.push_back(fila);
    }

    // Invoco la función
    int altura;
    int cantGente;
    vivenEnAltura(m, altura, cantGente);

    // Imprimo la salida
    cout << altura << " " << cantGente << endl;

    return 0;
}
