#include "terrainexportbitmap.h"

using namespace FLAT::Export;
using namespace FLAT;

TerrainExportBitmap::TerrainExportBitmap()
{
    //ctor
    m_filename = string("out");
}

string TerrainExportBitmap::get_extension()
{
    return "bmp";
}

string TerrainExportBitmap::get_description()
{
    return "Simple bitmap exporter";
}

void TerrainExportBitmap::set_filename(string fname)
{
    int index_dot = fname.find_last_of(".");

    string ext = fname.substr(index_dot+1);

    if(ext.compare(this->get_extension()))
    {
        m_filename = fname.substr(0,index_dot);
    }
    else
    {
        m_filename = fname;
    }
}

void TerrainExportBitmap::export_terrain_partitioned(shared_ptr<Terrain> terrain)
{
    string fname = m_filename;

    for(int i=0; i<terrain->getPartitioning(); i++)
    {
        for(int j=0; j<terrain->getPartitioning(); j++)
        {
            std::stringstream out;

            out << fname << "_" << i << "_" << j;

            this->set_filename(out.str());
            this->export_terrain(terrain->getPartition(i,j));
        }
    }
}

void TerrainExportBitmap::export_terrain(shared_ptr<Terrain> terrain)
{
    string s_filename = string(m_filename + "." + get_extension());

    int fill = ((terrain->getWidth()*3)%4 == 0 ? 0 : 4-(terrain->getWidth()*3)%4);

    //MS Bitmaps are padded with zeros if the width is not a whole multiple of 4
    long int bmp_width = terrain->getWidth() * 3 + fill;
    long int bmp_height = terrain->getHeight();

    double terrain_max_height = terrain->getMaxHeight();
    double terrain_min_height = terrain->getMinHeight();

    //determine the bmp_size of the bitmap in bytes
    long int bmp_size = bmp_width * bmp_height + 54;

    __uint8* data = new __uint8[bmp_size];

    //Write bitmap header to array
    *((__int16*)(&data[0]))     = 19778;
    *((__int32*)(&data[2]))     = bmp_size;
    *((__int32*)(&data[6]))     = 0;
    *((__int32*)(&data[10]))    = 54;

    //Write bitmap properties to array
    *((__int32*)(&data[14]))    = 40;                                   //biSize
    *((__int32*)(&data[18]))    = (unsigned int)terrain->getWidth();    //biWidth
    *((__int32*)(&data[22]))    = -terrain->getHeight();                //biHeight
    *((__int16*)(&data[26]))    = 1;                                    //biPlanes
    *((__int16*)(&data[28]))    = 24;                                   //biBitCount
    *((__int32*)(&data[30]))    = 0;                                    //biCompression
    *((__int32*)(&data[34]))    = bmp_height * bmp_width;               //biSizeImage
    *((__int32*)(&data[38]))    = 0;                                    //biXPelsPerMeter
    *((__int32*)(&data[42]))    = 0;                                    //biYPelsPerMeter
    *((__int32*)(&data[46]))    = 0;                                    //biClrUsed
    *((__int32*)(&data[50]))    = 0;                                    //biClrImportant

    int data_index = 54;

    //Write bitmap data to file
    for(int j=0; j<terrain->getHeight(); j++)
    {
        for(int i=0; i<terrain->getWidth(); i++)
        {
            __uint8 d_height = 255.0*((terrain->getAt(i,j)-terrain_min_height) / (terrain_max_height-terrain_min_height));

            data[data_index++] = d_height;  //R-channel
            data[data_index++] = d_height;  //G-channel
            data[data_index++] = d_height;  //B-channel


        }

        for(int f = 0; f < fill; f++)
        {
            data[data_index++] = 0;
        }
    }

    cout << s_filename.c_str() << endl;

    ofstream file_stream(s_filename.c_str(), ios::out | ios::binary);
    file_stream.write((char*)data, bmp_size);
    file_stream.close();

//    FILE* h_file = fopen(s_filename.c_str(), "w+");
//
//    if(errno > 0)
//    {
//        perror("");
//        delete[] data;
//        return;
//    }
//
//
//    int elements_written = fwrite(data, 1, bmp_size, h_file);
//
//    if(elements_written != bmp_size);
        //cout << ferror(h_file) << endl;

    //fclose(h_file);

    delete[] data;
}
