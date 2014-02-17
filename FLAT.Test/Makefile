# all: %.o

OBJ=DoubleParameterTest.o IntParameterTest.o main.o
CPP=DoubleParameterTest.cpp IntParameterTest.cpp main.cpp


FLAT.Test: 
	g++ -L../FLAT/ -L../UnitTest++/ -I../FLAT/include -I../UnitTest++/src -o FLAT.Test $(CPP) -std=c++0x  -lUnitTest++ -lFLAT	 

%.o: %.cpp
	gcc -p -Wall -std=c++0x -I../FLAT/include -I../UnitTest++/src  -g -c $<

clean:
	rm FLAT.Test
