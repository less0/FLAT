#include "terraingenerator.h"
#include "errordeployer.h"
#include "parameterizable.h"

#ifndef SQUARESQUARE_H
#define SQUARESQUARE_H
namespace FLAT
{
    namespace TerrainGeneration
    {
        /*! \brief Generates a Terrain based on the Square-Square-Algorithm
        *
        */
        class SquareSquare :
            public TerrainGenerator,
            public Parameterizable
        {
        public:
            SquareSquare();

            //error deployer functions
            Error* getLastError();

            void setSize(long int width, long int height);
            void setPartitioning(long int partitioning);
            void setParameter(int parameterNumber, const void* data);
            void setParameter(string parameterName, const void* data);

            int getNumParameters();
            string getParameterName(int parameterNumber);
            string getParameterType(int parameterNumber);
            string getParameterType(string parameterName);
            const void* getParameter(int parameterNumber);
            const void* getParameter(string parameterName);

            shared_ptr<Terrain> generateTerrain();
            shared_ptr<Terrain> getTerrain();

            inline int getIterations(int width)
            {
                int currentWidth = 3;
                int iterations = 0;

                while(currentWidth <= width)
                {
                    currentWidth = (currentWidth - 1) * 2;
                    iterations++;
                }

                return iterations;
            }

        private:
            int m_width,
                m_height;

            int m_partitioning;

            double m_k, m_H;

            Error* m_lastError;
            shared_ptr<Terrain> m_terrain;
        };
    }

}


#endif
