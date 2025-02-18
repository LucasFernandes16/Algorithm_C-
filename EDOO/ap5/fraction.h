#ifndef _FRACTION_H
#define _FRACTION_H

#include <iostream>
using namespace std;

class Fraction{
  private:
    long numerator,denominator;
  public:
    Fraction(long n= 0, long d =1){
      numerator = n;
      denominator = d;
    }

    Fraction operator -();

    Fraction& operator++();
    Fraction& operator--();

    Fraction& operator +=(const Fraction oth);
    Fraction& operator -=(const Fraction oth);
    Fraction& operator *=(const Fraction oth);
    Fraction& operator /=(const Fraction oth);

    Fraction operator +(const Fraction oth);
    Fraction operator -(const Fraction oth)const;
    friend Fraction operator *(const Fraction f1, const Fraction f2);
    friend Fraction operator / (const Fraction f1, const Fraction f2);

    friend ostream& operator<<(ostream& os, const Fraction f1);
    friend istream& operator>>(istream& is, Fraction& frac);
    
    double frac();
};

#endif