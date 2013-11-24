#ifndef TERRAINEXPORTBITMAP_H
#define TERRAINEXPORTBITMAP_H

#include <terrainexport.h>
#include <string>
#include <sstream>
#include <cstdio>
#include <iostream>
#include <fstream>

typedef uint8_t __uint8;
typedef int16_t __int16;
typedef int32_t __int32;

using namespace std;
namespace FLAT
{
    namespace Export
    {
        class TerrainExportBitmap : public TerrainExport
        {
            public:
                TerrainExportBitmap();

                void set_filename(string);
                string get_extension();
                string get_description();

                void export_terrain(Terrain);
                void export_terrain_partitioned(Terrain);
            private:
                string m_filename;
        };
    }
}


#endif // TERRAINEXPORTBITMAP_H
