#include "Estado.h"
const unsigned kZero = '0';
//Constructor Estado
//Los atributos nombre, aceptacion y numero_transiciones los obtengo de las tres primeras posiciones
//del info_estado, las cuales estan separadas por un espacio. Utilizo la constante kZero para cambiar
//un char por un int.
//Las siguientes posiciones de info_estado las utilizo para crear los atributos siguiente y simbolo,
//de tipo vector, que contiene el nombre del estado siguiente y el simbolo  
Estado::Estado(std::string info_estado) {
    nombre = info_estado[0] - kZero;
    aceptacion = info_estado[2] - kZero;
    numero_transiciones = info_estado[4] - kZero;

    siguiente.resize(numero_transiciones);
    simbolo.resize(numero_transiciones);
    int j = 0;
    for(int i = 6; i < info_estado.length(); i += 4) {
        simbolo[j] =  info_estado[i];
        j++;
    }
    j = 0;
    for(int i = 8; i < info_estado.length(); i += 4) {
        siguiente[j] =  info_estado[i] - kZero;
        j++;
    }
}

bool Estado::operator<(const Estado &estado) const {
    if(this->nombre < estado.GetNombre())
        return true;
    else 
        return false;
}

int Estado::GetNombre() const{
    return nombre;
}

int Estado::GetNumeroTransiciones() const {
    return numero_transiciones;
}

std::vector<int> Estado::GetSimbolo() const {
    return simbolo;
} 

std::vector<int> Estado::GetSiguiente() const {
    return siguiente;
} 

bool Estado::GetAceptacion() const {
    return aceptacion;
}