#include <iostream>
#include <fstream>
#include <cstring>

#include "DFA.hpp"

using namespace std;
int main(int argc, char *argv[]) {

    char help[] = "--help";

    if(argc == 2 && strcmp(help, argv[1]) == 0 ){
        cout << "Este programa realiza una búsqueda de patrones, mediante un DFA, dentro de una cadena.\n" <<endl;
        cout << "   LA FORMA CORRECTA DE EJECUCION ES LA SIGUIENTE:" << endl;
        cout << "   ./main pattern infile.txt  outfile.txt" << endl ;
        cout << "   El parámetro ¨pattern¨ especifica el patrón de búsqueda " << endl;
        cout << "   El fichero de entrada(infile.txt) contendrá una línea\n    por cada cadena que se desee analizar en busca del patrón." << endl;
        cout << "   El fichero de salida (outfile.txt) almacena los resultados del programa" << endl;
        return 1;;
    }   
 
    if(argc < 4) {
        cout << "Número de argumentos incorrectos" << endl;
        cout << "Introduzca como argumento “--help” para más información de la ejecución del programa" << endl;
        return 1;
    }

    char *pattern = argv[1];
    int size = 0;
    while(pattern[size] != '\0') {
        size++;
    }

    DFA dfa(size, argv[1]);

    ifstream infile(argv[2]); //lee el archivo infile.txt
    ofstream output(argv[3]);
    string line;

    while(infile >> line){
        bool resultado = dfa.chek(line);
        if(resultado == true){
            output << "si" << endl;
        }else{
            output << "no" << endl;
        }
    }

    infile.close();
    output.close();

    return 0;
}
