/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * 2º curso
 * Computabilidad y Algoritmia
 * Práctica Nº: 8
 *
 * @tittle: Autómatas Finitos No Deterministas
 *
 * @author: Carlos Marrero Martin
 * @date:   17 Nov 2020
 * @email:  alu0101210995@ull.edu.es
 * @brief:  Esta aplicacion se utiliza para simular un NFA cargado desde un archivo
 * de entrada, llamado input.nfa, pasado por parametro. Y tambien simula el comportamiento
 * para una lista de cadena introducida por un archivo, llamada input.txt, 
 * @see:    P08.pdf
 *
 * @folder:      cd practicas/cya/NFA/
 * @compilation: make
 * @removebuild: make clean
 * @execution:   ./main_NFA input.nfa input.txt output.txt
 *
 */
#include <iostream>
#include <cstring>
#include <fstream>
#include <set>
#include <vector> 
#include "Estado.h"
/** @brief Diseño de un automata finito no determinista y comprueba si una cadena pertenece al NFA
 * 
 */
class NFA {
    public:
      /**
       * @brief Constructor de la clase NFA. Utilizo el metodo privado Build() para hacerlo
       * @param fichero_NFA Es el nombre del fichero en el que se especifica el NFA
       */ 
      NFA(std::string fichero_NFA);
      /**
       * @brief Destructor de la clase NFA
       */
      ~NFA(){}
      /**
       * @brief Metodo que comprueba si una cadena pertenece al NFA. Utilizo los metodos 
       * privados ChekLenguaje(), para comprobar si la cadena pertenece al lenguaje,
       * GetEstadoByNombre(), para obtener un estado a partir de su nombre y 
       * CheckRecursive(), de forma recursiva compruebo si la cadena pertenece o no al NFA.
       * Tambien me ayudo de la clase Estado.h para crear el atributo estados.
       * @param cadena Es una cadena que se obtiene del input.txt
       * @return Retorna true si pertenece o false si no pertenece 
       */
      bool Chek(std::string cadena); 

    private: 
      std::set<int> alfabeto;
      int estado_inicial;
      int total_de_estados;
      std::set<Estado> estados;
      bool ChekLenguaje(int letra);
      void Build(std::string fichero_NFA);
      Estado GetEstadoByNombre(int nombre);
      bool CheckRecursive(Estado estado, std::string cadena, int pos);
};  