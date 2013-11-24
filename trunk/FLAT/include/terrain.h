#include <string>
#include <vector>
#include <list>
#include <memory>

#include "constants.h"

#ifndef TERRAIN_H
#define TERRAIN_H

using namespace std;

namespace FLAT
{
    class Terrain
    {
    private:
        vector<double>  m_heightmap;
        long int	    m_width;
        long int	    m_height;
        long int	    m_partitioning;
        double		    m_scaling;

		/** \brief Initializes the heightmap
		*
		* Before the the Terrain object can be used, the stl Vector containing
		* the data must be initialized, this action is performed in this
		* function
		*/
        void initTerrain();

    public:

        /*! \brief Creates a new Terrain heightmap
        *
        * \param width The size of the map in the x-dimension
        * \param height The size of the map in the y-dimension
        * \param partitioning Gets the number of subterrains the terrain can be
        * partitioned to
        * \param scaling Gets a factor the values of the map are scaled with
        */
        Terrain(long int width = 0,
                long int height = 0,
                long int partitioning = 1,
                double scaling = 1.0);
        Terrain(const Terrain& orig);
        ~Terrain();


        double getAt(long int x, long int y);
        void setAt(long int x, long int y, double height);
        /** \brief Resizes the Terrain
        *
        * Resizes the terrain to a given width and height, with the possibility to change the
        * partitioning. At the moment the Terrain is interpolated linearly
        */
        shared_ptr<Terrain> resize(long int width, long int height, long int partitioning = 1);
        shared_ptr<Terrain> getPartition(long int x, long int y);

        /*! \brief Gets the size of the terrain in the x-dimension
        */
        long int getWidth();
        /*! \brief Gets the size of the terrain in the y-dimension
        *
        * \todo This is to be confused with the height of the heightmap in
        * of height values and not in terms of dimension
        */
        long int getHeight();
        long int getPartitioning();

        /*! \brief Gets the maximum value of the map
        */
        double getMaxHeight();
        /*! \brief Gets the minimum value of the map
        */
        double getMinHeight();

        list<shared_ptr<Terrain>>	getPartitioned();
    };

}

#endif
