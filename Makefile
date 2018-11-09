all: NoiseReduction.o

NoiseReduction.o: NoiseReduction.cpp NoiseReduction.h
	g++ -I. --std=c++11 -c NoiseReduction.cpp -o NoiseReduction.o
clean:
	rm -f *.o

