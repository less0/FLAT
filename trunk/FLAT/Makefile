# all: %.o

OBJ=terrain.o constants.o error.o parameter.o errordeployer.o parameterconverter.o doubleparameterconverter.o parameterizable.o parametertype.o doubleparametertype.o intparametertype.o terrain.o


prog: $(OBJ)

%.o: ./src/%.cpp
	gcc -p -Wall -std=c++0x -I./include  -g -c $<
