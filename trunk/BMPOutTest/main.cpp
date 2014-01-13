#include <iostream>
#include <vector>

#include "terrain.h"
#include "diamondsquare.h"
#include "squaresquare.h"
#include "terrainexportbitmap.h"

using namespace std;
using namespace FLAT;
using namespace FLAT::TerrainGeneration;
using namespace FLAT::Export;

int main()
{
    TerrainExportBitmap exporter = TerrainExportBitmap();
    //exporter.set_filename("out");

//    DiamondSquare gen = DiamondSquare();
    SquareSquare gen = SquareSquare();
    shared_ptr<Terrain> terrain;

    int parts = 1;
    int size = 2100;

    double param1 = .1;
    double param2 = 2;

    gen.setParameter(shared_ptr<DoubleParameter>(new DoubleParameter("Base constant", param2)));
    gen.setParameter(shared_ptr<DoubleParameter>(new DoubleParameter("Dimension", param1)));

    gen.setSize(size*parts + 1, size*parts + 1);
    gen.setPartitioning(parts);

    try
    {
        cout << "Generating Terrain" << endl;
        terrain = gen.generateTerrain();
        cout << "Saving Terrain" << endl;
        exporter.export_terrain(terrain);
    }
    catch(int e)
    {
        cout << "Error" << endl;
    }




    return 0;
}
