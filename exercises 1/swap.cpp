#include <iostream>

using namespace std;

void swap(int &a, int &b){
    int x = a;
    int y = b;
    
    a=y;
    b=x;
    
}

int main() {
    /* No hace falta modificar el main */
    int a,b;
    //Leo a
    cin >> a >> b;
    
    swap(a,b);
    
    //Devuelvo despues del swap
    cout << a << " " << b;
    return 0;
}

