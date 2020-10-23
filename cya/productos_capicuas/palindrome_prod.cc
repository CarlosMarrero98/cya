#include <iostream>
#include <math.h>
#include <fstream>
#include "palindrome_prod.hpp"
using namespace std;


void palindrome_prod(int num_digitos, char* file_name) {
    int num_inicio, num_final, num_aux;
    num_final = pow(10,num_digitos);
    num_inicio = pow(10,(num_digitos-1));
    num_aux = num_inicio;

    ofstream archivo;
    archivo.open(file_name, ios::out);
    

    for(int i; num_aux < num_final; num_aux ++){
        num_inicio = num_aux;
        for(int j; num_inicio < num_final; num_inicio ++){
            int mul = 0, resto = 0, numlnv = 0, aux = 0;
            mul = num_aux * num_inicio;
            aux = mul;

            while(aux > 0) {
                resto = aux%10;
                aux = aux/10;
                numlnv = numlnv*10 + resto;
            }

            if(numlnv == mul) {

                archivo<< num_aux << " x " << num_inicio << " = "<< mul <<endl;

            }
        }
    }

    archivo.close();
}