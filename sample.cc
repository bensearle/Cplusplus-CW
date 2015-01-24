#include <iostream>
#include <vector>
#include <algorithm>
#include <float.h> //for DBL_MAX and -DBL_MAX
#include <math.h>
#include "sample.h"
using namespace std;

//see header file for comments on our weird constructors!
sample::sample() : number(0) {}

sample::sample(int num) : number(num) {}

sample::sample(vector<double> values) : number(0), values(values) {}

sample::sample(int num, vector<double> values) : number(num), values(values) {}

int sample::num() const { return number; }

void sample::set_num(const int &n)
{
	number = n;
}

// 2.2 q1
// How could you have forced programmers using your class to not initialise empty sample
// objects (i.e., without providing a vector to initialise them with)?
//
// Remove sample constructors that don't specify the vector input,
// and raise an error if the vector supplied is empty

// 2.2 q2
ostream & operator<<(ostream & s, const sample& sample){
	s << "<" << ' ' << sample.num() << " : ";
	for(auto y = begin(sample.get_data()); y != end(sample.get_data()); ++y){
		s << *y << ' ';
	}
	s << ">";
	return s;
}

// 2.2 q3
const vector<double> &sample::get_data() const
{
	return values;
}

// 2.2 q4
void sample::set_data(const vector<double> &v)
{
	values = v;
}

// 2.2 q5
double sample::maximum()
{
	double max = -DBL_MAX;
	for (double d : values){ // for each 'd' in the vector
        if (max < d) // if d is greater
            max = d;
	}
	return max;
}

// 2.2 q6
double sample::minimum()
{
	double min = DBL_MAX;
	for (double d : values){ // for each 'd' in the vector
		// if max is null
        if (min > d) // if d is less than
            min = d;
	}
	return min;
}

// 2.2 q7
double sample::range()
{
	double range = maximum() - minimum();
	return range;
}

// 2.2 q8
double sample::midrange()
{
	double midrange = (maximum() + minimum()) / 2;
	return midrange;
}

// 2.2 q9
double sample::mean()
{
	long double total = 0; // the sum of numbers. Changed to long double for q14
	for (double d : values){ // for each 'd' in the vector
		total += d;
	}
	double mean = total / values.size();
	return mean;
}

// 2.2 q10
double sample::variance()
{
	double sample_mean = mean();
	double size = 0; // count of how many numbers
	long double variance_square = 0; // Changed to long double for q14
	for (double d : values){
		variance_square += (sample_mean - d)*(sample_mean - d);
		++size;
	}
	double variance = variance_square / size;
	return variance;
}

// 2.2 q11
double sample::std_deviation()
{
	double std_deviation = sqrt(variance());
	return std_deviation;
}

// 2.2 q12
double sample::median()
{
	int vector_size = values.size();
	sort(begin(values),end(values), [] (const int & a, const int & b) {return a < b;} );
	long double median; // Changed to long double for q14
	if (vector_size % 2 == 0) // if vector is even length
	{
		median = (values[vector_size / 2 - 1] + values[vector_size / 2]) / 2.0;
	}
	else // if vector is odd length
	{
		median = values[vector_size / 2];
	}

	return median;
}

// 2.2 q13
istream & operator>>(istream &in, sample &s){
	char start_bracket, colon, end_bracket;
	std::vector<double> values;
	int number;
	double y;

	if (in >> start_bracket) {
		if ((in >> number >> colon) && (start_bracket == '<' && colon == ':')) {
			while(in >> y){
				values.push_back(y);
			} 
			in.clear();
			if ((in >> end_bracket) && (end_bracket == '>')) {
				s = sample(number,values);
				return in;
			}
		}
	}
	in.setstate(ios::badbit); // read failed
	return in;
}

// 2.2 q14
/*
Running the code from page 4:
$ ./2.2-14 
<2: 1.7976931348623158e+308 1.7976931348623158e+308 >

< 2 : 1.79769e+308 1.79769e+308 >
min 1.79769e+308
max 1.79769e+308
range 0
midrange inf
median inf
mean inf
variance inf
std_dev inf


The problem is the values are too close to DBL_MAX, so trying to add them results in the value going above the maximum value allowed for a double, it is seen as infinite and then +,-,*,/ an inf results in inf.
We have changed the value inside of the relevant methods to long double.
*/
