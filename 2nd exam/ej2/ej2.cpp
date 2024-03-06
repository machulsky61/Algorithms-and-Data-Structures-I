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


void swap(vector<posicion> &lista, int i, int j){
    posicion k=lista[i];
    lista[i]= lista[j];
    lista[j]=k;
}

int abs(int x){
    if(x < 0){
        return -x;
    } else {return x;}
}

vector<posicion> bajaNatalidad(mapa m1, mapa m2) {

    vector<poblacion> diferenciasPoblacionales;

    for(int i = 0; i < m1.size(); i++){
        for(int j = 0; j < m1[0].size(); j++){
            int diferenciaPoblacional = abs(m2[i][j].second - m1[i][j].second);
            diferenciasPoblacionales.push_back(diferenciaPoblacional);
        }
    }
    int min = 0;
    for(int i=0; i < diferenciasPoblacionales.size(); i++){ //busco la min diferencia
        if(diferenciasPoblacionales[i] < min){
            min = diferenciasPoblacionales[i];
        }
    }
    vector<posicion> res;
    for(int i = 0; i < m1.size(); i++){
        for(int j = 0; j < m1[0].size(); j++){
            if(abs(m2[i][j].second - m1[i][j].second == min)){
                res.push_back(make_pair(i,j)); // me aseguro q en res esten todos los q tienen diferencia =min
            }
        }
    }
    for(int i = 0; i<res.size(); i++){
        for(int j=res.size()-1; j>i; j--){
            if(m2[res[j].first][res[j].second] < m2[res[j-1].first][res[j-1].second]){
                swap(res, j, j-1);
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

    // El mapa 2
    int f2;
    cin >> f2;
    int c2;
    cin >> c2;
    mapa m2;
    char aux2;
    int alt2;
    int pob2;
    for (int i = 0; i < f2; i++) {
        vector<zona> fila2;
        for (int j = 0; j < c2; j++) {
            cin >> aux2;
            cin >> alt2;
            cin >> aux2;
            cin >> pob2;
            cin >> aux2;
            fila2.push_back(make_pair(alt2, pob2));
        }

        m2.push_back(fila2);
    }

    // Invoco la función
    vector<posicion> pos = bajaNatalidad(m, m2);

    // Ordeno el vector
   // Deja de ser necesario porque ahora va ordenado de acuerdo a especificación std::sort(pos.begin(), pos.end());

    // Imprimo la salida
    for (int i = 0; i < pos.size(); i++) {
        cout << "(" << pos[i].first << "," << pos[i].second << ") ";
    }

    return 0;
}
