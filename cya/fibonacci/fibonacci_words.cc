#include <math.h>
#include <string.h>

#include <iostream>
#include <fstream>

#include "fibonacci_words.hpp"

using namespace std;

FibonacciWords::FibonacciWords(string palabra) {
    kWord = palabra;
}

void FibonacciWords::print() {
    cout << kWord << endl;
}



