#include <iostream>
#include <fstream>
#include <cstring>
#include "NFA.h"
//Funcion principal
int main(int argc, char *argv[]){
    char help[] = "--help";
    //Muestra el mansaje de ayuda 
    if(argc == 2 && strcmp(help, argv[1]) == 0 ) {
        std::cout << "Este programa escrito en C++ lee desde un fichero las especificaciones" << std::endl;
        std::cout << "de un NFA(input.nfa) y, a continuación, simule el comportamiento del" << std::endl;
        std::cout << "autómata, que se guardara en un fichero de texto(output.txt), para una" << std::endl;
        std::cout << "cadena que se suministre como entrada(input.txt)" << std::endl;
        return 1;
    }   
    //Muestra el mansaje de error
    if(argc < 4) {
        std::cout << "Modo de empleo: ./main_NFA input.nfa input.txt output.txt" << std::endl;
        std::cout << "Pruebe ’main_NFA --help’ para más información." << std::endl;
        return 1;
    }
    //Crea un objeto
    NFA nfa(argv[1]);
    //Abre el input.txt 
    std::ifstream infile(argv[2]);
    std::string line;
    //Abre el output.txt
    std::ofstream output(argv[3]);
    //Almacenara las cadenas linea a linea 
    //Almacena in el output.txt un si, si es verdadero o un no si es falso
    while(infile >> line) {
        bool resultado = nfa.Chek(line); 
        if(resultado == true) {
            output << "si" << std::endl;
        }else{
            output << "no" << std::endl;
        }
    }
    //Cierra los ficheros input.txt y output.txt
    infile.close();
    output.close();

    return 0;
    
} 