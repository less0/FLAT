# all: %.o

OBJ=DoubleParameterTest.o IntParameterTest.o main.o


FLAT.Test: $(OBJ)
	 

%.o: %.cpp
	gcc -p -Wall -std=c++0x -I../FLAT/include -I../UnitTest++/src  -g -c $<

clean:
	rm *.o
