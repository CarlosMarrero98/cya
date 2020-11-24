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
 * @brief:  Esta aplicacion se utiliza para crear los estados que van a formar el NFA  
 * @see:    P08.pdf
 *
 * @folder:      cd practicas/cya/NFA/
 * @compilation: make
 * @removebuild: make clean
 * @execution:   ./main_NFA input.nfa input.txt output.txt
 *
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
#include <vector> 
class Estado { 
    public:
      /**
       * @brief Constructor de la clase Estado.
       * @param info_estado Es un string con la informacion para crear un estado
       */
      Estado(std::string info_estado);
      /**
       * @brief Constructor por defecto
       */
      Estado(){}
      /**
       * Destructor de la clase Estado 
       */
      ~Estado(){}
      /**
       * Sobrecarga del operador  
       */
      bool operator<(const Estado &estado) const;
      /**
       * @brief Get del atributo nombre
       * @return Retorna el valor del atributo Nombre
       */
      int GetNombre() const;
      /**
       * @brief Get del atributo numero_transiciones
       * @return Retorna el valor del atributo numero_transiciones
       */
      int GetNumeroTransiciones() const;
      /**
       * @brief Get del atributo aceptacion
       * @return Retorna el valor del atributo aceptacion
       */
      bool GetAceptacion() const;
      /**
       * @brief Get del atributo simbolo
       * @return Retorna el valor del atributo simbolo
       */
      std::vector<int> GetSimbolo() const;
      /**
       * @brief Get del atributo siguiente
       * @return Retorna el valor del atributo siguiente
       */
      std::vector<int> GetSiguiente() const;

    private: 
      int nombre;
      int numero_transiciones;
      bool aceptacion;
      std::vector<int> siguiente;
      std::vector<int> simbolo;
};  