#include "squaresquare.h"

#include <random>
#include <chrono>
#include <memory>
#include <iostream>

using namespace FLAT;
using namespace FLAT::TerrainGeneration;
using namespace std;

shared_ptr<Terrain> SquareSquare::generateTerrain(void)
{
    //check parameters for validity

    //initialize random number generator
    int seed = int(std::chrono::high_resolution_clock::now().time_since_epoch().count());
	std::mt19937 generator(seed);

    int level = 0;

    int currentSize = 3;
    shared_ptr<FLAT::Terrain> terrain(new FLAT::Terrain(currentSize, currentSize));
    shared_ptr<FLAT::Terrain> tempTerrain;

    currentSize = (currentSize - 1) * 2;
    level++;

    while(currentSize < this->m_width)
    {
        double sd = m_k*std::pow(2.0, -double(level+1)*m_H);

        std::normal_distribution<double> distribution(0.0, sd);

        tempTerrain = terrain;
        terrain = shared_ptr<FLAT::Terrain>(new FLAT::Terrain(currentSize, currentSize));

        for(int i=0; i<(currentSize / 2 + 1) - 1; i++)
        {
            for(int j=0; j<(currentSize / 2 + 1) - 1; j++)
            {
                int index_x_lower   = 2*i;
                int index_x_higher  = 2*i+1;
                int index_y_lower   = 2*j;
                int index_y_higher  = 2*j+1;

                double sum_00 = (9 * tempTerrain->getAt(i,j) +
                    3 * tempTerrain->getAt(i+1,j) +
                    3 * tempTerrain->getAt(i,j+1) +
                    tempTerrain->getAt(i+1,j+1)) / 16.0 +
                    distribution(generator);
                double sum_10 = (3 * tempTerrain->getAt(i,j) +
                    9 * tempTerrain->getAt(i+1,j) +
                    tempTerrain->getAt(i,j+1) +
                    3 * tempTerrain->getAt(i+1,j+1)) / 16.0 +
                    distribution(generator);
                double sum_01 = (3 * tempTerrain->getAt(i,j) +
                    tempTerrain->getAt(i+1,j) +
                    9 * tempTerrain->getAt(i,j+1) +
                    3 * tempTerrain->getAt(i+1,j+1)) / 16.0 +
                    distribution(generator);
                double sum_11 = (tempTerrain->getAt(i,j) +
                    3 * tempTerrain->getAt(i+1,j) +
                    3 * tempTerrain->getAt(i,j+1) +
                    9 * tempTerrain->getAt(i+1,j+1)) / 16.0 +
                    distribution(generator);

                terrain->setAt(index_x_lower, index_y_lower, sum_00);
                terrain->setAt(index_x_higher, index_y_lower, sum_10);
                terrain->setAt(index_x_lower, index_y_higher, sum_01);
                terrain->setAt(index_x_higher, index_y_higher, sum_11);
            }

        }


        currentSize = (currentSize - 1)*2;
        level++;
    }

    return terrain;

}

void SquareSquare::setSize(long int width, long int height)
{
    m_width = width;
    m_height = height;
}

void SquareSquare::setPartitioning(long int partitioning)
{
    m_partitioning = partitioning;
}

shared_ptr<Terrain> SquareSquare::getTerrain(void)
{
	return m_terrain;
}


TerrainGeneration::SquareSquare::SquareSquare()
{

}

int SquareSquare::getNumParameters()
{
    return 2;
}

const void* SquareSquare::getParameter(int parameterNumber)
{
    switch(parameterNumber)
    {
    case 1:
        return (const void*)&m_H;
    case 2:
        return (const void*)&m_k;
    default:
        return 0;
    }
}

const void* SquareSquare::getParameter(std::string parameterName)
{
    if(parameterName.compare(getParameterName(1)))
    {
        return getParameter(1);
    }
    else if(parameterName.compare(getParameterName(2)))
    {
        return getParameter(2);
    }

    return 0;
}

void SquareSquare::setParameter(int paramterNumber, const void* data)
{
    switch(paramterNumber)
    {
    case 1:
        m_H = *((double*)data);
        break;
    case 2:
        m_k = *((double*)data);
        break;
    }
}

void SquareSquare::setParameter(string parameterName, const void* data)
{
    if(parameterName.compare(getParameterName(1)))
    {
        setParameter(1, data);
    }
    else if(parameterName.compare(getParameterName(2)))
    {
        setParameter(2, data);
    }
}

std::string SquareSquare::getParameterName(int parameterNumber)
{
    switch(parameterNumber)
    {
    case 1:
        return "Dimension";
    case 2:
        return "Base constant";
    default:
        return "";
    }
}

std::string SquareSquare::getParameterType(int parameterNumber)
{
    switch(parameterNumber)
    {
    case 1:
        return "double";
    case 2:
        return "double";
    default:
        return "";
    }
}

std::string SquareSquare::getParameterType(std::string parameterName)
{
    for(int i=1; i<=getNumParameters(); i++)
    {
        if(parameterName.compare(getParameterName(i)))
        {
            return getParameterType(i);
        }
    }

    return "";
}

Error* getLastError()
{
    return 0;
}
