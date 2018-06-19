

//  In the Fraction Class there are two private member function;
//  "numerator" holds the value of the numerator of the fraction.
//  "Denominator" holds the denominator.
#include "fraction.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <string>
using namespace std;
namespace cs_fraction{
    fraction :: fraction()
    {
        numerator = 0;
        denominator = 1;
        simplify();
    }
    fraction :: fraction(int numer)
    {
        numerator = numer;
        denominator = 1;
    }
    fraction :: fraction(int numer, int denom)
    {
        numerator = numer;
        denominator = denom;
        assert(denominator !=0);
        simplify();
        
    }
    
    
    
    void fraction::print() const
    {
        
        fraction Fraction1(numerator, denominator);
        Fraction1.simplify();
        cout << Fraction1.numerator<<"/"<< Fraction1.denominator<<endl;
    };
    
    fraction operator+(const fraction &left, const fraction &right)
    {
        fraction fractplus;
        fractplus = left.addedTo(right);
        return fractplus;
    }
    
    fraction operator-(const fraction& left, const fraction& right)
    {
        fraction fractminus;
        fractminus = left.subtract(right);
        return fractminus;
    }
    fraction operator*(const fraction & left, const fraction &right)
    {
        fraction fractTimes;
        fractTimes = left.multipliedBy(right);
        return fractTimes;
    }
    
    fraction operator/(const fraction &left, const fraction &right)
    {
        fraction fractDivide;
        fractDivide = left.dividedBy(right);
        return fractDivide;
    }
    fraction fraction ::operator+=(const fraction &right)
    {
        *this = *this + right;
        return *this;
    }
    fraction fraction ::operator-=(const fraction &right)
    {
        *this = *this -right;
        return *this;
        
    }
    
    fraction fraction ::operator*=(const fraction &right)
    {
        *this = *this * right;
        return *this;
        
    }
    fraction fraction ::operator/=(const fraction &right)
    {
        *this = *this / right;
        return *this;
        
    }
    fraction fraction :: operator++()
    {
        numerator+=denominator;
        return *this;
    }
    fraction fraction :: operator++(int)
    {
        fraction temp(numerator, denominator);
        numerator+= denominator;
        return temp;
    }
    fraction fraction :: operator--()
    {
        numerator -= denominator;
        return *this;
    }
    fraction fraction :: operator--(int)
    {
        fraction temp(numerator, denominator);
        numerator = numerator - denominator;
        return temp;
    }
    
    ostream& operator<<(ostream& out, const fraction &right){
        int c;
        fraction temp(right.numerator, right.denominator);
        if(temp.numerator<0){
            temp.numerator*=-1;
        }
        if (temp.denominator<0){
            temp.denominator*=-1;
        }
        if(temp.numerator== temp.denominator){
            out << (right.numerator/right.denominator);
            return out;
        }
        if(temp.numerator < temp.denominator){
            out << right.numerator << "/" << right.denominator;
            return out;
        }else{
            c=(temp.numerator % temp.denominator);
            out <<(right.numerator-c)/right.denominator;
            if(temp.numerator % temp.denominator != 0){
                out <<"+"<< c << "/"<< temp.denominator;
            }
        }
        return out;
    }
    istream &operator >>(istream &in, fraction &right){
        int temp;
        in >> temp;
        if (in.peek() == '+'){
            in >> temp;
            in.ignore();
            return in;
        } else if (in.peek() == '/'){
            in.ignore();
            return in;
        } else {
            in.ignore();
            return in;
        }
    }
    
    bool operator<(const fraction &left, const fraction &right)
    {
        int fractl = (left.numerator * right.denominator);
        int fractr = (left.denominator * right.numerator);
        if (fractl < fractr){
            return true;
        }else{
            return false;
        }
        
    }
    
    bool operator>(const fraction &left, const fraction &right)
    {
        int fractl = (left.numerator * right.denominator);
        int fractr = (left.denominator * right.numerator);
        if (fractl > fractr){
            return true;
        }else{
            return false;
        }
        
    }
    bool operator<=(const fraction &left, const fraction &right)
    {
        int fractl = (left.numerator * right.denominator);
        int fractr = (left.denominator * right.numerator);
        if (fractl <= fractr){
            return true;
        }else{
            return false;
        }
        
    }
    bool operator>=(const fraction &left,const fraction &right)
    {
        
        int fractl = (left.numerator * right.denominator);
        int fractr = (left.denominator * right.numerator);
        if (fractl >= fractr){
            return true;
        }else{
            return false;
        }
        
    }
    bool operator!=(const fraction &left, const fraction &right)
    {
        int fractl = (left.numerator * right.denominator);
        int fractr = (left.denominator * right.numerator);
        if (fractl != fractr){
            return true;
        }else{
            return false;
        }
        
    }
    bool operator==(const fraction &left, const fraction &right)
    {
        int fractl = (left.numerator * right.denominator);
        int fractr = (left.denominator * right.numerator);
        if (fractl == fractr){
            return true;
        }else{
            return false;
        }
        
    }
    
    fraction fraction::multipliedBy(const fraction &f2) const //Member function multiplies fraction 1 by fraction 2
    {
        
        fraction Fraction1(numerator * f2.numerator,denominator * f2.denominator);
        Fraction1.simplify();
        return Fraction1;
    };
    
    
    
    
    
    
    fraction fraction::dividedBy(const fraction &f2) const// Member function divides fraction1 by fraction 2
    {
        fraction Fraction1(numerator * f2.denominator,denominator * f2.numerator);
        Fraction1.simplify();
        return Fraction1;
    };
    
    
    
    
    
    
    bool fraction::isEqualTo(const fraction &f2) const// Member Function checks if fractions are equal
    {                                            // Returns true or false
        int numer;
        int denom;
        numer =(numerator * f2.denominator);
        denom =(denominator * f2.numerator);
        if(numer == denom){
            return true;
        }else{
            return false;
        }
    };
    
    
    
    
    
    
    fraction fraction::subtract(const fraction &f2) const//Member function subracts fraction1 by fraction 2
    {
        int numer1;
        int denom1;
        int numer2;
        int denom2;
        numer1 =(numerator * f2.denominator);
        denom1 =(denominator * f2.denominator);
        numer2 =(f2.numerator * denominator);
        denom2 = (f2.denominator * denominator);
        fraction Fraction1(numer1 - numer2, denom1);
        Fraction1.simplify();
        return Fraction1;
        
    };
    
    
    
    
    
    
    fraction fraction::addedTo(const fraction &f2) const//Member function adds fraction 1 to fraction 2
    {
        int numer1;
        int denom1;
        int numer2;
        int denom2;
        numer1 =(numerator * f2.denominator);
        denom1 =(denominator * f2.denominator);
        numer2 =(f2.numerator * denominator);
        denom2 = (f2.denominator * denominator);
        fraction Fraction1(numer1 + numer2 , denom1);
        Fraction1.simplify();
        return Fraction1;
        
    };
    
    
    
    
    
    
    int fraction::getnumerator()//Function gets the value of the numerator of an object fraction
    {
        cout << numerator;
        return numerator;
    };
    
    
    
    
    
    
    int fraction::getdenominator()//Function gets the value of the denominator of an object fraction
    {
        cout << denominator;
        return denominator;
    };
    
    void fraction :: simplify(){
        int c;
        int small;
        int big;
        int numer;
        int denom;
        if (numerator < 0 ){
            numer = (numerator *-1);
        }else{
            numer = numerator;
        }
        if(denominator < 0){
            denom = (denominator *-1);
        }else{
            denom = denominator;
        }
        if(numer < denom){
            small = numer;
            big = denom;
        }else{
            small = denom;
            big = numer;
        }
        
        
        for(c=2;c<small+1;c++){
            
            if (numerator % c == 0 && denominator % c == 0){
                numerator = numerator/c;
                denominator = denominator/c;
                c=1;
            }}
        }
    
    
}