#pragma once
#include<iostream>
#include<utility>
#include<vector>
using namespace std;

template<typename T>
class samplet {
private:
	int number;
	vector<T> values; // vector of Ts
public:
	samplet();
	samplet(int);
	samplet(vector<T> values);
	samplet(int number, vector<T> values);
	int num() const;
	void set_num(const int &n);

	const vector<T> &get_data() const ;
	void set_data(const vector<T> &v);

	T maximum();
	T minimum();
	T range();
	T midrange();
	T mean();
	T variance();
	T std_deviation();
	T median();
};

template<typename T>
ostream& operator<<(ostream &s, const samplet <T> &smp);

template<typename T>
istream& operator>>(istream &s, samplet <T> &smp);

#include "samplet.cc"
