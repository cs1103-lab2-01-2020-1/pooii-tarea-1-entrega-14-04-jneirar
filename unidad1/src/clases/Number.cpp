//
// Created by jneira on 2020-04-09.
//

#include "Number.h"

template <typename T>
Number<T>::Number(){
    this->value = 0;
}

template <typename T>
Number<T>::Number(T value){
    this->value = value;
}

template <typename T>
Number<T>::Number(const Number& other){
    this->value = other.value;
}

template <typename T>
Number<T> Number<T>::operator=(const Number &other) {
    this->value = other.value;
    return Number(this->value);
}

template <typename T>
Number<T> Number<T>::operator+(T value){
    return Number(this->value + value);
}

template <typename T>
Number<T> Number<T>::operator+=(T value){
    this->value += value;
    return Number(this->value);
}

template <typename T>
Number<T> Number<T>::operator-(T value){
    return Number(this->value - value);
}

template <typename T>
Number<T> Number<T>::operator-=(T value){
    this->value -= value;
    return Number(this->value);
}

template <typename T>
Number<T> Number<T>::operator*(T value){
    return Number(this->value * value);
}

template <typename T>
Number<T> Number<T>::operator*=(T value){
    this->value *= value;
    return Number(this->value);
}

template <typename T>
Number<T> Number<T>::operator/(T value){
    return Number(this->value / value);
}

template <typename T>
Number<T> Number<T>::operator/=(T value){
    this->value /= value;
    return Number(this->value);
}

template <typename T>
Number<T> Number<T>::operator^(int pot){
    T res=1;
    if(pot==0)  return Number(1);
    for(int i=0; i<pot; i++)
        res = res * this->value;
    return Number(res);
}

template <typename T>
Number<T>::operator T() {
    return value;
}

template <typename T>
bool Number<T>::operator>(const Number& other){
    if(this->value > other.value)   return true;
    else    return false;
}

template <typename T>
bool Number<T>::operator>=(const Number& other){
    if(this->value >= other.value)   return true;
    else    return false;
}

template <typename T>
bool Number<T>::operator<(const Number& other){
    if(this->value < other.value)   return true;
    else    return false;
}

template <typename T>
bool Number<T>::operator<=(const Number& other){
    if(this->value <= other.value)   return true;
    else    return false;
}

template <typename T>
bool Number<T>::operator!=(const Number& other){
    if(this->value != other.value)   return true;
    else    return false;
}

template <typename T>
bool Number<T>::operator==(const Number& other){
    if(this->value == other.value)   return true;
    else    return false;
}

template <typename U>
ostream& operator <<(ostream& os, const Number<U>& other){
    os << other.value;
    return os;
}

template <typename U>
istream& operator >>(istream& os, Number<U>& other){
    os >> other.value;
    return os;
}