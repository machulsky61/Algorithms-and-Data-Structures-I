#include <vector>
#incluide <iostream>

using namespace std;
//SELECTION SORT; O(n^2)
int findMinPosition(vector<int> &s, int d, int h) {
    int min = d;
    for(int i=d+1; i<h; i++) {
        if (s[i] < s[min]) {
            min = i;
        }
    }
    return min;
}
void selectionSort(vector<int> &s) {
    for(int i=0; i<s.size(); i++) {
        int minPos = findMinPosition(s,i,s.size());
        swap(s, i, minPos);
    }
}

// INSERTION SORT; O(n^2)
void insertionSort(vector<int> &s) {
        for(int i=0; i<s.size(); i++) {
            for(int j=i; j>0 && s[j] < s[j-1]; j--) {
                swap(s[j], s[j-1]);
            }
        }
    }

// BUBBLE SORT; O(n^2)
vector <int> bubbleSort(vector <int> lista){
    for(int i=0; i<lista.size(); i++){
        for(int j = lista.size() - 1; j > i; j--){
            if(lista[j] < lista[j-1]){
                swap(lista[j], lista[j-1]);
            }
        }
    }
    return lista;
}

// COUNTING SORT; O(n) solo sirve si tenemos una cota del maximo elemento q puede aparecer en la secuencia
vector <int > countingSort(vector <int > &lista){
    vector <int > conteo = contar(lista);
    return reconstruir(lista ,conteo);
}
vector <int > contar(vector <int > &lista){
    //creo un vector inicializado en 0
    //cuya longitud sea igual a una cota maxima
    vector <int> conteo(COTA ,0);
    for(int i=0;i < lista.size();i++){
        conteo[lista[i]]++;
    }
    vector <int> reconstruir(vector <int > &lista , vector <int> conteo){
        vector <int > resultado(lista.size());
        int indice_conteo = 0;
        for(int i = 0; i<lista.size(); i++){
            // Ignoro valores nulos
            while(conteo[indice_conteo] == 0){
                indice_conteo++;
            }
            lista[i] = indice_conteo;
            conteo[indice_conteo ]--;
        }
    }

// COCKTAIL SORT; O(n^2) derivado del selection sort. busca en cada iteracion el maximo y el mınimo de la secuencia por ordenar, intercambiando el mınimo con i y el maximo con |v|−i −1
void cocktailSort(vector<int> &v){
    int final = v.size();
    for(int i = 0; i < v.size(); i++) {
        int indiceMin = i;
        int indiceMax = final-1;
        for(int j = i; j < final; j++){
            if(v[j] < v[indiceMin])
                indiceMin = j;
            if(v[j] > v[indiceMax])
                indiceMax = j;
        }
        swap(v[i], v[indiceMin]);
        swap(v[final-1], v[indiceMax]);
        final--;

    }
}

// BINGO SORT; O(n^2) derivado del selection sort. sirve para cuando hay muchos elementos repetidos en la seq
void bingoSort(vector<int> &v){
    vector<int> indicesMinimos;
    int i = 0;
    while (i < v.size()){
        int min = v[i];
        indicesMinimos.clear();

        for(int j = i; j < v.size(); j++){
            if(v[j] == min){
                indicesMinimos.push_back(j);
            }
            if(v[j] < min){
                indicesMinimos.clear();
                indicesMinimos.push_back(j);
                min = v[j];
            }
        }
        for(int k = 0; k < indicesMinimos.size(); k++){
            swap(v[i], v[indicesMinimos[k]]);
            i++;
        }
    }
}

// COCKTAIL SHAKER SORT; O(n^2) derivado del bubble sort. Hace una primera pasada para adelante en la lista, y una segunda pasada de regreso y asi hasta ordenar todo.
void cocktailShakerSort(vector<int> &v) {
    int j;
    for (int i = 0; i < v.size(); i++) {
        for (j = i; j < v.size() - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
            }
        }
        for (j = v.size()-1-i; j > i; j--) {
            if (v[j] < v[j - 1]) {
                swap(v[j], v[j - 1]);
            }
        }
    }
}


//MERGE de secuencias ordenadas; O(n)
vector<int> merge(vector<int> &a, vector<int> &b) {
    vector<int> c(a.size()+b.size(),0);
    int i = 0;
    int j = 0;
    for(int k=0; k < c.size(); k++) {
        if( j>=b.size() || (i<a.size() && a[i] < b[j] )) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = b[j];
            j++;
        }
    }
    return c;
}

// THE WELFARE CROOK; O(n+m+l); dadas 3 seq ordenadas, sabemos que hay al menos un elemento en comun entre ellos. Encontrar los ındices donde esta al menos uno de estos elementos repetidos.
void crook(vector<int> &a, vector<int> &b, vector<int> &c, int &i, int &j, int &k) {
    i = 0, j = 0, k = 0;
    while( a[i] != b[j] || b[j] != c[k] ) {
        if( a[i] < b[j] ) {
            i++;
        } else if( b[j] < c[k] ) {
            j++;
        } else {
            k++;
        }
    }
}