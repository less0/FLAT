all: FLAT.Test

FLAT: force_look
	cd ./FLAT; make

UnitTest: force_look
	cd ./UnitTest++; make

FLAT.Test: FLAT UnitTest force_look
	cd ./FLAT.Test; make clean; make
	./FLAT.Test/FLAT.Test

force_look:
	true
