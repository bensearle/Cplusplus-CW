#pragma once
#include<iostream>
#include<utility>
#include<vector>
using namespace std;

class sample {
private:
	int number;
	vector<double> values; // vector of doubles
public:
	sample();
	sample(int);
	sample(vector<double> values);
	sample(int number, vector<double> values);
/*
Hello! The reason we have so many constructors
is that the spec for the sample input text was
quite ambiguous! We now realise that the first
value, the int, is supposed to let the istream
operator know how many sample values to expect

We have made our istream operator work without 
that information and stored the int - 'number'
assuming it was a "sample number" or something

This means that sample output streams from our
sample class will break other peoples' classes

            MUAHAHAHAHAHAHAHA!!!!
*/
	int num() const;
	void set_num(const int &n);

	const vector<double> &get_data() const ;
	void set_data(const vector<double> &v);

	double maximum();
	double minimum();
	double range();
	double midrange();
	double mean();
	double variance();
	double std_deviation();
	double median();
};

ostream& operator<<(ostream &s, const sample &smp);

istream& operator>>(istream &s, sample &smp);
