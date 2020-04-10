//
// Created by jneira on 2020-04-09.
//

#ifndef POOII_VECTOR_H
#define POOII_VECTOR_H

#include <iostream>

namespace UTEC{
    class vector {
        int* data_;
        size_t size_;
        size_t capacity_;
    public:
        vector();
        ~vector();
        vector(size_t size);
        vector(const vector& other);
        vector(int* data, size_t size);
        vector operator=(const vector& other);
        void push_back(int element);
        void pop_back();
        void insert(size_t pos, int element);
        void erase(size_t pos);
        vector operator+(const vector& other);
        void imprime();
    };
}


#endif //POOII_VECTOR_H
