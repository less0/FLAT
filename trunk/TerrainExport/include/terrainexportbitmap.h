#ifndef TERRAINEXPORTBITMAP_H
#define TERRAINEXPORTBITMAP_H

#include <terrainexport.h>
#include <string>
#include <sstream>
#include <cstdio>
#include <iostream>
#include <fstream>



#ifdef LINUX
typedef __uint8_t __uint8;
typedef __uint16_t __int16;
typedef __uint32_t __int32;
#else
//typedef __UINT8_TYPE__ __uint8;
typedef unsigned __int8 __uint8;
#endif

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

                void export_terrain(shared_ptr<Terrain>);
                void export_terrain_partitioned(shared_ptr<Terrain>);
            private:
                string m_filename;
        };
    }
}


#endif // TERRAINEXPORTBITMAP_H
