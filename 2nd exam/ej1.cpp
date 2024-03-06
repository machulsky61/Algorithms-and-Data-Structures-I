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
typedef vector<vector<zona>> mapa; ///vector<vector<pair>> ---> vector<vector<altura,poblacion>>



bool esValle(mapa m, posicion p){

    bool esValle = true;

    if(0 <= p.first - 1){
        if(m[p.first-1][p.second].first >= m[p.first][p.second].first){
            esValle = esValle && true;
        } else {
            esValle = esValle && false;
        }
    }
    if(p.first + 1 < m.size()){
        if(m[p.first+1][p.second].first >= m[p.first][p.second].first){
            esValle = esValle && true;
        } else {
            esValle = esValle && false;
        }
    }
    if(0 <= p.second - 1){
        if(m[p.first][p.second-1].first >= m[p.first][p.second].first){
            esValle = esValle && true;
        } else {
            esValle = esValle && false;
        }
    }
    if(p.second+1 < m[0].size()){
        if(m[p.first][p.second+1].first >= m[p.first][p.second].first){
            esValle = esValle && true;
        } else {
            esValle = esValle && false;
        }
    }
    return esValle;
}

int main() {
    /* No hace falta modificar el main */

    // La posición
    int pos1;
    cin >> pos1;
    int pos2;
    cin >> pos2;
    posicion p = make_pair(pos1, pos2);

    // El mapa
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

    // Evaluo si la posición es valle
    bool res = esValle(m, p);

    // Imprimo la salida
    cout << (res?"True":"False") << endl;

    return 0;
}