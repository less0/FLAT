#ifndef ERODER_H
#define ERODER_H

#include <memory>
#include "parameterizable.h"
#include "terrain.h"

namespace FLAT
{
    namespace Erosion
    {
        /*! \brief Abstract base class for erosion algorithms
         *
         *
         */
        class Eroder :
            public Parameterizable
        {
            public:
                Eroder();

                virtual void setInitialHeightMap(shared_ptr<FLAT::Terrain>) = 0;

                virtual shared_ptr<FLAT::Terrain> getHeigthMap() = 0;
                virtual shared_ptr<FLAT::Terrain> getWaterMap() = 0;
                virtual shared_ptr<FLAT::Terrain> getSoil() = 0;

                virtual void step() = 0;

                virtual std::string getName() = 0;

            protected:
            private:
        };
    }
}

#endif // ERODER_H
