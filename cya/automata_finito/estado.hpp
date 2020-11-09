using namespace std;
class Estado {
    public:
      Estado(int knombre, int ksig, char ksimbolo, bool kaceptacion);
      Estado(){}
      ~Estado(){}
      bool operator<(const Estado &estado) const;
      int getnombre() const;
      char getsimbolo() const;
      int getsig() const;
      bool getaceptacion() const;
      
    private: 
      int nombre;
      int sig;
      char simbolo;
      bool aceptacion;
};  