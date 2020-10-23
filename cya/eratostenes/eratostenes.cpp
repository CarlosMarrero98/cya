


#include <iostream>
#include <cassert>
#include <cmath>
#include "eratostenes.hpp"

void eratostenes(int size_) {
    int vector_[size_];
    for(int i = 0; i < size_; i++){
        vector_[i] = true;
    }

    cout << vector_[3] << endl;
}