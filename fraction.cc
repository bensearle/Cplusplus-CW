#include<iostream>
#include<utility>
#include"fraction.h"
using namespace std;

int gcd(const int &x, const int &y) {
	if (y==0)
		return abs(x);
	else
		return gcd(y, x % y);
}

int lcm(const int &x, const int &y) {
	return abs(x * (y / gcd(x,y)));
}

void fraction::simplify() {
	int g = gcd(n,d);
	if (g != 0) {
		n = n/g;
		d=  d/g;
	}
}

fraction::fraction() {
	n=0;
	d=1;
}

fraction::fraction(int num) {
	n=num;
	d=1;
}

fraction::fraction(int num, int den) {
	if (den == 0) {
		n=0;
		d=0;
	} else {
		n=num;
		d=den;
		simplify();
	}
}

int fraction::num() const { return n; }
int fraction::den() const { return d; }

//long forms of the attribute 
//getters to match the spec
int fraction::numerator() const { return num(); }
int fraction::denominator() const { return den(); }

fraction & fraction::operator+=(const fraction &o) {
	int m = lcm(d,o.den());
	n = n * m/d + o.num() * m/o.den();
	d = m;
	simplify();
	return *this;
}

fraction & fraction::operator-=(const fraction &o) {
	fraction minus(-o.num(),o.den());
	return operator+=(minus);
}

fraction & fraction::operator*=(const fraction &o) {
	n*=o.num();
	d*=o.den();
	simplify();
	return *this;
}

fraction & fraction::operator/=(const fraction &o) {
	n*=o.den();
	d*=o.num();
	simplify();
	return *this;
}


bool fraction::operator<(const fraction &o) const {
	int m = lcm(d,o.den());
	if (n * m/d < o.num() * m/o.den())
		return true;
	return false;
}


bool fraction::operator==(const fraction &o) const {
	if (n == o.num() && d == o.den())
		return true;
	return false;
}

fraction operator+(fraction a, fraction b) {return a+=b;}
fraction operator+(int a, fraction b) {return fraction(a)+=b;}
fraction operator+(fraction a, int b) {return b+a;}

fraction operator-(fraction a, fraction b) {return a-=b;}
fraction operator-(int a, fraction b) {return fraction(a)-=b;}
fraction operator-(fraction a, int b) {return a-=fraction(b);}

fraction operator*(fraction a, fraction b) {return a*=b;}
fraction operator*(int a, fraction b) {return fraction(a)*=b;}
fraction operator*(fraction a, int b) {return b*a;}

fraction operator/(fraction a, fraction b) {return a/=b;}
fraction operator/(int a, fraction b) {return fraction(a)/=b;}
fraction operator/(fraction a, int b) {return a/=fraction(b);}

ostream& operator<<(ostream &s, const fraction &f) {
	return s << f.num() << '/' << f.den();
}

istream& operator>>(istream &s, fraction &f) {
	int n,d;
	char slash;
	if ((s >> n >> slash >> d) &&
			(slash == '/'))
		f = fraction(n,d);
	else
		s.setstate(ios::badbit);
	return s;
}


fraction::operator double() const {
	return n/static_cast<double>(d);
}
