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

    leer(argv[1]);


    return 0;
}

    





    
