#ifndef PARAMETERCONVERTER_H
#define PARAMETERCONVERTER_H

#include <string>
#include <memory>
#include "parameter.h"

using namespace std;

namespace FLAT
{
    /*! \brief Abstract base class to convert strings to Parameter objects to be
    * passed to Parametriizable objects.
    *
    * \sa Parametrizable
    * \sa ParameterType
    * \sa Parameter
    */
    class ParameterConverter
    {
        public:
            /*! \brief Converts a string to a parameter
            *
            * \sa  Parametrizable
            */
            virtual shared_ptr<Parameter> convertValue(string name, string stringRepresentation) = 0;
        protected:
        private:
    };
}

#endif // PARAMETERCONVERTER_H
