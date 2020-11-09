#include "estado.hpp"

Estado::Estado(int knombre, int ksig, char ksimbolo, bool kaceptacion){
    nombre = knombre;
    sig = ksig;
    simbolo = ksimbolo;
    aceptacion = kaceptacion;
}

bool Estado::operator<(const Estado &estado) const{
    if(this->nombre < estado.getnombre())
        return true;
    else 
        return false;
}

int Estado::getnombre() const{
    return nombre;
}

char Estado::getsimbolo() const{
    return simbolo;
}

int Estado::getsig() const{
    return sig;
}

bool Estado::getaceptacion() const{
    return aceptacion;
}