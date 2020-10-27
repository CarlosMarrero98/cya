#include <iostream>
#include <fstream>
#include <cstring>

#include "fibonacci_words.hpp"

using namespace std;

int main(int argc, char *argv[], char *arg[]) {

    char help[] = "--help";



    if(argc == 2 && strcmp(help, argv[1]) == 0 ){
        cout << "Explicar" << endl;
        exit(0);
    }   

    if(argc < 3) {
        cout << "ERROR" << endl;
        exit(0);
    }




    ifstream archivo;
    string palabra;
    archivo.open(argv[1], ios::in);

    
    while(!archivo.eof()) {
        getline(archivo,palabra);

        cout << palabra << endl;
        cout << palabra.length() <<endl;
        
        FibonacciWords pal(palabra);
        
    }
    archivo.close();


    //hacer el fibonatchi hasta que el tamaño de la cadena sea igual la leido por pantalla y cuando sean iguales conparar 
    




    return 0;
}

    





    
