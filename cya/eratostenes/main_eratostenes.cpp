//Autor:Marrero Martin, Carlos
//Alu: 0101210995
//Correo: alu0101210995@ull.edu.es
//Universidad de La Laguna 
//Escuela Superior de Ingenieria y Tecnologia
//Grado ingenieria informatica
//Curso: 2º
//Practica 2: La criba de Erathostenes
//Enunciado de la practica:

#include <iostream>
#include <cmath>
using namespace std;

void eratostenes(int size_);
void sieve(bool vector_[], int size_);
void remove(bool vector_[], int size_);



int main(int argc, char *argv[]) {
    if(argc < 2) {
        cout << "Uso del programa: main_eratostenes num" << endl;
    }else{
        eratostenes(atoi(argv[1]));
    }
    





    return 0;
}



void eratostenes(int size_) {
    bool vector_[size_];
    for(int i = 0; i < size_; i++) {
        vector_[i] = true;
    }

    sieve(vector_, size_);
}

void sieve(bool vector_[], int size_){
    for(int i = 2; i < size_; i++){
        for(int j = 2; i*j < size_; j++){
            vector_[i*j] = false;
        }
    }

    remove(vector_, size_);

    
}

void remove(bool vector_[], int size_){
    for(int i = 2; i < size_; i++){
        if(vector_[i] == true){
            cout << i << ' ';
        }
    }
    cout << endl;
}