all: FLAT

FLAT: force_look
	cd ./FLAT; make
	

force_look:
	true
