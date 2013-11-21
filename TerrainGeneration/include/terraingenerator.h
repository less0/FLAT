#include "terrain.h"

#include <memory>

#ifndef TERRAINGENERATOR_H
#define TERRAINGENERATOR_H


using namespace std;

/*! \brief Abstract base class for classes implementing an terrain generation algorithm
*
* This class implements the idea of the strategy pattern.
*/
namespace FLAT
{
    namespace TerrainGeneration
    {
        class TerrainGenerator
        {
        public:
            virtual void setSize(long int width, long int height) = 0;
            virtual void setPartitioning(long int partitioning) = 0;

            virtual shared_ptr<Terrain> generateTerrain() = 0;
            virtual shared_ptr<Terrain> getTerrain() = 0;
        };

    }
}


#endif
