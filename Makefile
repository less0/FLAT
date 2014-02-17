all: FLAT.Test

FLAT: force_look
	cd ./FLAT; make

UnitTest: force_look
	cd ./UnitTest++; make

FLAT.Test: FLAT UnitTest
	cd ./FLAT.Test; make
	./FLAT.Test/FLAT.Test

force_look:
	true
