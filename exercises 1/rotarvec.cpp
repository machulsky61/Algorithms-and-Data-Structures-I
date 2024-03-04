#include <iostream>
#include <vector>

using namespace std;

vector<int> rotar(vector<int> v, int k){
    
    int i = 0;
    int longitudV = v.size();
    vector<int> vectorRotado;
    int loQueMeFaltaAgregar = k;
    
    while(k<longitudV){
        vectorRotado.push_back(v[k]);
        k=k+1;
    }
    
   while(i<loQueMeFaltaAgregar){
       vectorRotado.push_back(v[i]);
        i=i+1;
   }


return vectorRotado;

}

int main() {
    /* No hace falta modificar el main */
    // Leo las entradas
    int n; //Longitud del vector a rotar
    cin >> n;
    int i = 0;
    int x;
    vector<int> v;// En v leo el vector
    while (i<n){
        cin >> x;
        v.push_back(x);
        i++;
    }
    
    int k; // La cantidad que tengo que rotar la guardo en k
    cin >> k;
    
    // Hago la rotacion
    vector<int> res = rotar(v,k);
    i = 0;
    
    // Imprimo el vector resultado
    while (i < res.size()){
        cout << res[i] << " ";
        i++;
    }

    return 0;
}