
#ifndef LABOTESTING_EJ2_H
#define LABOTESTING_EJ2_H

#endif //LABOTESTING_EJ2_H
using namespace std;

// DEFINICIONES DE TIPO
typedef pair<int, int> posicion;
typedef int altura;
typedef int poblacion;
typedef pair<altura, poblacion> zona;
typedef vector<vector<zona > > mapa;

void swap(vector<posicion> &lista, int i, int j);

vector<posicion> bajaNatalidad(mapa m1, mapa m2);
