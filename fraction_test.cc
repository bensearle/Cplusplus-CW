#include "fraction.h"
#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>

using namespace std;

int main() {
//setup
	fraction f1 = fraction();
	fraction f2 = fraction(5);
	fraction f3 = fraction(2,6);

	fraction f35 = fraction(3,5);

//constructors
	assert(f1.numerator()==0);
	assert(f1.denominator()==1);

	assert(f2.numerator()==5);
	assert(f2.denominator()==1);

	assert(f3.numerator()==1);
	assert(f3.denominator()==3);

//equality
	fraction eq(1,3);
	assert((f3==eq)==true);

//lessthan
	assert(f3<f35);
	assert(f35<f2);

//+=
	f35 += fraction(1,5);
	assert(fraction(4,5)==f35);

//adds
	assert(fraction(32,6)==f2+f3);
	assert(fraction(8,6)==f3+1);
	assert(fraction(14,6)==2+f3);

//minus
	assert(fraction(28,6)==f2-f3);
	assert(fraction(-4,6)==f3-1);
	assert(fraction(10,6)==2-f3);

//times
	assert(fraction(5,3)==f2*f3);
	assert(fraction(1,3)==f3*1);
	assert(fraction(2,3)==f3*2);
	assert(fraction(4,15)==f35*f3);

//divide
	assert(fraction(15)==f2/f3);
	assert(fraction(1,3)==f3/1);
	assert(fraction(5,2)==2/f35);

//input
	string str ("4/5");
	istringstream instream (str);
	fraction inputtest;
	instream >> inputtest;
	assert(inputtest==fraction(4,5));

//output
	ostringstream outstream ("");
	outstream << inputtest;
	assert(outstream.str() == "4/5");
}
