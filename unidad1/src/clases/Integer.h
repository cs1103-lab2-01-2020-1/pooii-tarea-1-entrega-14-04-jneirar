#ifndef POOII_INTEGER_H
#define POOII_INTEGER_H

#include "../tipos.h"

class Integer {
    int value;
public:
    Integer();
    Integer(int value);
    Integer(const Integer& other);
    Integer operator=(const Integer& other);
    Integer operator+(int value);
    operator int();
    friend ostream& operator <<(ostream& os, const Integer& other);
    friend istream& operator >>(istream& os, Integer& other);

    Integer operator^(int value);

    Integer operator+=(int value);
    Integer operator-(int value);
    Integer operator-=(int value);
    Integer operator*(int value);
    Integer operator*=(int value);
    Integer operator/(int value);
    Integer operator/=(int value);

    bool operator>(const Integer& other);
    bool operator>=(const Integer& other);
    bool operator<(const Integer& other);
    bool operator<=(const Integer& other);
    bool operator!=(const Integer& other);
    bool operator==(const Integer& other);

};

#endif //POOII_INTEGER_H
