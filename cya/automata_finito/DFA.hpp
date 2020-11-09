#include "estado.hpp"
#include <set>

using namespace std;
class DFA {
    public:
      DFA(int ksize, string kpattern);
      ~DFA(){}
      bool chek(string linea);
      
    private: 
      int size;
      string pattern;
      set<Estado> estados;
      void build();
};  