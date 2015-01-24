#include "sample.h"
#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>
#include <cmath> //for isnan

#include <vector>

using namespace std;

int main() {
//setup
	sample sempty = sample();
	vector<double> v = vector<double>();
	v.push_back(1);
	sample s1 = sample(v);
	v.push_back(5.7);
	v.push_back(83842.222);
	v.push_back(-3);
	sample s2 = sample(2,v);

//constructors
	assert(sempty.get_data().size() == 0);
	assert(s1.get_data().size() == 1);
	assert(s2.get_data().size() == 4);

//output
	ostringstream outstream ("");
	outstream << s2;
	assert(outstream.str() == "< 2 : 1 5.7 83842.2 -3 >");

//input
	sample inputtest;
	istringstream instream (outstream.str());
	instream >> inputtest;
	assert(inputtest.get_data().size() == 4);

//tests from Christos' example
	sample christos_example;
	instream.str( "<6:7 11 2 13 3 5>");
	instream >> christos_example;
	assert(christos_example.get_data().size() == 6);
	assert(christos_example.minimum() == 2);
	assert(christos_example.maximum() == 13);
	assert(christos_example.range() == 11);
	assert(christos_example.midrange() == 7.5);
	assert(christos_example.median() == 6);
	assert(0 < christos_example.mean() && christos_example.mean() - 6.83333 < 0.001);
	assert(0 < christos_example.mean() && christos_example.variance() - 16.1389 < 0.001);
	assert(0 < christos_example.mean() && christos_example.std_deviation() - 4.01732 < 0.001);

//0 sample size test
	sample zero_sample(0,vector<double>());
	assert(std::isnan(zero_sample.mean()));
	assert(std::isnan(zero_sample.variance()));

}
