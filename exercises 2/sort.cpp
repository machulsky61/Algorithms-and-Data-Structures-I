#include <vector>
#include <iostream>

using namespace std;

int indiceMinSubsec(vector<int> v, int l, int r){
    int res = l;
    for(int i = l; i<=r; i++){
        if(v[i] < v[res]){res = i;}
    }
    return res;
}

void ordenar1(vector<int>& v){
    for(int l = 0; l < v.size(); l++){
        int min = indiceMinSubsec(v, l, v.size()-1);
        swap(v[l], v[min]);
    }
}

int main() {
    // Leo las entradas
    int n; //Longitud del vector
    cin >> n;
    int i = 0;
    int x;
    vector<int> v;// En v leo el vector
    while (i<n){
        cin >> x;
        v.push_back(x);
        i++;
    }
    // Hago el ordenamiento
    ordenar1(v);
    // Imprimo el vector resultado
    i = 0;
    while (i < v.size()){
        cout << v[i] << " ";
        i++;
    }
    return 0;
}