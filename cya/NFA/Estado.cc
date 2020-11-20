#include "Estados.hpp"

Estado::Estado(string info_estado) {

    nombre = info_estado[0] - '0';
    aceptacion = info_estado[2] - '0';
    numero_transiciones = info_estado[4] - '0';

    siguiente.resize(numero_transiciones);
    simbolo.resize(numero_transiciones);

    int j = 0;
    for(int i = 6; i < info_estado.length(); i += 4) {
        simbolo[j] =  info_estado[i];
        j++;
    }

    j = 0;
    for(int i = 8; i < info_estado.length(); i += 4) {
        siguiente[j] =  info_estado[i] - '0';
        j++;
    }
}

bool Estado::operator<(const Estado &estado) const{
    if(this->nombre < estado.GetNombre())
        return true;
    else 
        return false;
}

int Estado::GetNombre() const{
    return nombre;
}

int Estado::GetNumeroTransiciones() const{
    return numero_transiciones;
}

vector<int> Estado::GetSimbolo() const{
    return simbolo;
} 

vector<int> Estado::GetSiguiente() const{
    return siguiente;
} 

bool Estado::GetAceptacion() const{
    return aceptacion;
}