#ifndef TERRAINEXPORT_H
#define TERRAINEXPORT_H

#include <string>
#include <memory>
#include "terrain.h"

using namespace std;

namespace FLAT
{
    namespace Export
    {
        /*! \brief Abstreact base class to provide an interface to export
        * terrains
        */
        class TerrainExport
        {
            public:
                /*! \brief Sets the filename to export the file to */
                virtual void set_filename(string) = 0;
                /*! \brief Gets the default extension for the file type the
                * class exports the data to */
                virtual string get_extension() = 0;
                /*! \brief Gets an description of the exporter */
                virtual string get_description() = 0;

                /*! \brief Exports a terrain to the file specified in set_filename
                */
                virtual void export_terrain(shared_ptr<Terrain>) = 0;
                virtual void export_terrain_partitioned(shared_ptr<Terrain>) = 0;
            protected:
            private:
        };
    }

}


#endif // TERRAINEXPORT_H
