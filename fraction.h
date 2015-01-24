#pragma once

#include<iostream>
#include<utility>
using namespace std;


class fraction {
private:
	int n;
	int d;
	void simplify();
public:
	fraction() ;
	fraction(int n) ;
	fraction(int n, int d) ;
	int num() const ;
	int den() const ;

	//long forms of the attribute 
	//getters to match the spec
	int numerator() const ;
	int denominator() const ;

	bool operator==(const fraction &o) const ;
	bool operator<(const fraction &o) const ;
	fraction &operator+=(const fraction &o) ;
	fraction &operator-=(const fraction &o) ;
	fraction &operator*=(const fraction &o) ;
	fraction &operator/=(const fraction &o) ;


	operator double() const ;
};


//Maths
fraction operator+(fraction a, fraction b) ;
fraction operator+(int a, fraction b) ;
fraction operator+(fraction a, int b) ;

fraction operator-(fraction a, fraction b) ;
fraction operator-(int a, fraction b) ;
fraction operator-(fraction a, int b) ;

fraction operator*(fraction a, fraction b) ;
fraction operator*(int a, fraction b) ;
fraction operator*(fraction a, int b) ;

fraction operator/(fraction a, fraction b) ;
fraction operator/(int a, fraction b) ;
fraction operator/(fraction a, int b) ;


//Input and Output
ostream& operator<<(ostream &s, const fraction &f) ;

istream& operator>>(istream &s, fraction &f) ;
