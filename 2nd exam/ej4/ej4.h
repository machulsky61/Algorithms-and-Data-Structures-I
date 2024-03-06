//
// Created by Joaqu on 19/11/2021.
//

#ifndef LABOTESTING_EJ4_H
#define LABOTESTING_EJ4_H

#endif //LABOTESTING_EJ4_H
using namespace std;

// DEFINICIONES DE TIPO
typedef pair<int, int> posicion;
typedef int altura;
typedef int poblacion;
typedef pair<altura, poblacion> zona;
typedef vector<vector<zona > > mapa;

bool esValle(mapa m, posicion p);

int rellenarValles(mapa &m);