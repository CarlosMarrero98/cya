#include "NFA.h" 

// Constructor NFA
NFA::NFA(std::string fichero_NFA) {
    Build(fichero_NFA);
}
//Metodo check
//Primero comprueba si la cadena obtenida del input.txt tiene algun caracter que no pertenezca al alfabeto
//Usando el metodo CheckRecursive() compruebo si la cadena pertenece o no al NFA.
bool NFA::Chek(std::string cadena) {
    for(int i = 0; i < cadena.length(); i++) {
        bool result =  ChekLenguaje(cadena[i]);
        if(result == false) return false;
    }
    Estado inicial = GetEstadoByNombre(estado_inicial);
    return CheckRecursive(inicial, cadena, 0);
}
//Con el metodo Build le doy valores a los atributos
//Usando ifstream leo el fichero input.nfa
//Almaceno cada linea del fichero input.nfa en un vector, de dimension 100, de 
//nombre info_NFA. Y con "erase" ajusto la dimension del vector
//Los atributos total_de_estados y estado_inicial los obtengo de las dos primeras lineas
//del fichero input.nfa. Utilizo stoi para combertir un string en un numero
//El atributo estados lo obtengo de las sigientes lines del fichero. Utilizo la clase Estado y set 
//para ello
//El atributo alfabeto lo obtengo del atributo simbolo de la clase Estado
void NFA::Build(std::string fichero_NFA) {
    std::ifstream infile; 
    std::string line;
    infile.open(fichero_NFA, std::ios::in);
    
    std::vector<std::string> info_NFA(100); 
    int i = 0;
    while(!infile.eof()) {
        getline(infile, line);
        info_NFA[i] = line;
        i++;
    }
    info_NFA.erase(info_NFA.begin()+i,info_NFA.end());
    infile.close();
    
    total_de_estados = stoi(info_NFA[0]);
    estado_inicial = stoi(info_NFA[1]);
    for(int i = 2; i < info_NFA.size(); i++) {
        Estado estado(info_NFA[i]);
        estados.insert(estado);
    } 

    std::set<Estado>::iterator it = estados.begin(); 
    Estado aux = *estados.begin();
    while (it != estados.end()) { 
        aux = *it;
        std::vector<int> vector_aux = aux.GetSimbolo();
        for(int i = 0; i < vector_aux.size(); i++) {            
            alfabeto.insert(vector_aux[i]);
        }
        it++;        
    }    
}
//Con el atributo ChekLenguaje compruebo si una palabra de la cadena esta en alfabeto 
//Para ello le paso el parametro letra y la comparo con las que forman el atributo alfabeto
bool NFA::ChekLenguaje(int letra) {
    std::set<int>::iterator it = alfabeto.begin(); 
    int aux = *alfabeto.begin();
    while (it != alfabeto.end()) {  
        aux = *it;
        if(letra == aux) {
            return true;
        }
        it++;       
    }
    return false;
}
//Con el atributo GetEstadoByNombre obtengo un estado a partir del nombre del estado 
Estado NFA::GetEstadoByNombre(int nombre) {
    std::set<Estado>::iterator it = estados.begin();
    Estado estado = *estados.begin();
    while (it != estados.end()) {
        estado = *it;
        if (estado.GetNombre() == nombre) return estado;
        it++;
    }
}
//Con el atributo CheckRecursive de forma recursiva compruebo si la cadena pertenece o no al NFA
//A la funcion CheckRecursive le paso los parametros: estado, de tipo Estado, que nos dice el estado 
//siguiente del NFA, cadena, de tipo string, es la cadena que obtenemos del unput.txt y pos, de tipo int
//se utiliza para recorrer la cadena, si hay un ~ no consume una posicion
bool NFA::CheckRecursive(Estado estado, std::string cadena, int pos) {
    bool result = false;
    std::vector<int> aux_simbolos = estado.GetSimbolo();
    bool vacio = true;
    
    for (int i = 0; i < aux_simbolos.size(); i++) {
        if(aux_simbolos[i] == '~') {
            vacio = false;
        }
    }

    if ((cadena.length() == pos && vacio == true)) {
        //condicion de parada
        return estado.GetAceptacion() ? true : false;
    }else {
        std::vector<int> aux_simbolos = estado.GetSimbolo();
        std::vector<int> aux_siguiente = estado.GetSiguiente();
        for (int i = 0; i < estado.GetNumeroTransiciones(); i++) {
            if (aux_simbolos[i] == cadena[pos]) {
                Estado siguienteEstado = GetEstadoByNombre(aux_siguiente[i]);
                result = CheckRecursive(siguienteEstado, cadena, pos + 1);
                if (result) return true;
            }
            if(aux_simbolos[i] == 126) {   
                Estado siguienteEstado = GetEstadoByNombre(aux_siguiente[i]);
                result = CheckRecursive(siguienteEstado, cadena, pos);
                if (result) return true; 
            }
        }
        return false;
    }
}
