#include <iostream>
#include <cstring>
#include <fstream>
#include <set>
#include <vector> 
#include "Estados.hpp"

using namespace std;
class NFA {
    public:
      NFA(string fichero_NFA);
      bool Chek(string cadena); 
      

    private: 
      set<int> alfabeto;
      int estado_inicial;
      int total_de_estados;
      set<Estado> estados;
      bool ChekLenguaje(int letra);
      void Build(string fichero_NFA);
      Estado GetEstadoByNombre(int nombre);
      bool CheckRecursive(Estado estado, string cadena, int pos);
};  