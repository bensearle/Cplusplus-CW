CXX= g++
CXXFLAGS= -Wall -pedantic -ansi -g -std=c++0x

all: fraction_test sample_test samplet_test

fraction.o: fraction.cc fraction.h
	$(CXX) $(CXXFLAGS) -c fraction.cc

fraction_test.o: fraction_test.cc fraction.h
	$(CXX) $(CXXFLAGS) -c fraction_test.cc 

fraction_test: fraction.o fraction_test.o
	$(CXX) $(CXXFLAGS) -lpthread $^ -o $@
	

sample.o: sample.cc sample.h
	$(CXX) $(CXXFLAGS) -c sample.cc

sample_test.o: sample_test.cc sample.h
	$(CXX) $(CXXFLAGS) -c sample_test.cc

sample_test: sample.o sample_test.o
	$(CXX) $(CXXFLAGS) -lpthread $^ -o $@


samplet_test.o: samplet_test.cc samplet.h
	$(CXX) $(CXXFLAGS) -c samplet_test.cc

samplet_test: samplet_test.o
	$(CXX) $(CXXFLAGS) -lpthread $^ -o $@


clean:
	-rm -f *.o *_test
