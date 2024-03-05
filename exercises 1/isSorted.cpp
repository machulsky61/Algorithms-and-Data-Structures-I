#include <iostream>
#include <vector>

using namespace std;

bool estaOrdenadoCrecientemente(vector<int> v){
    int i = 0;
    int contador = 0;
  while(i < v.size() && v[i] <= v[i+1]){
      i = i + 1;
      contador = contador + 1;
  }
  if(contador == v.size()){return true;}else{return false;}
}

bool estaOrdenadoDecrecientemente(vector<int> v){
    int contador = 0;
    for(int i = 0; i < v.size(); i = i + 1)
        if(v[i]>=v[i+1]){contador=contador +1;}else{contador = contador;}
    if(contador == v.size()){return true;}else{return false;}
}

bool estaOrdenado(vector<int> v){
    if(v.size()==0){
        return false;
    }
   if(v.size()==1){
        return true;
    }
if(estaOrdenadoCrecientemente(v) || estaOrdenadoDecrecientemente(v)){return true;}else{return false;}
}

 int main() {
    // Leo las entradas
    int n; 
    cin >> n;
    int i = 0;
    int x;
    vector<int> v;// En v leo el vector
    while (i<n){
        cin >> x;
        v.push_back(x);
        i++;
    }
    // Evaluo si el vector v esta ordenado
    bool res = estaOrdenado(v);
    // Imprimo la salida
    cout << (res?"True":"False");
    return 0;
}