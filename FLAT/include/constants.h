#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace FLAT
{
    class constants
    {

    public:
        constants(void);
        ~constants(void);

        static double TEST_ZERO;
    };

    enum ErrorCode
    {
        FLAT_ERROR_NEGATIVE_MAP_SIZE = 100,
        FLAT_ERROR_INCORRECT_PARTITIONING = 101,
        FLAT_ERROR_WIDTH_AND_HEIGHT_UNEQUAL = 102,
        FLAT_ERROR_SIZE_NOT_POWER_2 = 103,
        FLAT_ERROR_SIZE_INVALID = 104
    };
}


#endif
