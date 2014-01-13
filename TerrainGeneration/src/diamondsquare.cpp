#include "diamondsquare.h"
#include "constants.h"
#include "error.h"

#include <chrono>

using namespace FLAT;
using namespace FLAT::TerrainGeneration;

DiamondSquare::DiamondSquare(void)
{
	m_lastError = 0;

	m_parameters[1] = "Dimension";
	m_parameters[2] = "Base constant";

	m_width = 0;
	m_height = 0;
	m_partitioning = 1;
}

shared_ptr<Terrain> DiamondSquare::generateTerrain()
{
	//initialize random number generator
	int seed = int(std::chrono::high_resolution_clock::now().time_since_epoch().count());
	std::mt19937 generator(seed);

	//check for correct parameters
	if(m_width <= 0 || m_height <= 0)
	{
		m_lastError = new Error(FLAT_ERROR_NEGATIVE_MAP_SIZE, "Map size must not be negative.");
	}

	if((m_width % m_partitioning) != 0 || (m_height % m_partitioning) != 0)
	{
		//Width or height is not a multiple of partitioning
		m_lastError = new Error(FLAT_ERROR_INCORRECT_PARTITIONING,
                          "Width and height must be a multiple of partitioning");
		return 0;
	}

	if(m_width != m_height)
	{
		m_lastError = new Error(FLAT_ERROR_WIDTH_AND_HEIGHT_UNEQUAL,
                          "Diamond-squares does only support square landscapes at the moment");
		return shared_ptr<Terrain>((Terrain*)0);
	}

	//test for width=2^n and height=2^n for single partition
	if(!testPow2(m_width / m_partitioning - 1) || !testPow2(m_height / m_partitioning - 1))
	{
		m_lastError = new Error(FLAT_ERROR_SIZE_INVALID,
                          "Diamond-squares algorithm requires the width and height of the single partitions to be 2^n+1.");
		return shared_ptr<Terrain>((Terrain*)0);
	}

	shared_ptr<Terrain> terrain(new Terrain(m_width, m_height, m_partitioning));
	terrain->setAt(0,0,1.0);

	//setup partitioning variables
	long int part_width = m_width / m_partitioning;
    long int part_height = m_height / m_partitioning;

	//generate Terrain, using the Diamond square algorithm

	int depth = 1;

	//set random height for corner points and center points of partitions
	std::normal_distribution<double> distribution(0, m_k*std::pow(2.0, -double(depth)*m_H));
	std::normal_distribution<double> distribution2(0, m_k*std::pow(2.0, -double(depth+1)*m_H));


    for(long int i=0; i<m_partitioning; i++)
    {
        for(long int j=0; j<m_partitioning; j++)
        {
            long int offset_x = part_width * i;
            long int offset_y = part_height * j;

            long int center_x = offset_x + (part_width-1)/2;
            long int center_y = offset_y + (part_height-1)/2;

            long int left_upper_x = offset_x;
            long int left_upper_y = offset_y;

            long int left_lower_x = offset_x;
            long int left_lower_y = offset_y + part_height - 1;

            long int right_upper_x = offset_x + part_width - 1;
            long int right_upper_y = offset_y;

            long int right_lower_x = offset_x + part_width - 1;
            long int right_lower_y = offset_y + part_height - 1;

            terrain->setAt(left_upper_x,  left_upper_y, distribution(generator));
            terrain->setAt(right_upper_x, right_upper_y, distribution(generator));
            terrain->setAt(left_lower_x,  left_lower_y, distribution(generator));
            terrain->setAt(right_lower_x, right_lower_y, distribution(generator));

            //set middle point
            terrain->setAt(center_x,
                center_y,
                (terrain->getAt(left_upper_x,left_upper_y)
                    + terrain->getAt(left_lower_x,left_lower_y)
                    + terrain->getAt(right_upper_x, right_upper_y)
                    + terrain->getAt(right_lower_x,right_lower_y))/4.0
                    + distribution2(generator));
        }
    }

	//generate the edges using midpoint displacement for each partition
	for(depth = 2; pow(2,depth-1)<part_width; depth++)
	{
	    distribution = normal_distribution<double>(0, m_k*std::pow(2.0, -double(depth)*m_H));

	    for(long int i=0; i<m_partitioning; i++)
	    {
            for(long int j=0; j<m_partitioning; j++)
            {
                long int offset_x = part_width * i;
                long int offset_y = part_height * j;

                int d = (part_width-1)/powl(2,depth-2);

                for(int index = (part_width-1)/powl(2,depth-1); index<part_width; index += d)
                {
                    int upper_x = offset_x+index;
                    int upper_y = offset_y;

                    double sum_upper = terrain->getAt(upper_x - d/2, upper_y) + terrain->getAt(upper_x+d/2, upper_y);

                    int lower_x = offset_x+index;
                    int lower_y = offset_y+part_height - 1;

                    double sum_lower = terrain->getAt(lower_x - d/2, lower_y) + terrain->getAt(lower_x+d/2, lower_y);

                    int left_x = offset_x;
                    int left_y = offset_y+index;

                    double sum_left = terrain->getAt(left_x, left_y-d/2) + terrain->getAt(left_x, left_y+d/2);

                    int right_x = offset_x + part_width - 1;
                    int right_y = offset_y + index;

                    double sum_right = terrain->getAt(right_x, right_y-d/2)
                        + terrain->getAt(right_x, right_y+d/2);

                    terrain->setAt(upper_x, upper_y, distribution(generator) + sum_upper / 2.0);
                    terrain->setAt(lower_x, lower_y, distribution(generator) + sum_lower / 2.0);
                    //terrain.setAt(offset_x, offset_y + index, distribution(generator) * (terrain.getAt(offset_x, offset_y + (index - d/2)) + terrain.getAt(offset_x, offset_y + (index + d/2)))/2.0);
                    terrain->setAt(left_x, left_y, distribution(generator) + sum_left / 2.0);
                    terrain->setAt(right_x, right_y, distribution(generator) + sum_right / 2.0);

                }
            }
        }
	}

	//generate the rest of the heightmap using the diamond-square algorithm
    for(depth = 3; powl(2,depth-1)<part_width; depth++)
    {
        std::normal_distribution<> distribution(0, m_k*std::pow(2.0, -double(depth)*m_H));

        for(long int i=0; i<m_partitioning; i++)
	    {
            for(long int j=0; j<m_partitioning; j++)
            {
                long int offset_x = part_width * i;
                long int offset_y = part_height * j;

                long int start = (part_width-1)/powl(2,depth-1);
                long int d = (part_width-1)/powl(2,depth-2);

                for(int index_x = start; index_x<part_width; index_x += d)
                {
                    for(int index_y = start; index_y<part_height; index_y += d)
                    {
                        double corner_sum = (terrain->getAt(offset_x + index_x - d/2, offset_y + index_y - d/2)+
                                             terrain->getAt(offset_x + index_x - d/2, offset_y + index_y + d/2)+
                                             terrain->getAt(offset_x + index_x + d/2, offset_y + index_y - d/2)+
                                             terrain->getAt(offset_x + index_x + d/2, offset_y + index_y + d/2));

                        terrain->setAt(index_x+offset_x, index_y+offset_y, corner_sum/4.0+distribution(generator));
                    }

                }

                for(int index_x = d/2; index_x<(part_width-1); index_x += d/2)
                {
                    for(int index_y = ((index_x/(d/2))%2 == 0)?d/2:d; index_y<(part_height-1); index_y += d)
                    {
                        double diamond_sum = (terrain->getAt(offset_x + index_x,         offset_y + index_y - d/2) +
                                              terrain->getAt(offset_x + index_x + d/2,   offset_y + index_y) +
                                              terrain->getAt(offset_x + index_x,         offset_y + index_y + d/2) +
                                              terrain->getAt(offset_x + index_x - d/2,   offset_y + index_y));

                        terrain->setAt(index_x+offset_x, index_y+offset_y, diamond_sum/4.0 + distribution(generator));
                    }
                }
            }
        }
    }



	m_terrain = terrain;
	return m_terrain;
}

Error* DiamondSquare::getLastError()
{
	return m_lastError;
}

int DiamondSquare::getNumParameters()
{
	return 2;
}

std::string DiamondSquare::getParameterName(int numParam)
{
	switch(numParam)
	{
	case 1:
		return "Dimension";
	case 2:
		return "Base constant";
	}

	return "";
}

void DiamondSquare::setParameter(const unique_ptr<Parameter>& data)
{
	if(data->getName().compare(std::string("Dimension")))
	{
		m_H = *((double*)data->getValue());
	}
	else if(data->getName().compare(std::string("Base constant")))
	{
		m_k = *((double*)data->getValue());
	}
}


shared_ptr<ParameterType> DiamondSquare::getParameterType(int parameterNumber)
{
    return shared_ptr<ParameterType>(new DoubleParameterType());
}


shared_ptr<ParameterType> DiamondSquare::getParameterType(string parameterName)
{
    return shared_ptr<ParameterType>(new DoubleParameterType());
}

shared_ptr<Parameter> DiamondSquare::getParameter(string parameterName)
{
    if(parameterName.compare("Dimension"))
        return shared_ptr<Parameter>(new DoubleParameter(parameterName, m_H));
    if(parameterName.compare("Base constant"))
        return shared_ptr<Parameter>(new DoubleParameter(parameterName, m_k));

    return shared_ptr<Parameter>((Parameter*)0);
}

shared_ptr<Parameter> DiamondSquare::getParameter(int parameterNumber)
{
    ///\todo Add check if index exists
    return getParameter(m_parameters[parameterNumber]);
}

void DiamondSquare::setSize(long int width, long int height)
{
    m_width = width;
    m_height = height;
}

void DiamondSquare::setPartitioning(long int partitioning)
{
    m_partitioning = partitioning;
}

shared_ptr<Terrain> DiamondSquare::getTerrain()
{
    return m_terrain;
}


