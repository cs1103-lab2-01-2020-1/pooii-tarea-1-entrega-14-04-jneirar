#include "Integer.h"

Integer::Integer(){
    this->value = 0;
}

Integer::Integer(int value){
    this->value = value;
}

Integer::Integer(const Integer& other){
    this->value = other.value;
}

Integer Integer::operator=(const Integer& other){
    this->value = other.value;
    return Integer(this->value);
}

Integer Integer::operator+(int value){
    return Integer(this->value+value);
}

Integer::operator int(){
    return this->value;
}

ostream& operator <<(ostream& os, const Integer& other){
    os << other.value;
    return os;
}

istream& operator >>(istream& os, Integer& other){
    os >> other.value;
    return os;
}

Integer Integer::operator^(int pot){
    int res=1;
    if(pot==0)  return Integer(1);
    for(int i=0; i<pot; i++)
        res = res * this->value;
    return Integer(res);
}

Integer Integer::operator+=(int value) {
    this->value += value;
    return Integer(this->value);
}

Integer Integer::operator-(int value){
    return Integer(this->value - value);
}

Integer Integer::operator-=(int value){
    this->value -= value;
    return Integer(this->value);
}

Integer Integer::operator*(int value){
    return Integer(this->value * value);
}

Integer Integer::operator*=(int value){
    this->value *= value;
    return Integer(this->value);
}

Integer Integer::operator/(int value){
    return Integer(this->value / value);
}

Integer Integer::operator/=(int value){
    this->value /= value;
    return Integer(this->value);
}

bool Integer::operator>(const Integer& other){
    if(this->value > other.value)   return true;
    else    return false;
}

bool Integer::operator>=(const Integer& other){
    if(this->value >= other.value)   return true;
    else    return false;
}

bool Integer::operator<(const Integer& other){
    if(this->value < other.value)   return true;
    else    return false;
}

bool Integer::operator<=(const Integer& other){
    if(this->value <= other.value)   return true;
    else    return false;
}

bool Integer::operator!=(const Integer& other){
    if(this->value != other.value)   return true;
    else    return false;
}

bool Integer::operator==(const Integer& other){
    if(this->value == other.value)   return true;
    else    return false;
}
