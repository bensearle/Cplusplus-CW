#include <iostream>
#include "sample.cc"

using namespace std;

int main(void) {
    sample s;
    while (cin  >> s)
	cout << "" << endl;
        cout << s               << endl
             << "min " << s.minimum() << endl << "max " << s.maximum() << endl
             << "range " << s.range() << endl << "midrange " << s.midrange() << endl
             << "median " << s.median() << endl << "mean " << s.mean() << endl
             << "variance " << s.variance() << endl << "std_dev " << s.std_deviation() << endl;

    if (cin.bad()) cerr << "\nBad input\n\n";
    return(0);
}
