#include <iostream>
#include "palindrome_prod.hpp"
using namespace std;

int main(int argc, char *argv[], char *arg[]) {
    if(argc < 2 || atoi(argv[1]) <= 0  ) {
        cout << "Uso del programa: main_capicua num(: num > 0)" << endl;
    }else {
        cout << "Entra en el programa" << endl;

        palindrome_prod(atoi(argv[1]), argv[2]);
    }

    return 0;

}