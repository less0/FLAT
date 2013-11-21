#include <iostream>

#include "terrain.h"
#include "diamondsquare.h"
#include "terrainexportbitmap.h"
#include "error.h"

using namespace std;
using namespace FLAT;
using namespace FLAT::TerrainGeneration;
using namespace FLAT::Export;

int main()
{
    TerrainExportBitmap exporter = TerrainExportBitmap();
    //exporter.set_filename("out");

    DiamondSquare gen = DiamondSquare();
    Terrain terrain;

    int parts = 1;
    int size = 1025;

    double param1 = 10;
    double param2 = .4;

    gen.setParameter(1, (void*)&param1);
    gen.setParameter(2, (void*)&param2);

    gen.setSize(size*parts, size*parts);
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
