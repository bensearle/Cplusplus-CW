#include <iostream>
#include <vector>
#include <algorithm>
#include <float.h> //for DBL_MAX and -DBL_MAX
#include <math.h>
using namespace std;

template<typename T>
samplet<T>::samplet() : number(0) {}

template<typename T>
samplet<T>::samplet(int num) : number(num) {}

template<typename T>
samplet<T>::samplet(vector<T> values) : number(0), values(values) {}

template<typename T>
samplet<T>::samplet(int num, vector<T> values) : number(num), values(values) {}

template<typename T>
int samplet<T>::num() const { return number; }

template<typename T>
void samplet<T>::set_num(const int &n)
{
	number = n;
}

// 2.3 q15
// The return types have been changed to T
// to accomodate any object being put into samplet.

// 2.2 q2
template<typename T>
ostream & operator<<(ostream & s, const samplet<T>& samplet){
	s << "<" << ' ' << samplet.num() << " : ";
	for(auto y = begin(samplet.get_data()); y != end(samplet.get_data()); ++y){
		s << *y << ' ';
	}
	s << ">";
	return s;
}

// 2.2 q3
template<typename T>
const vector<T> &samplet<T>::get_data() const
{
	return values;
}

// 2.2 q4
template<typename T>
void samplet<T>::set_data(const vector<T> &v)
{
	values = v;
}

// 2.2 q5
template<typename T>
T samplet<T>::maximum()
{
	T max = values[0];
	for (T d : values){ // for each 'd' in the vector
        if (max < d) // if d is greater
            max = d;
	}
	return max;
}

// 2.2 q6
template<typename T>
T samplet<T>::minimum()
{
	T min = values[0];
	for (T d : values){ // for each 'd' in the vector
		// if max is null
        if (min > d) // if d is less than
            min = d;
	}
	return min;
}

// 2.2 q7
template<typename T>
T samplet<T>::range()
{
	T range = maximum() - minimum();
	return range;
}

// 2.2 q8
template<typename T>
T samplet<T>::midrange()
{
	T midrange = (maximum() + minimum()) / 2;
	return midrange;
}

// 2.2 q9
template<typename T>
T samplet<T>::mean()
{
	T total = 0; // the sum of numbers. Changed to long double for q14
	for (T d : values){ // for each 'd' in the vector
		total += d;
	}
	T mean = total / values.size();
	return mean;
}

// 2.2 q10
template<typename T>
T samplet<T>::variance()
{
	T samplet_mean = mean();
	T size = 0; // count of how many numbers
	T variance_square = 0; // Changed to long T for q14
	for (T d : values){
		variance_square += (samplet_mean - d)*(samplet_mean - d);
		++size;
	}
	T variance = variance_square / size;
	return variance;
}

// 2.2 q11
template<typename T>
T samplet<T>::std_deviation()
{
	T std_deviation = sqrt(variance());
	return std_deviation;
}

// 2.2 q12
template<typename T>
T samplet<T>::median()
{
	int vector_size = values.size();
	sort(begin(values),end(values), [] (const int & a, const int & b) {return a < b;} );
	T median; // Changed to long double for q14
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
template<typename T>
istream & operator>>(istream &in, samplet<T> &s){
	char start_bracket, colon, end_bracket;
	std::vector<T> values;
	int number;
	T y;

	if (in >> start_bracket) {
		if ((in >> number >> colon) && (start_bracket == '<' && colon == ':')) {
			while(in >> y){
				values.push_back(y);
			}
			in.clear();
			if ((in >> end_bracket) && (end_bracket == '>')) {
				s = samplet<T>(number,values);
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
