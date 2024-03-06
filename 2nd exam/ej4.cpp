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

int rellenarValles(mapa &m) {
    int res = 0;
    int sumaAlturas = 0;
    int sumaAlt = 0;


    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j < m[0].size(); j++){

            sumaAlturas = sumaAlturas + m[i][j].first;

            if(esValle(m, make_pair(i,j))){
                int cantidadDeVecinos = 0;
                int alturaVecinos = 0;

                if(0 <= i-1){
                    cantidadDeVecinos++;
                    alturaVecinos = alturaVecinos + m[i-1][j].first;
                }
                if(i+1 < m.size()){
                    cantidadDeVecinos++;
                    alturaVecinos = alturaVecinos + m[i+1][j].first;
                }
                if(0<=j-1){
                    cantidadDeVecinos++;
                    alturaVecinos = alturaVecinos + m[i][j-1].first;
                }
                if(j+1 < m[0].size()){
                    cantidadDeVecinos++;
                    alturaVecinos = alturaVecinos + m[i][j+1].first;
                }
                int promedioVecinos = alturaVecinos / cantidadDeVecinos;
                res = res + (promedioVecinos - m[i][j].first);
                m[i][j].first = promedioVecinos;

            }
        }
    }
    int sumaAlturasNew =0;
    for(int i = 0; i<m.size(); i++){
        for(int j =0; j<m[0].size(); j++){
            sumaAlturasNew = sumaAlturasNew + m[i][j].first;
        }
    }


    res = abs(sumaAlturasNew - sumaAlturas);

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
