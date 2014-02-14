# all: %.o

OBJ=constants.o doubleparameterconverter.o doubleparameter.o doubleparametertype.o error.o errordeployer.o exception.o intparameterconverter.o intparameter.o intparametertype.o parameterconverter.o parameter.o parameterizable.o parametertype.o terrain.o


libFLAT: $(OBJ)
	ar rcs libFLAT.a $(OBJ)

%.o: ./src/%.cpp
	gcc -p -Wall -std=c++0x -I./include  -g -c $<

clean:
	rm *.o
