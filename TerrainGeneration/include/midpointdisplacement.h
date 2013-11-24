#include "terrain.h"

#ifndef MIDPOINTDISPLACEMENT_H
#define MIDPOINTDISPLACEMENT_H
class MidpointDisplacement
{

public:
	MidpointDisplacement(void);
	~MidpointDisplacement(void);
	Terrain* generateTerrain(int size, double init[4], double factor, long seed);
};

#endif
