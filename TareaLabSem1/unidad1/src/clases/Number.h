//
// Created by jneira on 2020-04-09.
//

#ifndef POOII_NUMBER_H
#define POOII_NUMBER_H

#include "../tipos.h"

template<typename T>
class Number {
    T value;
public:
    T getV(){
      return value;
    };
    Number();
    Number(T value);
    Number(const Number& other);
    Number operator=(const Number& other);
    Number operator+(T value);
    Number operator+=(T value);
    Number operator-(T value);
    Number operator-=(T value);
    Number operator*(T value);
    Number operator*=(T value);
    Number operator/(T value);
    Number operator/=(T value);

    Number operator^(int value);
    operator int();
    operator long int();
    operator long long int();
    operator double();
    operator float();

    bool operator>(const Number& other);
    bool operator>=(const Number& other);
    bool operator<(const Number& other);
    bool operator<=(const Number& other);
    bool operator!=(const Number& other);
    bool operator==(const Number& other);

    template <typename U>
    friend ostream& operator <<(ostream& os, const Number<U>& other);

    template <typename U>
    friend istream& operator >>(istream& os, Number<U>& other);


};


#endif //POOII_NUMBER_H