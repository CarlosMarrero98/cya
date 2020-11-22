#include <iostream>
#include <fstream>
#include <cstring>
#include "NFA.hpp" 

using namespace std;

int main(int argc, char *argv[]){
    char help[] = "--help";

    if(argc == 2 && strcmp(help, argv[1]) == 0 ) {
        cout << "Este programa escrito en C++ lee desde un fichero las especificaciones" <<endl;
        cout << "de un NFA(input.nfa) y, a continuación, simule el comportamiento del" <<endl;
        cout << "autómata, que se guardara en un fichero de texto(output.txt), para una" <<endl;
        cout << "cadena que se suministre como entrada(input.txt)" <<endl;
        return 1;
    }   
 
    if(argc < 4) {
        cout << "Modo de empleo: ./main_NFA input.nfa input.txt output.txt" << endl;
        cout << "Pruebe ’main_NFA --help’ para más información." << endl;
        return 1;
    }

    cout << "Entra en el programa" << endl;

    NFA nfa(argv[1]);

    ifstream infile(argv[2]); //lee el archivo infile.txt
    string line;
    ofstream output(argv[3]);

    while(infile >> line) {
        bool resultado = nfa.Chek(line); 
        if(resultado == true) {
            output << "si" << endl;
        }else{
            output << "no" << endl;
        }
    }

    infile.close();
    output.close();

    return 0;
    
} 