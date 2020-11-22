#include "NFA.hpp" 


NFA::NFA(string fichero_NFA) {
    Build(fichero_NFA);
}

bool NFA::Chek(string cadena){
    
    for(int i = 0; i < cadena.length(); i++){
        bool result =  ChekLenguaje(cadena[i]);
        if(result == false) return false;
    }

    Estado inicial = GetEstadoByNombre(estado_inicial);
    bool checked = CheckRecursive(inicial, cadena, 0);
    return checked;
/*
    Estado estado_actual = *estados.begin();
    for(int i = 0; i < cadena.size(); i++) {
        vector<int> aux_simbolo = estado_actual.GetSimbolo();
        for(int j = 0; j < estado_actual.GetSimbolo().size(); j++){
            if(cadena[i] == aux_simbolo[j]) {
                //si ocurre
                vector<int> aux_nobre = estado_actual.GetSiguiente();
                Estado aux;

                for(set<Estado>::iterator it = estados.begin(); it != estados.end(); it ++) {
                    aux = *it;
                    if(aux.GetNombre() == aux_nobre[j]){
                        estado_actual = aux;
                        if(estado_actual.GetAceptacion() == true) return true; 
                    }
                }
            }
        }
    }

    return false;*/
}

void NFA::Build(string fichero_NFA){
    
    ifstream infile; //lee el archivo input.nfa
    string line;
    infile.open(fichero_NFA, ios::in);
    
    vector<string> info_NFA(100); //Donde almaceno la info del NFA

    int i = 0;
    while(!infile.eof()) {
        getline(infile, line);
        info_NFA[i] = line;
        i++;
    }
    infile.close();
    
    info_NFA.erase(info_NFA.begin()+i,info_NFA.end()); //cambio el tamaño de mi vector
    
    total_de_estados = stoi(info_NFA[0]); //con stoi combierto un string en un numero
    estado_inicial = stoi(info_NFA[1]);
    for(int i = 2; i < info_NFA.size(); i++){
        Estado estado(info_NFA[i]);
        estados.insert(estado);
    } 

    //Creo alfabeto
    set<Estado>::iterator it = estados.begin(); 
    Estado aux = *estados.begin();
    while (it != estados.end()) {  // recorro el set 
        aux = *it;
        vector<int> vector_aux = aux.GetSimbolo();

        for(int i = 0; i < vector_aux.size(); i++) {            
            alfabeto.insert(vector_aux[i]);
        }
        it++;        
    }    
}

bool NFA::ChekLenguaje(int letra) {
    set<int>::iterator it = alfabeto.begin(); 
    int aux = *alfabeto.begin();
    while (it != alfabeto.end()) {  
        aux = *it;
        if(letra == aux){
            return true;
        }
        it++;       
    }
    return false;
}

Estado NFA::GetEstadoByNombre(int nombre) {
    // Obtener estado siguiente a partir de su nombre
    set<Estado>::iterator it = estados.begin();
    Estado estado = *estados.begin();
    while (it != estados.end())
    { // recorro el set
        estado = *it;
        if (estado.GetNombre() == nombre)
            return estado;
        it++;
    }
}

bool NFA::CheckRecursive(Estado estado, string cadena, int pos) {
    bool result = false;
    vector<int> aux_simbolos = estado.GetSimbolo();
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

        vector<int> aux_simbolos = estado.GetSimbolo();
        vector<int> aux_siguiente = estado.GetSiguiente();

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
