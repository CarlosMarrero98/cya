#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
#include <vector> 
using namespace std;

class Estado { 
    public:
      Estado(string info_estado);
      Estado(){}
      ~Estado(){}
      bool operator<(const Estado &estado) const;
      int GetNombre() const;
      int GetNumeroTransiciones() const;
      bool GetAceptacion() const;
      vector<int> GetSimbolo() const;
      vector<int> GetSiguiente() const;

      
    private: 
      int nombre; 
      int numero_transiciones;
      bool aceptacion;
      vector<int> siguiente;
      vector<int> simbolo;
};  