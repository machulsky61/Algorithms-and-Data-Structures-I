#include <vector>
#incluide <iostream>

using namespace std;
//BUSQUEDA LINEAL; O(n)
bool busquedaLineal(vector<int> lista, int x){
    bool res = false;
    for(int i=0; i < lista.size() ; i++){
        if(lista[i] == x){
            res = true;
        }
    }
    return res;
}

// BUSQUEDA DE MIN Y MAX; O(n)
vector<int> buscarMinyMax(vector<int> v){
    int min = v[0];
    int max = v[0];
    for(int i = 0; i < v.size(); i++){
        if( max < v[i]){
            max = v[i];
        }
        if(v[i] < min){
            min = v[i];
        }
    }
    vector<int> res = {min,max};
    return res;
}

// BINARY SEARCH; O(log(n))
bool contieneOrdenada(vector<int>&s, int x) {
    //casos triviales
    if (s.size()==0 ) {
        return false;
    } else if (s.size()==1) {
        return s[0]==x;
    } else if (x<s[0]) {
        return false;
    } else if (x>=s[s.size() - 1]) {
        return s[s.size()-1]==x;
    } else {
        //casos no triviales
        int low = 0;
        int high = s.size() - 1;
        while( low+1 <high ) {
            int mid = (low+high) /2;
            if( s[mid] <= x ) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return s[low] == x;
    }
}