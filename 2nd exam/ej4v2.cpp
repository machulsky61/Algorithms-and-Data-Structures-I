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

vector<posicion> vecinos(mapa m, posicion p){
    vector<posicion> res;
    if(p.first+1 < m.size()){
        res.push_back(make_pair(p.first+1,p.second));
    }
    if(p.first -1 >= 0){
        res.push_back(make_pair(p.first-1,p.second));
    }
    if(p.second+1 < m[0].size()){
        res.push_back(make_pair(p.first,p.second+1));
    }
    if(p.second-1 >= 0){
        res.push_back(make_pair(p.first,p.second-1));
    }
    return res;
}

int esPromedioVecinos(mapa m, posicion p) {
    int res = 0;
    int contadorVecinos = 0;
    int alturas = 0;
    vector<posicion> vecinosDelValle = vecinos(m,p);

    for(int i=0; i < vecinosDelValle.size(); i++){
        contadorVecinos++;
        alturas = alturas + m[vecinosDelValle[i].first][vecinosDelValle[i].second].first;
    }

    res = alturas / contadorVecinos;
    return res;
}

int rellenarValles(mapa &m) {
    mapa m0 = m;
    int res = 0;
    for(int i = 0;i<m0.size();i++){
        for(int j = 0;j<m0[0].size();j++){
            if(esValle(m0, make_pair(i,j))){
                int promedio = esPromedioVecinos(m0, make_pair(i,j));
                res += promedio - m[i][j].first;
                m[i][j].first = promedio;
            }
        }
    }
    return res;
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
    int res = rellenarValles(m);

    // Imprimo la salida
    cout << res << endl;
    cout << m.size() << endl;
    cout << m[0].size() << endl;
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size();j++) {
            cout << "("<< m[i][j].first << "," << m[i][j].second << ") ";
        }
        cout << endl;
    }

    return 0;
}