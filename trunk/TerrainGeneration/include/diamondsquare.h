#include "terraingenerator.h"
#include "terrain.h"
#include "errordeployer.h"
#include "parameterizable.h"
#include <random>
#include <cmath>
#include <map>
#include <stdlib.h>

#ifndef DIAMONDSQUARE_H
#define DIAMONDSQUARE_H


namespace FLAT
{
    namespace TerrainGeneration
    {
        /*! \brief Generates a fractal landscape using the diamond square algorithm, introduced by A. Fournier,D. Fussell und L. Carpenter: Computer rendering of stochastic models In: Communications of the ACM, Band 25, Nr. 6, 1982, S. 371–384.
        *
        */
        class DiamondSquare :
            public TerrainGenerator,
            public Parameterizable
        {
        private:
            long int    m_width;
            long int    m_height;
            long int    m_partitioning;

            shared_ptr<Terrain>     m_terrain;
            Error*      m_lastError;

            map<int,string> m_parameters;

            //midpoint displacement Parameters
            double m_k, m_H;

            inline bool testPow2(long int arg)
            {
                return (arg > 0 && (arg & (arg - 1))==0);
            }

        public:
            DiamondSquare(void);

            void setSize(long int width, long int height);
            void setPartitioning(long int partitioning);
            void setParameter(int parameterNumber, const void* data);
            void setParameter(std::string parameterName, const void* data);

            int getNumParameters();
            std::string getParameterName(int parameterNumber);
            std::string getParameterType(int parameterNumber);
            std::string getParameterType(std::string parameterName);
            const void* getParameter(int parameterNumber);
            const void* getParameter(std::string parameterName);

            shared_ptr<Terrain> generateTerrain();
            shared_ptr<Terrain> getTerrain();

            FLAT::Error* getLastError();
        };
    }

}
#endif

