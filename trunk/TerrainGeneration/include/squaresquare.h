#include "terraingenerator.h"
#include "errordeployer.h"
#include "parameterizable.h"
#include "doubleparameter.h"
#include "doubleparametertype.h"

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
            void setParameter(shared_ptr<Parameter> data);

            int getNumParameters();
            string getParameterName(int parameterNumber);
            shared_ptr<ParameterType> getParameterType(int parameterNumber);
            shared_ptr<ParameterType> getParameterType(string parameterName);
            shared_ptr<Parameter> getParameter(int parameterNumber);
            shared_ptr<Parameter> getParameter(string parameterName);

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
