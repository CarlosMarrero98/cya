#include <math.h>

#include <iostream>
#include <fstream>

#include "fibonacci_words.hpp"

using namespace std;

void leer(char *file_name) {
    ifstream archivo;
    string palabra;
    archivo.open(file_name, ios::in);

    while(!archivo.eof()) {
        getline(archivo,palabra);
        cout << palabra << endl;
    }

    archivo.close();
}