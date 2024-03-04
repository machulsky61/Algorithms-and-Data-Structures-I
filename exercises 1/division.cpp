#include <iostream>

void division(int dividendo, int divisor, int &cociente, int &resto){
  
    int i = dividendo - divisor;
    cociente = 0;
    
    while(i >= 0){
        cociente = cociente + 1;
        i = i - divisor;
    }
    resto = dividendo - divisor*cociente;
    }

using namespace std;
int main() {
    /* No hace falta modificar el main */
    //Leo la entrada
    int divisor,dividendo, cociente,resto;
    cin >> dividendo>>divisor;
    
    //Calculo la division
    division(dividendo,divisor,cociente,resto);
    
    //Salida
    cout << cociente << " " << resto;
    
    return 0;
}