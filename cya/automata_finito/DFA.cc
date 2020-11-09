#include <string.h>
#include <iostream>
#include <fstream>
#include <set>
#include "DFA.hpp"
using namespace std;

DFA::DFA(int ksize, string kpattern) {
    size = ksize;
    pattern = kpattern; 
    build();
}

void DFA:: build() {
    int nombre = 0;
    bool aceptacion = false;
    for(int nombre = 0; nombre < size + 1; nombre++){
        string aux = pattern;
    
        if(size == nombre){
            aceptacion = true;
        }
        Estado q(nombre, nombre + 1, pattern[nombre], aceptacion);
        estados.insert(q);
    }
}

bool DFA::chek(string linea){
    Estado estado0 = *estados.begin();
    for(int i = 0; i < linea.size(); i++){
        Estado estadoactual = estado0;
        while(estadoactual.getsimbolo() == linea[i]  ){
            Estado aux;
            for(set<Estado>::iterator j = estados.begin(); j != estados.end(); j++ ){
                aux = *j;
                if(aux.getnombre() == estadoactual.getsig()){
                    break;
                }
            }
            estadoactual = aux;
            i ++;
            if (estadoactual.getaceptacion() == true){
                return true;
            }
        }
    }
    return false;
}