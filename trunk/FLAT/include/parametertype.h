#ifndef PARAMETERTYPE_H
#define PARAMETERTYPE_H

#include "parameterconverter.h"

namespace FLAT
{
    /*! \brief Abstract base class for parameter types
    *
    */
    class ParameterType
    {
        public:
            /*! \brief Gets an intance of the ParameterConverter class which
            * converts strings to Parameter objects, which then can be passed to
            * Parametrizable objects
            */
            virtual shared_ptr<ParameterConverter> getConverter() = 0;
        protected:
        private:
    };
}

#endif // PARAMETERTYPE_H
