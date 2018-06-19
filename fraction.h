
//  This is the header file for a program that adds, subtracts, divides, multiplies, and simplifies
//  two fractions. The numerator and the denominator are stored inside seperate variables inside of the Fraction
//  class. Member functions inside the Function class compute arithmatic on two fractions, simplifies them and checks
//  If they are equal.
//  Public Member Functions;
//  Fraction(int,int); Construct that takes to values and sets numerator and denominator.
//  void print(); Takes a single fraction andPrints and simplifies fraction
//  Fraction addedTo: Addstwo fractions.
//  subtract; Subtracts 2 functions.
//  multipliedBy; Multiplies two numerators and two denominators
//  dividedby; Divides two numerators and two denominators
//  bool isEqualTo; Takes two fractions and checks if they are equal.
#ifndef FRACTION_h
#define FRACTION_h
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
using namespace std;
namespace cs_fraction{
    class fraction{
    private:
        int numerator; //Creating Private variables
        int denominator;
        void simplify();
    public:
        fraction();
        fraction(int numerator);
        fraction (int numerator,int denominator);
        friend ostream& operator<<(ostream& out, const fraction &right);
        friend istream& operator >> (istream& out, fraction &right);
        friend fraction operator+(const fraction &left, const fraction &right);
        friend fraction operator-(const fraction &left, const fraction &right);
        friend fraction operator*(const fraction &left, const fraction &right);
        friend fraction operator/(const fraction &left, const fraction &right);
        fraction operator+= (const fraction &right);
        fraction operator-= (const fraction &right);
        fraction operator *= (const fraction &right);
        fraction operator /=(const fraction &right);
        fraction operator++();
        fraction operator++(int);
        fraction operator--();
        fraction operator--(int);
        friend bool operator<(const fraction &left, const fraction &right);
        friend bool operator<=(const fraction &left, const fraction &right);
        friend bool operator>(const fraction &left, const fraction &right);
        friend bool operator >=(const fraction &left, const fraction &right);
        friend bool operator == (const fraction &left, const fraction &right);
        friend bool operator !=(const fraction &left, const fraction &right);
        void print() const;
        fraction addedTo(const fraction &f2) const;      // Made member functions public to interact with variables
        fraction subtract (const fraction &f2) const;    //Without effecting them.
        fraction multipliedBy(const fraction &f2) const;
        fraction dividedBy(const fraction &f2) const;
        bool isEqualTo(const fraction &f2) const;
        int getnumerator();
        int getdenominator();
        
        
    };
}
#endif
