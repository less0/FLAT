#include "terrain.h"
#include "constants.h"
#include <cmath>

using namespace FLAT;

Terrain::Terrain(long int width, long int height, long int partitioning, double scaling)
{
    //check width and height to be multiples of partitioning
    if((width % partitioning) != 0 || (height % partitioning) != 0)
    {
        throw FLAT_ERROR_INCORRECT_PARTITIONING;
    }

    //assign member variables
    this->m_width = width;
    this->m_height = height;

    this->m_partitioning = partitioning;
    this->m_scaling = 1.0;

    this->initTerrain();
}

Terrain::Terrain(const Terrain& copy)
{
    this->m_width = copy.m_width;
    this->m_height = copy.m_height;
    this->m_partitioning = copy.m_partitioning;
    this->m_scaling = copy.m_scaling;

    //this->initTerrain();

    vector<double> heightmap = copy.m_heightmap;

    initTerrain();

    for(unsigned int i=0;i < heightmap.size(); i++)
    {
        this->m_heightmap[i] = heightmap.at(i);
    }
}

Terrain::~Terrain()
{
    m_heightmap.resize(0);
}

shared_ptr<Terrain> Terrain::resize(long width, long height, long partitioning)
{
    shared_ptr<Terrain> result =
        shared_ptr<Terrain>(new Terrain(width, height, partitioning, this->m_scaling));

    for(int i=0; i<width; i++)
    {
        for(int j=0; j<height; j++)
        {
            //in each step the position of a point of the new grid in the old grid is calculated and
            //based on the distances to the points in the old grid, the weighted average of the
            //height field on the new position is calculated.

            double d_x = ((double)i)*(((double)(width-1))/((double)(this->m_width-1)));
            double d_y = ((double)j)*(((double)(width-1))/((double)(this->m_height-1)));

            //Calculate the indices for the surrounding points
            double index_x_low	= floor(d_x);
            double index_x_high = ceil(d_x);

            double index_y_low	= floor(d_y);
            double index_y_high = ceil(d_y);

            //Calculate the weights for the surrounding points
            double weight_x_low	= 1 - (d_x - index_x_low);
            double weight_x_high= 1 - (index_x_high - d_x);

            double weight_y_low = 1 - (d_y - index_y_low);
            double weight_y_high= 1 - (index_y_high - d_y);

            //Calculate the weighted average of the height of the surrounding points
            double height = (this->getAt(index_x_low,index_y_low)*weight_x_low*weight_y_low +
                             this->getAt(index_x_high, index_y_low)*weight_x_high*weight_y_low +
                             this->getAt(index_x_low, index_y_high)*weight_x_low*weight_y_high +
                             this->getAt(index_x_high, index_y_high)*weight_x_high*weight_y_high) /
                            (weight_x_low*weight_y_low + weight_x_high*weight_y_low + weight_x_low*weight_y_high + weight_x_high*weight_y_high);

            //set
            result->setAt(i,j, height);
        }
    }

    return result;
}

void Terrain::initTerrain()
{
    m_heightmap.resize(m_width * m_height);
}

double Terrain::getAt(long int x, long int y)
{
    return m_heightmap[x+m_width*y];
}

void Terrain::setAt(long int x, long int y, double height)
{
    m_heightmap[x+m_width*y] = height;
}

shared_ptr<Terrain> Terrain::getPartition(long int x, long int y)
{
    int width = m_width / m_partitioning;
    int height = m_height / m_partitioning;

    shared_ptr<Terrain> result = shared_ptr<Terrain>(new Terrain(width, height, 1, m_scaling));

    int offset_x = x * width;
    int offset_y = y * height;

    for(int i=0; i<width; i++)
    {
        for(int j=0; j<height; j++)
        {
            int orig_x = offset_x + i;
            int orig_y = offset_y + j;

            result->setAt(i,j, getAt(orig_x, orig_y));
        }
    }

    return result;
}

list<shared_ptr<Terrain>> Terrain::getPartitioned()
{
    list<shared_ptr<Terrain>> result = list<shared_ptr<Terrain>>();

    for(int j=0; j<m_partitioning; j++)
    {
        for(int i=0; i<m_partitioning; i++)
        {
            result.push_back(getPartition(i,j));
        }
    }

    return result;
}

long int Terrain::getWidth()
{
    return m_width;
}

long int Terrain::getHeight()
{
    return m_height;
}

long int Terrain::getPartitioning()
{
    return m_partitioning;
}

double Terrain::getMaxHeight()
{

    double max = 0.0;

    for(int i=0; i<this->getWidth(); i++)
    {
        for(int j=0; j<this->getHeight(); j++)
        {
            if(this->getAt(i,j) > max)
            {
                max = this->getAt(i,j);
            }
        }
    }

    return max;
}

double Terrain::getMinHeight()
{
    double min = getMaxHeight();

    for(int i=0; i<this->getWidth(); i++)
    {
        for(int j=0; j<this->getHeight(); j++)
        {
            if(this->getAt(i,j) < min)
            {
                min = this->getAt(i,j);
            }
        }
    }

    return min;
}
