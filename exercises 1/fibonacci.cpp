#include <iostream>

using namespace std;

// Funcion de fibonacci que calcula n-esimo termino
int fibonacci(int n){
    int fn1;
    int fn2;
    for(int i = 0; i <= n; i = i + 1){
        if(i == 0){
            fn1=0;
        }
        if(i == 1){
            fn2 = 0;
            fn1 = 1;
        }
        if(i > 1){
            fn1 = fn2 + fn1;
            fn2 = fn1 - fn2;
        }
    }
    return fn1;
}
int main() 
{
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;    
    return 0;
}