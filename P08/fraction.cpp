/*
Create a class Fraction for performing arithmetic operations with fractions according to the specification below. You are free to name the attributes of the class, but the names and signatures of the member functions must be as stated.

    Use private int member fields to represent the numerator and the denominator.
    Provide two constructors for the class: a default constructor that initialises the numerator with 0 and denominator with 1, and a constructor that takes two int arguments, corresponding to the numerator and denominator values. You may assume that the denominator is always different from 0.
    The constructors must ensure that the fraction is stored in normalised form, that is, it must be irreducible and the denominator must always be positive. For example, the fractions 3/15, -3/-4 and 2/-4 must be stored, respectively, as 1/5, 3/4 and -1/2.
    Define public numerator() and denominator() accessors for the numerator and denominator fields.
    Provide public member functions to perform the basic arithmetic operations with fractions: sum, subtraction, multiplication and division, with the following corresponding signatures:

  Fraction sum(const Fraction& right)
  Fraction sub(const Fraction& right)
  Fraction mul(const Fraction& right)
  Fraction div(const Fraction& right)

The code of the following functions is given in the file fraction_aux.h and must be inserted in the correct place:

    Fraction::gcd, to calculate the greatest common divisor of 2 numbers;
    Fraction::normalise, to normalise a fraction;
    Fraction::write, to write a fraction on the screen.

Note that you need to declare these functions in the Fraction class. 

*/



class Fraction {
    public:
    Fraction();
    Fraction(int num, int den);
    int denominator() const;
    int numerator() const;
    Fraction sum(const Fraction& right);
    Fraction sub(const Fraction& right);
    Fraction mul(const Fraction& right);
    Fraction div(const Fraction& right);
    void normalise();
    void write() const;

   

    
    private:
    static int gcd(int a, int b);
    int numerator_;
    int denominator_;
    



};


#include <iostream>
#include "fraction_aux.h"

Fraction::Fraction() : numerator_(0), denominator_(1) {}
Fraction::Fraction(int num, int den) {
    numerator_ = num;
    denominator_ = den;
    normalise();
}

int Fraction::numerator() const {
    return numerator_;
}

int Fraction::denominator() const {
    return denominator_;
}

Fraction Fraction::sum(const Fraction& right) {
    return Fraction(numerator_*right.denominator_+right.numerator_*denominator_,denominator_*right.denominator_);


    }
Fraction Fraction::sub(const Fraction& right) {
    return Fraction(numerator_*right.denominator_-right.numerator_*denominator_,denominator_*right.denominator_);

}
Fraction Fraction::mul(const Fraction& right) {
    return Fraction(numerator_*right.numerator_,denominator_*right.denominator_);
    }
Fraction Fraction::div(const Fraction& right) {

    return Fraction(numerator_*right.denominator_,denominator_*right.numerator_);
}

int main() {
  // public tests (1 point each)
  { 
    Fraction().sum({2, 4}).write(); cout << ' ';
    Fraction(1,1).sum({2, 4}).write(); cout << ' ';
    Fraction(2,4).sum({3, 9}).write(); cout << ' ';
    Fraction(-2,4).sum({1, 2}).write(); cout << ' ';
    Fraction(3,27).sum({-27, 81}).write(); cout << '\n';
  } // -> 1/2 3/2 5/6 0/1 -2/9
  { 
    Fraction().sub({2, 4}).write(); cout << ' ';
    Fraction(1,1).sub({2, 4}).write(); cout << ' ';
    Fraction(2,4).sub({3, 9}).write(); cout << ' ';
    Fraction(-2,4).sub({1, 2}).write(); cout << ' ';
    Fraction(3,27).sub({-27, 81}).write(); cout << '\n';
  } // -> -1/2 1/2 1/6 -1/1 4/9 
  { 
    Fraction().mul({2, 4}).write(); cout << ' ';
    Fraction(1,1).mul({2, 4}).write(); cout << ' ';
    Fraction(2,4).mul({3, 9}).write(); cout << ' ';
    Fraction(-2,4).mul({1, 2}).write(); cout << ' ';
    Fraction(3,27).mul({-27, 81}).write(); cout << '\n';
  } // -> 0/1 1/2 1/6 -1/4 -1/27
  { 
    Fraction().div({2, 4}).write(); cout << ' ';
    Fraction(1,1).div({2, 4}).write(); cout << ' ';
    Fraction(2,4).div({3, 9}).write(); cout << ' ';
    Fraction(-2,4).div({1, 2}).write(); cout << ' ';
    Fraction(3,27).div({-27, 81}).write(); cout << '\n';
  } // -> 0/1 2/1 3/2 -1/1 -1/3
  cout << '\n';
  // private (1000 points each)
  { 
    Fraction().sum({-12, 44}).write(); cout << ' ';
    Fraction(1,12).sum({1, 24}).write(); cout << ' ';
    Fraction(-1,12).sum({3, 24}).write(); cout << ' ';
    Fraction(-7,5).sum({5, 7}).write(); cout << ' ';
    Fraction(8,9).sum({13, 18}).write(); cout << '\n';
  } // -> -3/11 1/8 1/24 -24/35 29/18
  { 
    Fraction().sub({-12, 44}).write(); cout << ' ';
    Fraction(1,12).sub({1, 24}).write(); cout << ' ';
    Fraction(-1,12).sub({3, 24}).write(); cout << ' ';
    Fraction(-7,5).sub({5, 7}).write(); cout << ' ';
    Fraction(8,9).sub({13, 18}).write(); cout << '\n';
  } // -> 3/11 1/24 -5/24 -74/35 1/6
  { 
    Fraction().mul({-12, 44}).write(); cout << ' ';
    Fraction(1,12).mul({1, 24}).write(); cout << ' ';
    Fraction(-1,12).mul({3, 24}).write(); cout << ' ';
    Fraction(-7,5).mul({5, 7}).write(); cout << ' ';
    Fraction(8,9).mul({13, 18}).write(); cout << '\n';
  } // -> 0/1 1/288 -1/96 -1/1 52/81
  { 
    Fraction().div({-12, 44}).write(); cout << ' ';
    Fraction(1,12).div({1, 24}).write(); cout << ' ';
    Fraction(-1,12).div({3, 24}).write(); cout << ' ';
    Fraction(-7,5).div({5, 7}).write(); cout << ' ';
    Fraction(8,9).div({13, 18}).write(); cout << '\n';
  } // -> 0/1 2/1 -2/3 -49/25 16/13

  return 0;
}