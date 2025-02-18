#include "fraction.h"
#include <iostream>
using namespace std;

Fraction Fraction::operator -()
{
  return Fraction(-numerator,denominator);
}

Fraction& Fraction::operator++(){
      numerator += denominator;
      return *this;
    }

Fraction& Fraction::operator--(){
  numerator -= denominator;
  return *this;
}

Fraction& Fraction::operator +=(const Fraction oth){
  this->numerator = numerator * oth.denominator + oth.numerator * denominator;
  this->denominator = oth.denominator * denominator;
  return *this;
}

Fraction& Fraction::operator -=(const Fraction oth){
  this->numerator = numerator * oth.denominator - oth.numerator * denominator;
  this->denominator = oth.denominator * denominator;
  return *this;
}

Fraction& Fraction::operator *=(const Fraction oth){
  this->numerator = numerator * oth.numerator;
  this->denominator = denominator * oth.denominator;
  return *this;
}

Fraction& Fraction::operator /=(const Fraction oth){
  this->numerator = numerator * oth.denominator;
  this->denominator = denominator * oth.numerator;
  return *this;
}

Fraction Fraction::operator +(const Fraction oth){
  long num = this->numerator * oth.denominator + oth.numerator * this->denominator;
  long den = this->denominator * oth.denominator;
  return Fraction(num,den);
}

Fraction Fraction::operator -(const Fraction oth)const{
  long num = this->numerator * oth.denominator - oth.numerator * this->denominator;
  long den = this->denominator * oth.denominator;
  return Fraction(num,den);
}

Fraction operator*(const Fraction f1, const Fraction f2){
  long num = f1.numerator * f2.numerator ;
  long den = f1.denominator * f2.denominator;
  return Fraction(num,den);
}

Fraction operator / (const Fraction f1, const Fraction f2){
  long num = f1.numerator * f2.denominator;
  long den = f1.denominator * f2.numerator;
  return Fraction(num,den);
}

std::ostream& operator<<(ostream& os, const Fraction f1){
  os << f1.numerator << "/" << f1.denominator;
  return os;
}

std::istream& operator>>(istream& is, Fraction& frac){
  char s;
  is >> frac.numerator >> s >> frac.denominator;
  if(frac.numerator == 0) cout <<"digite um valor válido";
  return is;
  
}

double Fraction::frac(){
  int p = this->numerator;
  int a = this->denominator;
  double db = p/a;
  return db;
}