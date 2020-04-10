//
// Created by jneira on 2020-04-09.
//

#include "vector.h"
using namespace UTEC;

vector::vector(): capacity_{8}, size_{0} {
    data_ = new int[capacity_];
}

vector::vector(size_t size): size_{size} {
    capacity_ = 8;
    while(size > capacity_){
        capacity_ *= 2;
    }
    data_ = new int[capacity_];
    for(int i=0; i<size_; i++)
        data_[i] = 0;
}

vector::vector(const UTEC::vector &vc) {
    capacity_ = vc.capacity_;
    size_ = vc.size_;
    data_ = new int[capacity_];
    data_ = vc.data_;
}

vector::vector(int *data, size_t size) {
    size_ = size;
    capacity_ = 8;
    while(size > capacity_){
        capacity_ *= 2;
    }

    int* temp = new int[capacity_];
    for (size_t i = 0; i < size_; i++)
        temp[i] = data[i];

    data_ = new int[capacity_];
    data_ = temp;

    temp = nullptr;
    delete [] temp;
}

vector::~vector() {
    capacity_ = 8;
    size_ = 0;
    delete [] data_;
    data_ = nullptr;
}

vector vector::operator=(const vector &other) {
    this->capacity_ = 8;
    this->size_ = 0;
    delete [] this->data_;
    this->data_ = nullptr;

    this->capacity_ = other.capacity_;
    this->size_ = other.size_;

    int* temp = new int[this->capacity_];
    for (size_t i = 0; i < this->size_; i++)
        temp[i] = other.data_[i];
    delete [] data_;
    this->data_ = temp;

    temp = nullptr;
    delete [] temp;

    return vector();
}

void vector::push_back(int element) {
    if (size_ + 1 > capacity_) {
        capacity_ *= 2;
        int* temp = new int[capacity_];
        for (size_t i = 0; i < size_; i++)
            temp[i] = data_[i];
        delete [] data_;
        data_ = temp;
        temp = nullptr;
        delete [] temp;
    }
    data_[size_] = element;
    ++size_;
}

void vector::pop_back() {
    if(size_>0){
        if (size_ - 1 <= capacity_/2 && capacity_ > 8){
            capacity_ = capacity_ / 2;
            int* temp = new int[capacity_];
            for (size_t i = 0; i < size_-1; i++)
                temp[i] = data_[i];
            delete [] data_;
            data_ = temp;
            temp = nullptr;
            delete [] temp;
        }
        --size_;
    }
}

void vector::insert(size_t pos, int element) {
    if(pos < size_){
        if (size_ + 1 > capacity_) {
            capacity_ *= 2;
            int* temp = new int[capacity_];
            for (size_t i = 0; i < size_; i++)
                temp[i] = data_[i];
            delete [] data_;
            data_ = temp;
            temp = nullptr;
            delete [] temp;
        }

        for(size_t i = size_; i > pos; i--)
            data_[i] = data_[i-1];
        data_[pos] = element;
        ++size_;
    }
}

void vector::erase(size_t pos) {
    if(pos < size_){
        if (size_ - 1 <= capacity_/2 && capacity_ > 8){
            capacity_ = capacity_ / 2;
            int* temp = new int[capacity_];
            for (size_t i = 0; i < size_-1; i++)
                temp[i] = data_[i];
            delete [] data_;
            data_ = temp;
            temp = nullptr;
            delete [] temp;
        }
        for(size_t i = pos; i < size_ - 1; i++)
            data_[i] = data_[i+1];
        --size_;
    }
}

vector vector::operator+(const vector &other) {
    int* dataTotal;
    int sizeTotal = this->size_ + other.size_;
    dataTotal = new int[sizeTotal];
    for(int i=0; i<this->size_; i++)
        dataTotal[i] = this->data_[i];
    for(int i=0; i<other.size_; i++)
        dataTotal[i+this->size_] = other.data_[i];
    return vector(dataTotal, sizeTotal);
}

void vector::imprime() {
    for(size_t i = 0; i < size_; i++)
        std::cout << data_[i] << " ";
    std::cout << "\n";
    std::cout << "SIZE: " << size_ << " CAPACITY: " << capacity_ << "\n";
}